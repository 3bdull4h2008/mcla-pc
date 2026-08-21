// spdlog forwarding for the SEH-bearing boot TU (see boot_host.h). Keeps fmt
// template instantiation out of the TU that contains __try/__except.

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