using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ArchonIPC;

namespace IPCServerTest
{
    class DNSHandler : IDNSRequestHandler
    {
        public Task<DNSResponse> HandleDnsRequest(int PID, int PPID, DNSEventType EventType, string CMDLine, string DomainName)
        {
            Console.WriteLine($"Process ID:{PID}, Parent process ID:{PPID}, EventType:{EventType}, CMD line:{CMDLine}, Domain Name: {DomainName}");
            return Task.FromResult(DNSResponse.Block);
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
