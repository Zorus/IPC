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
    public enum class DNSAction
    {
        Allow = 0,
        Block = 1
    };

    namespace
    {
#pragma managed(push, off)
        inline void EmplaceRequest(ArchonIPC::Request& request, IPC::SharedMemory& memory)
        {
            request.StringParam1.emplace(memory.GetAllocator<wchar_t>());
            request.StringParam2.emplace(memory.GetAllocator<wchar_t>());
        }
        inline void SetStringParam1(ArchonIPC::Request& request, const wchar_t* text)
        {
            request.StringParam1->assign(text);
        }
        inline void SetStringParam2(ArchonIPC::Request& request, const wchar_t* text)
        {
            request.StringParam2->assign(text);
        }

        inline void EmplaceResponse(ArchonIPC::Response& response, IPC::SharedMemory& memory)
        {
            response.StringParam1.emplace(memory.GetAllocator<wchar_t>());
            response.StringParam2.emplace(memory.GetAllocator<wchar_t>());
        }
        inline void SetStringParam1(ArchonIPC::Response& response, const wchar_t* text)
        {
            response.StringParam1->assign(text);
        }
        inline void SetStringParam2(ArchonIPC::Response& response, const wchar_t* text)
        {
            response.StringParam2->assign(text);
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

        property unsigned long long UIntParam1
        {
            unsigned long long get()
            {
                return m_impl->UIntParam1;
            }

            void set(unsigned long long value)
            {
                m_impl->UIntParam1 = value;
            }
        }
        property unsigned long long UIntParam2
        {
            unsigned long long get()
            {
                return m_impl->UIntParam2;
            }

            void set(unsigned long long value)
            {
                m_impl->UIntParam2 = value;
            }
        }
        property System::String^ StringParam1
        {
            System::String^ get()
            {
                return m_impl->StringParam1 ? msclr::interop::marshal_as<System::String^>(m_impl->StringParam1->c_str()) : nullptr;
            }

            void set(System::String^ value)
            {
                SetStringParam1(*m_impl, value ? msclr::interop::marshal_context{}.marshal_as<const wchar_t*>(value) : L"");
            }
        }
        property System::String^ StringParam2
        {
            System::String^ get()
            {
                return m_impl->StringParam2 ? msclr::interop::marshal_as<System::String^>(m_impl->StringParam2->c_str()) : nullptr;
            }

            void set(System::String^ value)
            {
                SetStringParam2(*m_impl, value ? msclr::interop::marshal_context{}.marshal_as<const wchar_t*>(value) : L"");
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
    public ref class Response
    {
    internal:
        Response(const ArchonIPC::Response& request)
            : m_impl{ request }
        {}
    public:
        Response(IPC::Managed::SharedMemory^ memory)
        {
            EmplaceResponse(*m_impl, *memory->Impl);
        }

        property DNSAction Action
        {
            DNSAction get()
            {
                return (ArchonIPC::Managed::DNSAction)m_impl->Action;
            }

            void set(DNSAction value)
            {
                m_impl->Action = (ArchonIPC::DNSAction)value;
            }
        }

        property unsigned long long UIntParam1
        {
            unsigned long long get()
            {
                return m_impl->UIntParam1;
            }

            void set(unsigned long long value)
            {
                m_impl->UIntParam1 = value;
            }
        }
        property unsigned long long UIntParam2
        {
            unsigned long long get()
            {
                return m_impl->UIntParam2;
            }

            void set(unsigned long long value)
            {
                m_impl->UIntParam2 = value;
            }
        }
        property System::String^ StringParam1
        {
            System::String^ get()
            {
                return m_impl->StringParam1 ? msclr::interop::marshal_as<System::String^>(m_impl->StringParam1->c_str()) : nullptr;
            }

            void set(System::String^ value)
            {
                SetStringParam1(*m_impl, value ? msclr::interop::marshal_context{}.marshal_as<const wchar_t*>(value) : L"");
            }
        }
        property System::String^ StringParam2
        {
            System::String^ get()
            {
                return m_impl->StringParam2 ? msclr::interop::marshal_as<System::String^>(m_impl->StringParam2->c_str()) : nullptr;
            }

            void set(System::String^ value)
            {
                SetStringParam2(*m_impl, value ? msclr::interop::marshal_context{}.marshal_as<const wchar_t*>(value) : L"");
            }
        }
    internal:
        property ArchonIPC::Response& Impl
        {
            ArchonIPC::Response& get()
            {
                return *m_impl;
            }
        }
    private:
        IPC::Managed::detail::NativeObject<ArchonIPC::Response> m_impl;
    };
}
}
