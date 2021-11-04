#include <iostream> //std::cout を使うため
#include <fstream> //std::ifstream を使うため
#include <string> //std::string を使うため
#include <sstream> //std::istringstream を使うため
#include <vector>

std::vector<std::string> f(const std::string& line/*１行分の文字列*/)
{
	std::vector<std::string> row;

	//文字列 line の内容を入力ストリームにする
	std::istringstream istm(line);
	std::string item;//１項目分の文字列
	//１行読み込みではない
	if (std::getline(istm, item, ','/*区切り文字*/)) {
		row.push_back(std::move(item));
		for (;;) {
			if (std::getline(istm, item, ','))
				row.push_back(std::move(item));
			else
				break;
		}
	}
	return row;
}
std::vector<std::vector<std::string>> csv_read(std::istream&& istm)
{
	std::vector<std::vector<std::string>> table;
	for (;;) {
		std::string line;//１行分の文字列
		//１行読み込み
		if (std::getline(istm, line))
			table.push_back(f(line));
		else
			break;
	}
	return table;
}
void table_modify(std::vector<std::vector<std::string>>& table, int k)
{
	for (auto& cells : table) {
		if (!cells.empty()) {
			for (auto& cell : cells)
				cell = std::to_string(k * std::stoi(cell));
		}
	}
}
void csv_write(std::ostream&& ostm, const std::vector<std::vector<std::string>>& table)
{
	for (const auto& cells : table) {
		if (!cells.empty()) {
			ostm << cells[0];
			for (size_t i = 1; i < cells.size();++i)
				ostm << ',' << cells[i];
		}
		ostm << '\n';
	}
}
int main()
{
	auto table = csv_read(std::ifstream("..\\ConsoleApplication1\\test.csv"));
	table_modify(table, 10);
	csv_write(std::ofstream("test2.csv"), table);
}
