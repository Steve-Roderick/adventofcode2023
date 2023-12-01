#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
/* Warm up day to remind myself how to use a little cpp
 * Given an input file like this:
 * ```
 * 1 world
 * 2 from
 * 3 day
 * 4 00
 * 0 hello
 * ```
 * Write program to emit the above file but sorted by the leading index, i.e, prints:
 * ```
 * hello
 * world
 * from
 * day
 * 00
 * ```
*/

int main()
{
	std::vector<std::tuple<int, std::string>> vec;
	std::ifstream infile("./day-00/input.txt");
	std::string line;
	while(std::getline(infile, line)) {
        int d = line.find(" ");
        std::string num = line.substr(0, d);
        std::string msg  = line.substr(d+1, -1);
        int index = std::stoi(num);
        vec.push_back(std::make_tuple(index, msg));
	}
    std::sort(begin(vec), end(vec));
    for (auto & element : vec) {
        std::string msg = std::get<1>(element);
        std::cout << msg << std::endl;
    }

}
