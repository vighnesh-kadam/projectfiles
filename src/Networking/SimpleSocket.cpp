#include "SimpleSocket.hpp"
#include <cstdlib>

HDE::SimpleSocket::SimpleSocket(int domain,int service,int protocol,int port,u_long interface)
{
	//define addr struct
	address.sin_family=domain;
	address.sin_port=htons(port);
	address.sin_addr.s_addr=htonl(interface);
	
	//Establish connection
	sock = socket(domain,service,protocol);
	test_connection(sock);
	
	//test_connection(connection);
	
}

void HDE::SimpleSocket::test_connection(int item_to_test){
	if(item_to_test<0){
		perror("failed to connect");
		exit(EXIT_FAILURE);
	}
	
}

struct sockaddr_in HDE::SimpleSocket::get_address(){
	return address;
}

int HDE::SimpleSocket::get_sock(){
	return sock;
}

int HDE::SimpleSocket::get_connection(){
	return connection;
}

void HDE::SimpleSocket::set_connection(int con){
	connection=con;
}