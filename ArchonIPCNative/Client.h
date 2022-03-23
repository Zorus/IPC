#pragma once
#include "SchemaEnum.h"
#include <memory>
#include <functional>
#include "ClientMessages.h"

namespace IPC
{
    struct DefaultTraits;
    template <typename Request, typename Response, typename Traits>
    class Client;
}
namespace ArchonIPC
{
    struct Request;
    struct Response;
}

namespace ArchonIPC
{
    class Client
    {
        public:
            Client(const char* address);
            DNSResponse SendDnsRequest(const DNSRequest& request);
            void OnDisconnect(std::function<void()> onDisconnect);
        private:
            std::shared_ptr<IPC::Client<Request, Response, IPC::DefaultTraits>> m_client;
    };
}

