#include <iostream>
#include <vector> //std::vector を使うため
#include <string>
#include <sstream>

int main()
{
	std::vector<std::string> a;
	for (std::istringstream istm("ABC,DEF,GHI,JKL");;) {
		std::string s;
		if (std::getline(istm, s, ','))
			a.push_back(s);
		else
			break;
	}
	for (const auto& s : a) {
		std::cout << s << '\n';
	}
}
