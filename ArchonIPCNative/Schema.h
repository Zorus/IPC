#pragma once

#include <IPC/SharedMemory.h>
#include <boost/optional.hpp>
#include <boost/interprocess/containers/string.hpp>
#include "SchemaEnum.h"

namespace ArchonIPC
{
    struct Request
    {
        int PID;
        DNSEventType EventType;
        unsigned long long UIntParam1;
        unsigned long long UIntParam2;
        boost::optional<boost::interprocess::basic_string<wchar_t, std::char_traits<wchar_t>, IPC::SharedMemory::Allocator<wchar_t>>> StringParam1;
        boost::optional<boost::interprocess::basic_string<wchar_t, std::char_traits<wchar_t>, IPC::SharedMemory::Allocator<wchar_t>>> StringParam2;
    };

    struct Response
    {
        DNSAction Action;
        unsigned long long UIntParam1;
        unsigned long long UIntParam2;
        boost::optional<boost::interprocess::basic_string<wchar_t, std::char_traits<wchar_t>, IPC::SharedMemory::Allocator<wchar_t>>> StringParam1;
        boost::optional<boost::interprocess::basic_string<wchar_t, std::char_traits<wchar_t>, IPC::SharedMemory::Allocator<wchar_t>>> StringParam2;
    };
}