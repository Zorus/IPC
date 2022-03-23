#include "SchemaInterop.h"
#include <IPC/Managed/detail/TransportImpl.h>
namespace IPC
{
namespace Managed
{
    namespace detail
    {
        template <>
        struct Convert<ArchonIPC::Response>
        {
            using type = ArchonIPC::Managed::Response^;

            static const ArchonIPC::Response& From(type% from)
            {
                return from->Impl;
            }
        };

        template <>
        struct Convert<ArchonIPC::Managed::Response^>
        {
            using type = ArchonIPC::Response;

            static ArchonIPC::Managed::Response^ From(const type& from)
            {
                return gcnew ArchonIPC::Managed::Response{ from };
            }
        };


        template <>
        struct Convert<ArchonIPC::Request>
        {
            using type = ArchonIPC::Managed::Request^;

            static const ArchonIPC::Request& From(type% from)
            {
                return from->Impl;
            }
        };

        template <>
        struct Convert<ArchonIPC::Managed::Request^>
        {
            using type = ArchonIPC::Request;

            static ArchonIPC::Managed::Request^ From(const type& from)
            {
                return gcnew ArchonIPC::Managed::Request{ from };
            }
        };


        template Transport<ArchonIPC::Managed::Request^, ArchonIPC::Managed::Response^>;

    } // detail

} // Managed
} // IPC
