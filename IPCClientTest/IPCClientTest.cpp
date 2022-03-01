// IPCClientTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Client.h"

int main()
{
    ArchonIPC::Client client("ipc://ArchonAPC");  
    auto resp = client.SendDnsRequest(25, 25, ArchonIPC::DNSEventType::_getaddrinfo, "CMD_TEST", "DOMAIN_TEST");
    system("pause");
}
