/*
BF (Basic Format) - MIT License

Copyright SeanTolstoyevski and all contributors

* source: https://github.com/SeanTolstoyevski/bf

This project is provided as-is, without any warranties or guarantees.
While the authors have taken care in creating it, all responsibility for use
rests with the user.

 */

#include <iostream>

#include "./../bf.hpp"

int main()
{
	auto text{bf::format("su an saat: ", 11, ".", 19, '\n')};
	std::cout << text;

	return 0;
}