#include "stdafx.h"
#include "Schema.h"
#include <IPC/Managed/detail/Interop/TransportImpl.h>


namespace IPC
{
namespace Managed
{
    namespace detail
    {
    namespace Interop
    {
        template Transport<ArchonIPC::Request, ArchonIPC::Response>;

    } // Interop
    } // detail

} // Managed
} // IPC
