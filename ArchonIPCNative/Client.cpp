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

    DNSResponse Client::SendDnsRequest(int PID, int PPID, DNSEventType EventType, const char* CMDLine, const char* DomainName)
    {
        boost::optional<Response> response;
        Request request;
        request.PID = PID;
        request.PPID = PPID;
        request.EventType = EventType;
        request.CMDLine.emplace(CMDLine, m_client->GetConnection().GetOutputChannel().GetMemory()->GetAllocator<char>());
        request.DomainName.emplace(DomainName, m_client->GetConnection().GetOutputChannel().GetMemory()->GetAllocator<char>());
        response = (*m_client)(std::move(request)).get();
        return response->Response;
    }

    void Client::OnDisconnect(std::function<void()> onDisconnect)
    {
        m_client->GetConnection().RegisterCloseHandler(onDisconnect, true);
    }
}