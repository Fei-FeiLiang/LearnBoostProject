#include <iostream>
#include <chrono>
#include <boost/asio.hpp>



void printifno(const boost::system::error_code& error)
{
	std::cout << "error ------ : " << std::endl;
}

int main(int argc, char** argv)
{
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	t.async_wait(&printifno);
	
	io.run();

	system("pause");
	return 0;
}