#pragma once
#include "SchemaEnum.h"
#include <string>
namespace ArchonIPC
{
	struct DNSRequest
	{
        int PID = 0;
        DNSEventType EventType;
        unsigned long long UIntParam1 = 0;
        unsigned long long UIntParam2 = 0;
        std::wstring StringParam1;
        std::wstring StringParam2;
	};

    struct DNSResponse
    {
        DNSAction Action;
        unsigned long long UIntParam1 = 0;
        unsigned long long UIntParam2 = 0;
        std::wstring StringParam1;
        std::wstring StringParam2;
    };
}
