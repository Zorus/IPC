using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArchonIPC
{
    public enum DNSEventType
    {
        DNSQueryA = 0,
        DNSQueryW = 1,
        DNSQueryUTF8 = 2,
        DNSQueryEx = 3,
        getaddrinfo = 4,
        getaddrinfow = 5,
        getaddrinfoexa = 6,
        getaddrinfoexw = 7
    };
    public enum DNSResponse
    {
        Allow = 0,
        Block = 1
    };
    public interface IDNSRequestHandler
    {
        Task<DNSResponse> HandleDnsRequest(int PID, int PPID, DNSEventType EventType, string CMDLine, string DomainName);
    }
}
