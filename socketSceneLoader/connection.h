#pragma once
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
using std::string;
using std::thread;
using std::queue;
using std::stack;
using std::vector;

//#define LOG_OPEN
#ifdef LOG_OPEN
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(X)
#endif
class Server
{ 
public:
	Server()
	{
	}

	void SetAddr(string ip, string port);
	void Bind();
	void Receive();
	void Accept();
	int InitSocket();
	void Close();
	static int Send(string str);
	static void Receive();

private:
	thread recieveThread;
	queue<char> charQueue;
	SOCKET ServerSocket;
	stack<char> charStack;
	string ipAddr;
	string port;

public:
	queue<string> jsonQueue;
};

class Client
{
public:
	int InitSocket();
	int Connect(string ip, string port);
	int Send(string str);
	void Receive();
	void Close();

	queue<string> jsonQueue;
	stack<char> charStack;

private:
	SOCKET ClientSocket;
};