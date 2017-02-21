/*
Given an array of integers, every element appears *twice* except for one. Find that single one.
*/
#include <iostream>

using namespace std;

int findSingleElement(int doubledElements[], int len)
{
    int singleElement = doubledElements[0];
    int i = 0;
    while(i < (len-1))
    {
       // XOR serially.
        singleElement = singleElement ^ doubledElements[++i];
        std::cout << "running element is : " << singleElement << std::endl;
    }
    return singleElement;
}

int main()
{
    int doubledElements[5] = {1,2,3,2,1};
    int singleElement = findSingleElement(doubledElements, 5);
    std::cout << "single element is : " << singleElement << std::endl;
   return 0;
}
