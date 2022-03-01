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
        int PPID;
        DNSEventType EventType;
        boost::optional<boost::interprocess::basic_string<char, std::char_traits<char>, IPC::SharedMemory::Allocator<char>>> CMDLine;
        boost::optional<boost::interprocess::basic_string<char, std::char_traits<char>, IPC::SharedMemory::Allocator<char>>> DomainName;
    };

    struct Response
    {
        DNSResponse Response;
    };
}