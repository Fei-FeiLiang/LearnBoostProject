#include <iostream>
#include "boost/asio.hpp"


void print(const boost::system::error_code&)
{
	std::cout << "hello, world, this is a asynchronously timer" << std::endl;
}

int main(int argc, char** argv)
{
	boost::asio::io_context io;

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

	t.async_wait(&print);

	io.run();

	for (int i=0; i<5; i++)
	{
		std::cout << "0000000000000000000000000000000" << std::endl;
	}
	

	system("pause");

	return 0;
}