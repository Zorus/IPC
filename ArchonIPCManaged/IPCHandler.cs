using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using IPC.Managed;
using ArchonIPC.Managed;

namespace ArchonIPC
{
    internal class IPCHandler
    {
        private readonly IIPCRequestHandler _dnsHandler;
        private readonly SharedMemory _outMemory;
        public IPCHandler(IIPCRequestHandler handler, SharedMemory outMemory)
        {
            _dnsHandler = handler;
            _outMemory = outMemory;
        }

        public async Task<Managed.Response> Handle(Managed.Request request)
        {
            var res = await _dnsHandler.HandleDnsRequest(
                new ArchonIPC.DNSRequest()
                {
                    PID = request.PID, 
                    EventType = (DNSEventType)request.EventType,
                    StringParam1 = request.StringParam1,
                    StringParam2 = request.StringParam2,
                    UIntParam1 = request.UIntParam1,
                    UIntParam2 = request.UIntParam2,
                });

            return new Managed.Response(_outMemory)
            {
                Action = (Managed.DNSAction)res.Action,
                StringParam1 = res.StringParam1,
                StringParam2 = res.StringParam2,
                UIntParam1 = res.UIntParam1,
                UIntParam2 = res.UIntParam2
            };
        }
    }
}
