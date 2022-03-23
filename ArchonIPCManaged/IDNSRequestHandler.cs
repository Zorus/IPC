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
    public enum DNSAction
    {
        Allow = 0,
        Block = 1
    };
    public struct DNSRequest
    {
        public int PID;
        public DNSEventType EventType;
        public ulong UIntParam1;
        public ulong UIntParam2;
        public string StringParam1;
        public string StringParam2;
    }
    public struct DNSResponse
    {
        public DNSAction Action;
        public ulong UIntParam1;
        public ulong UIntParam2;
        public string StringParam1;
        public string StringParam2;
    }
    public interface IIPCRequestHandler
    {
        Task<DNSResponse> HandleDnsRequest(DNSRequest request);
    }
}
