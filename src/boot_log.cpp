// spdlog forwarding for the SEH-bearing boot TU (see boot_host.h). Keeps fmt
// codegen out of the function holding __try/__except (boot_host.cpp:2008), not the TU.

#include "logging.h"
#include "boot_host.h"

namespace mcla::boot {

void BootReportInfo(const char* line)
{
    MCLA_LOG_INFO("{}", line);
}

void BootReportError(const char* line)
{
    MCLA_LOG_ERROR("{}", line);
}

} // namespace mcla::boot