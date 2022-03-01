using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IPC.Managed;

namespace ArchonIPC
{
    internal class IPCHandler
    {
        private readonly IDNSRequestHandler _dnsHandler;
        public IPCHandler(IDNSRequestHandler handler)
        {
            _dnsHandler = handler;
        }

        public async Task<Managed.Response> Handle(Managed.Request request)
        {
            var res = await _dnsHandler.HandleDnsRequest(request.PID, request.PPID
                    , (DNSEventType)request.EventType, request.CMDLine, request.DomainName);

            return new Managed.Response
            {
                _Response = (Managed.DNSResponse)res
            };
        }
    }
}
