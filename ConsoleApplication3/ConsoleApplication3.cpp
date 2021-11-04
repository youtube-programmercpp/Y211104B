// ConsoleApplication3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <sstream>
int main()
{
	std::istringstream istm("123,456,789");
	for (;;) {
		std::string s;
		if (std::getline(istm, s, ','))
			std::cout << s << '\n';
		else
			break;
	}
}
