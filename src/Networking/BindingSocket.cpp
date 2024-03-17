#include <stdio.h>
#include "BindingSocket.hpp"

HDE::BindingSocket::BindingSocket(int domain,int service,int protocol,int port,u_long interface):SimpleSocket(domain,service,protocol,port,interface)
{
int  con=connect_to_network(get_sock(),get_address());
	set_connection(con);
	test_connection(get_connection());
	

	
}

int HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address){

	return bind(sock,(struct sockaddr*)&address,sizeof(address));
}