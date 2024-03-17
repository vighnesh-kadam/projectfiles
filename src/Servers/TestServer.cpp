#include <stdio.h>
#include "TestServer.hpp"
#include <iostream>
#include <cstring>
HDE::TestServer::TestServer():SimpleServer(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10)
{
	launch();
	
}

void HDE::TestServer::acceptor()
{
		ListeningSocket *socket_ptr=get_socket();
		int sock_fd=socket_ptr->get_sock();
		struct sockaddr_in  address=socket_ptr->get_address();
		int addr_length=sizeof(address);
		new_socket=accept(sock_fd,(struct sockaddr*)&address,(socklen_t*)&addr_length);
		
		read(new_socket,buffer,3000);
		
}

void HDE::TestServer::handler(){
	std::cout<<buffer<<std::endl;
}

void HDE::TestServer::responder(){
	
	char *hello="hello from the server";
	
	write(new_socket,hello,std::strlen(hello));
	
	
}


void HDE::TestServer::launch(){
	std::cout<<"====waiting======"<<std::endl;
	acceptor();
	handler();
	responder();
	std::cout<<"====done======"<<std::endl;
	
}