#include <iostream>
#include <vector>

using namespace std;

const int MAX_BUFF=256;

void foo(int argc, char*argv[]){
    int i;
    for(i=1; i<argc; ++i){
        std::cout<<argv[i];
    }
}


int main(int argc, char *argv[])
{
    vector<int> vec = {1,2,3,4,5};

    int maxNum = argc;
    if(maxNum > MAX_BUFF){
        maxNum = MAX_BUFF;
    }

    foo(maxNum, argv);
    return 0;
}
