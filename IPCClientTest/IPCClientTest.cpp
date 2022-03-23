// IPCClientTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Client.h"

int main()
{
    ArchonIPC::Client client("ipc://ArchonAPC");  

    auto resp = client.SendDnsRequest(ArchonIPC::DNSRequest{ 25, ArchonIPC::DNSEventType::_getaddrinfo, 255, 366, L"DOMAIN_TEST1", L"DOMAIN_TEST2" });
    std::wcout << L"Action: " << (resp.Action == ArchonIPC::DNSAction::Allow ? L"Allow" : L"Block")
        << L" UIntParam1: " << resp.UIntParam1
        << L" UIntParam2: " << resp.UIntParam2
        << L" StringParam1: " << resp.StringParam1
        << L" StringParam2: " << resp.StringParam2 
        << std::endl;
    system("pause");
}
