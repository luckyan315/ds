#include <iostream>
#include <string>

using namespace std;

const int N = 6;

std::string shift_string(const char* str, const int arr_len, const int shift_len);

void reverse_string(char* str, const int arr_len, const int rev_len);
void reverse(char* pStr, int from, int to);

void print(const char* pStr, const int cnt);
int main(int argc, char *argv[])
{
	char str[N + 1] = "123456";

	std::cout<<"shift string without modify ori str..."<<std::endl;
	std::cout<<shift_string(str, N, 2)<<std::endl;

	std::cout<<"reverse_strings & modify ori str..."<<std::endl;
	reverse_string(str, N, 2);
	print(str, N);

    return 0;
}

std::string shift_string(const char *pStr, const int arr_len, const int shift_len)
{
	char * pTmp = new char[arr_len + 1];
	for(int i=0; i<arr_len; ++i)
	{
		*(pTmp + i) = *(pStr + (i + shift_len) % arr_len);
	}
	return std::string(pTmp, arr_len);
}

void reverse_string(char *pStr, const int arr_len, const int rev_len)
{
	reverse(pStr, 0, rev_len - 1);
	reverse(pStr, rev_len, arr_len -1);
	reverse(pStr, 0, arr_len -1);
	return;
}

void reverse(char *pStr, int from, int to)
{
	while(from < to)
	{
		char ch = pStr[from];
		pStr[from++] = pStr[to];
		pStr[to--] = ch;
	}
}

void print(const char* pStr, const int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		std::cout<<pStr[i];
	}
	std::cout<<std::endl;
}
