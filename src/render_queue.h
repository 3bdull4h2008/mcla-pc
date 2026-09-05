#pragma once

#include <cstdint>
#include <variant>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace mcla::native {

struct DrawIndexedCommand {
    uint32_t vbAddr;
    uint32_t ibAddr;
    uint32_t indexCount;
    uint32_t startIndexLocation;
    uint32_t baseVertexLocation;
    uint32_t vbStride;
    uint32_t ibFormat;
    uint32_t primitiveTopology;
};

struct SetPipelineStateCommand {
    uint64_t psoHash;
};

struct SetVertexBuffersCommand {
    uint32_t vbAddr;
    uint32_t stride;
    uint32_t offset;
};

struct SetIndexBufferCommand {
    uint32_t ibAddr;
    uint32_t format;
    uint32_t size;
};

struct PresentCommand {
    uint32_t frameNumber;
    uint32_t obj;
    uint32_t swapInfo;
};

struct SetRenderStateCommand {
    uint32_t deviceAddr;
    uint32_t value;
};

struct InitD3D12Command {
    void* hwnd;
    uint32_t width;
    uint32_t height;
};

struct DrawCapturedCommand {
    uint32_t vbBase;
    uint32_t vbSize;
    uint32_t vbStride;
    uint32_t ibBase;
    uint32_t ibSize;
    uint32_t frameId;
    uint64_t psoHash;
};

struct ResizeCommand {
    uint32_t width;
    uint32_t height;
};

struct RenderCommand {
    enum Type : uint8_t {
        DRAW_INDEXED,
        SET_PIPELINE_STATE,
        SET_VERTEX_BUFFERS,
        SET_INDEX_BUFFER,
        PRESENT,
        SET_RENDER_STATE,
        NOOP,
        INIT_D3D12,
        DRAW_CAPTURED,
        RESIZE,
    };
    
    Type type;
    std::variant<
        DrawIndexedCommand,
        SetPipelineStateCommand,
        SetVertexBuffersCommand,
        SetIndexBufferCommand,
        PresentCommand,
        SetRenderStateCommand,
        InitD3D12Command,
        DrawCapturedCommand,
        ResizeCommand
    > data;
};

class CommandQueue {
public:
    explicit CommandQueue(size_t maxCapacity = 4096) 
        : maxCapacity_(maxCapacity), shutdown_(false) {}
    
    ~CommandQueue() {
        shutdown();
    }
    
    void push(RenderCommand cmd) {
        std::unique_lock lock(mutex_);
        notFull_.wait(lock, [this] { 
            return queue_.size() < maxCapacity_ || shutdown_; 
        });
        
        if (shutdown_) return;
        
        queue_.push(std::move(cmd));
        notEmpty_.notify_one();
    }
    
    bool pop(RenderCommand& cmd) {
        std::unique_lock lock(mutex_);
        notEmpty_.wait(lock, [this] { 
            return !queue_.empty() || shutdown_; 
        });
        
        if (shutdown_ && queue_.empty()) return false;
        
        cmd = std::move(queue_.front());
        queue_.pop();
        notFull_.notify_one();
        return true;
    }
    
    void shutdown() {
        std::lock_guard lock(mutex_);
        shutdown_ = true;
        notEmpty_.notify_all();
        notFull_.notify_all();
    }
    
    size_t size() const {
        std::lock_guard lock(mutex_);
        return queue_.size();
    }
    
    bool isEmpty() const {
        std::lock_guard lock(mutex_);
        return queue_.empty();
    }
    
private:
    mutable std::mutex mutex_;
    std::condition_variable notEmpty_;
    std::condition_variable notFull_;
    std::queue<RenderCommand> queue_;
    size_t maxCapacity_;
    std::atomic<bool> shutdown_;
};

extern CommandQueue g_commandQueue;

} // namespace mcla::native