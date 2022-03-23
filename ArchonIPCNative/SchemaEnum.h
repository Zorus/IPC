#pragma once
namespace ArchonIPC
{
    enum class DNSEventType
    {
        _DNSQueryA = 0,
        _DNSQueryW = 1,
        _DNSQueryUTF8 = 2,
        _DNSQueryEx = 3,
        _getaddrinfo = 4,
        _getaddrinfow = 5,
        _getaddrinfoexa = 6,
        _getaddrinfoexw = 7
    };
    enum class DNSAction
    {
        Allow = 0,
        Block = 1
    };
}