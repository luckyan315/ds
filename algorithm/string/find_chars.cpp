#include <iostream>
#include <string>
using namespace std;

//check whether a include b chars
bool include_chars(const std::string& a, const std::string& b);

int main(int argc, char *argv[])
{
	std::string str_a("ABCDEFGHLMNOPQRS");
	std::string str_b("DCGSRZQPO");

	std::string ret = include_chars(str_a, str_b) ? "true" : "false";

	std::cout<<ret<<std::endl;
    return 0;
}

bool include_chars(const std::string& a, const std::string& b)
{
	//assume less than 32 letters, 
	int container = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		container |= 1 << (a.at(i) - 'A');
	}

	for (int i = 0; i < b.length(); ++i)
	{
		if ((container & (1 << (b.at(i) - 'A'))) == 0)
		{
			return false;
		}
	}
	
	return true;
}
