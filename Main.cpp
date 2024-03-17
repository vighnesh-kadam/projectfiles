#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "./src/Networking/ListeningSocket.hpp"
#include "./src/Servers/TestServer.hpp"

int main(){
	
	std::cout<<"hello";
	
//	HDE::ListeningSocket ls=HDE::ListeningSocket(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10);
	std::cout<<"succes"<<std::endl;
	std::cin.get();

		HDE::TestServer *t;
		std::cout<<&t;
		
}
