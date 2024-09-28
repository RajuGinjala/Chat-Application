
#include <QCoreApplication>
#include<WinSock2.h>
#include <iostream>
#include "stdafx.h"
#include <WinSock2.h>
#include <WS2tcpip.h>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //1
    std::cout << "1ts step intializing the wsa variables ";
    SOCKET sereversoc, acceptsock;int port = 55555;WSADATA ws; int waser;
    WORD wre = MAKEWORD(2, 2);
    waser = WSAStartup(wre, &ws);
    if (waser != 0)
    {
        cout << "the winsock dll not found " << endl;
    }
    else
    {
        cout << "winsock is found " << endl;
        cout << "status :" << ws.szSystemStatus << endl;
    }
  //2.


    sereversoc = INVALID_SOCKET;

    sereversoc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sereversoc == INVALID_SOCKET)
    {
        cout << "sock is not creating ...? close the wsa variable" << endl;

        WSACleanup();
    }
    else
    {
        cout << " sock is opened " << endl;
    }

    //3.


    sockaddr_in service;

    service.sin_family = AF_INET;
    InetPton(AF_INET, _T("192.168.1.25"), &service.sin_addr.s_addr);

    service.sin_port = htons(port);

    if(bind(sereversoc, (SOCKADDR*)&service, sizeof(service)<0){

        //if (bind(sereversoc, (struct sockaddr *) &service, sizeof(service)) < 0) {
            perror("Error binding socket");
            exit(1);
        }

    if (listen(sereversoc, 1) == SOCKET_ERROR)
    {
        cout << " listen() error " << WSAGetLastError() << endl;
    }
    else
    {
        cout << " listen mode is ok, im waiting " << endl;
    }


    acceptsock = accept(sereversoc, NULL, NULL);

    if (acceptsock == INVALID_SOCKET) {
        cout << " accept is failed ..!" << endl;
        WSACleanup();
    }
    else
    {
        cout << " accepted conncetion " << endl;
    }


    char rs[200]; char confir[200];



    while (!(strcmp(rs, "stop") == 0))
    {
        int me = recv(acceptsock, rs, 200, 0);
        if (me > 0)
        {
            cout << " client : - " << rs << endl;
        }
        else
        {
            cout << "messgae not recived " << endl;
            break;
        }
        int br;
        cout << "enter a message " << endl;
        cin.getline(confir,200);

        br = send(acceptsock, confir, 200, 0);

        if (br > 0)
        {
            //cout << " sent msg : - "<<confir << endl;

        }
        else
        {
            cout << " msg not sent ";
            break;
            return -1;

        }
    }
    cout << " chating is stoped";
    WSACleanup();



    return a.exec();
}
