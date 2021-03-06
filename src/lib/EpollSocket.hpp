#ifndef __EPOLLSOCKET_HPP
#define __EPOLLSOCKET_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <string.h>
#include <arpa/inet.h>

typedef int (*EpollInputCallBackFunction)(const int iFd);

class CEpollSocket
{
public:
	int Init(const char* szServerAddr, const unsigned short usPort, bool bUseNagle = true);
	int Wait(int iTimeout = 0);
	int RegisterEpollEventFunction(void* pFunction, const int iEventType);
	
private:
	int m_iEpollSocketID;
	int m_iListenSocketID;
	struct sockaddr_in m_stServerAddr;
	struct epoll_event m_stListenEvent;
	EpollInputCallBackFunction m_fpEpollInputCallBackFunc;
	bool m_bUseNagle;
	
public:
	static const int MAX_CLIENT_CONNECTION;

public:
	static int SetNonblocking(int iSock);
	static int SetNonNagle(int iSock);
	
};

#endif
