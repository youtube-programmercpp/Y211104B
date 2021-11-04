#include <fstream>
int main()
{
	std::ofstream file("test.csv");
	for (int i = 0; i < 10; ++i) {
		file << i * 0;
		for (int j = 1; j < 10; ++j) {
			file << ',' << i * j;
		}
		file << '\n';
	}
}
