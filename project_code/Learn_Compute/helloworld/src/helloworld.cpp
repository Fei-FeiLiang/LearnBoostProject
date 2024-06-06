#include <iostream>

#include "boost/compute/core.hpp"

int main(int argc, char** argv)
{
	boost::compute::device myDevice = boost::compute::system::default_device();

	std::cout << "hello: " << myDevice.name();
	std::cout << " (platform: " << myDevice.platform().name() << ")" << std::endl;


	system("pause");
	return 0;
}