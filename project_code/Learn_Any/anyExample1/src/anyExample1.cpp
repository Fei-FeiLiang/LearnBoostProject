#include <iostream>
#include <list>
#include "boost/any.hpp"


typedef std::list<boost::any> many;

void append_int(many& values, int value)
{
	boost::any to_append = value;
	values.push_back(to_append);
}

void append_float(many& values, float value)
{
	boost::any to_ap = value;
	values.push_back(to_ap);
}


bool is_int(const boost::any& anyValue)
{
	return anyValue.type() == typeid(int);
}

bool is_float(const boost::any& anyValue)
{
	return anyValue.type() == typeid(float);
}

bool is_double(const boost::any& anyValue)
{
	return anyValue.type() == typeid(double);
}

int main(int argc, char** argv)
{
	many myMany;
	append_int(myMany, 3);
	append_float(myMany, 34.56789);

	myMany.push_back(23.456);
	myMany.push_back("34543nihao");

	std::cout << "d" << std::endl;

	for (auto n : myMany)
	{
		if (is_int(n))
		{
			std::cout << "int value is:" << boost::any_cast<int>(n) << std::endl;
		}
		if (is_float(n))
		{
			std::cout << "float value is :" << boost::any_cast<float>(n) << std::endl;
		}
		if (is_double(n))
		{
			std::cout << "double value is:" << boost::any_cast<double>(n) << std::endl;
		}

	}

	system("pause");
	return 0;
}