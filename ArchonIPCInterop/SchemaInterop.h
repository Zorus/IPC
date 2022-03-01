#include "Schema.h"
#include <IPC/Managed/detail/Cast.h>
#include <IPC/Managed/detail/NativeObject.h>
#include <IPC/Managed/detail/Interop/SharedMemory.h>
#include <msclr/marshal.h>


namespace ArchonIPC
{
namespace Managed
{
    public enum class DNSEventType
    {
        _DNSQueryA = 0,
        _DNSQueryW = 1,
        _DNSQueryUTF8 = 2,
        _DNSQueryEx = 3,
        _getaddrinfo = 4,
        _getaddrinfow = 5,
        _getaddrinfoexa = 6,
        _getaddrinfoexw = 7
    };
    public enum class DNSResponse
    {
        Allow = 0,
        Block = 1
    };

    namespace
    {
#pragma managed(push, off)
        inline void EmplaceRequest(ArchonIPC::Request& request, IPC::SharedMemory& memory)
        {
            request.CMDLine.emplace(memory.GetAllocator<char>());
            request.DomainName.emplace(memory.GetAllocator<char>());
        }

        inline void SetCMDLine(ArchonIPC::Request& request, const char* text)
        {
            request.CMDLine->assign(text);
        }
        inline void SetDomainName(ArchonIPC::Request& request, const char* text)
        {
            request.DomainName->assign(text);
        }
#pragma managed(pop)
    }

    [IPC::Managed::Object]
    public ref class Request
    {
    internal:
        Request(const ArchonIPC::Request& request)
            : m_impl{ request }
        {}
    public:
        Request(IPC::Managed::SharedMemory^ memory)
        {
            EmplaceRequest(*m_impl, *memory->Impl);
        }

        property int PID
        {
            int get()
            {
                return m_impl->PID;
            }

            void set(int value)
            {
                m_impl->PID = value;
            }
        }

        property int PPID
        {
            int get()
            {
                return m_impl->PPID;
            }

            void set(int value)
            {
                m_impl->PPID = value;
            }
        }

        property DNSEventType EventType
        {
            DNSEventType get()
            {
                return (ArchonIPC::Managed::DNSEventType)m_impl->EventType;
            }

            void set(DNSEventType value)
            {
                m_impl->EventType = (ArchonIPC::DNSEventType)value;
            }
        }

        property System::String^ CMDLine
        {
            System::String^ get()
            {
                return m_impl->CMDLine ? msclr::interop::marshal_as<System::String^>(m_impl->CMDLine->c_str()) : nullptr;
            }

            void set(System::String^ value)
            {
                SetCMDLine(*m_impl, value ? msclr::interop::marshal_context{}.marshal_as<const char*>(value) : "");
            }
        }
        property System::String^ DomainName
        {
            System::String^ get()
            {
                return m_impl->DomainName ? msclr::interop::marshal_as<System::String^>(m_impl->DomainName->c_str()) : nullptr;
            }

            void set(System::String^ value)
            {
                SetDomainName(*m_impl, value ? msclr::interop::marshal_context{}.marshal_as<const char*>(value) : "");
            }
        }
    internal:
        property ArchonIPC::Request& Impl
        {
            ArchonIPC::Request& get()
            {
                return *m_impl;
            }
        }
    private:
        IPC::Managed::detail::NativeObject<ArchonIPC::Request> m_impl;
    };


    [IPC::Managed::Object]
    public ref struct Response
    {
        property DNSResponse _Response;
    };
}
}
