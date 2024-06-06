#include <iostream>
#include <chrono>
#include "boost/asio.hpp"


int main(int argc, char** argv)
{
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	//boost::asio::steady_timer t(io, std::chrono::seconds(5));   //这里我改成了C++11中的 chrono
	t.wait();
	std::cout << "Hello, world!" << std::endl;
	
	
	char *pChar = new char[5];


	system("pause");
	return 0;
}