#include "Client.h"
#include "Schema.h"
#include "boost/winapi/thread.hpp"
#include <IPC/Transport.h>
namespace ArchonIPC
{
    Client::Client(const char* address)
    {
        IPC::Transport<Request, Response> transport;
        auto connector = transport.ConnectClient(address, false);
        m_client = connector();
    }

    DNSResponse Client::SendDnsRequest(const DNSRequest& dnsRequest)
    {
        boost::optional<Response> response;
        Request request;
        request.PID = dnsRequest.PID;
        request.EventType = dnsRequest.EventType;
        request.StringParam1.emplace(dnsRequest.StringParam1.c_str(), m_client->GetConnection().GetOutputChannel().GetMemory()->GetAllocator<char>());
        request.StringParam2.emplace(dnsRequest.StringParam2.c_str(), m_client->GetConnection().GetOutputChannel().GetMemory()->GetAllocator<char>());
        request.UIntParam1 = dnsRequest.UIntParam1;
        request.UIntParam2 = dnsRequest.UIntParam2;
        response = (*m_client)(std::move(request)).get();
        return DNSResponse
        {
            response->Action,
            response->UIntParam1,
            response->UIntParam2,
            response->StringParam1.get().c_str(),
            response->StringParam2.get().c_str()
        };
    }

    void Client::OnDisconnect(std::function<void()> onDisconnect)
    {
        m_client->GetConnection().RegisterCloseHandler(onDisconnect, true);
    }
}