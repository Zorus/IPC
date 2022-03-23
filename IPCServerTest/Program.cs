using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ArchonIPC;

namespace IPCServerTest
{
    class DNSHandler : IIPCRequestHandler
    {
        public Task<DNSResponse> HandleDnsRequest(DNSRequest request)
        {
            Console.WriteLine($"Process ID:{request.PID}, EventType:{request.EventType}, StringParam1: {request.StringParam1}, StringParam2: {request.StringParam2}, UIntParam1: {request.UIntParam1}, UIntParam2: {request.UIntParam2}");
            return Task.FromResult(new DNSResponse { 
                Action = DNSAction.Allow,
                StringParam1 = "Responsed" + request.StringParam1,
                StringParam2 = "Responsed" + request.StringParam2,
                UIntParam1 = request.UIntParam1 + 1,
                UIntParam2 = request.UIntParam2 + 1
            });
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            using (var server = Server.Create("ipc://ArchonAPC", new DNSHandler()))
            {
                server.Error += (obj, err) => Console.WriteLine(err.Exception.ToString());
                Console.WriteLine("Listening on incoming connections. Press any key to exit.");
                Console.ReadKey();
            }
        }
    }
}
