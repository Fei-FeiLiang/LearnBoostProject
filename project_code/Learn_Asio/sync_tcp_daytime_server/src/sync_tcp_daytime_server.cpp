#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;    //下面就可以只用用tcp开头

std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;
	time_t now = time(0);
	return ctime(&now);
}

int main()
{
	try
	{
		boost::asio::io_context io_context;

		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));

		for (;;)
		{
			tcp::socket socket(io_context);
			acceptor.accept(socket);

			std::string message = make_daytime_string() +";56778;";

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
		}
		system("pause");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	};

	system("pause");

	return 0;
}