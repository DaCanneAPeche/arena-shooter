#include <iostream>
#include <string>

void debug(std::string title, std::string text, bool error=false) {
	if (!error)
		std::cout << '[' << title << "] " << text << std::endl;

	else
		std::cerr << "\033[1;31m[" << title << "] " << text << "\033[1;0m" << std::endl;

}
