/*
Reverse a given string
*/
#include <stdio.h>
#include <string>
#include <iostream>

/* Function to reverse arr[] from start to end*/
std::string strRev(std::string str)
{
    int length = str.size();
    for (int i =0; i< length/2 ; i++)
    {
        str[i] = str[i] ^ str[length - 1 - i];
        str[length - 1 - i] = str[i] ^ str[length - 1 - i];
        str[i] = str[i] ^ str[length - 1 - i ];
    }
    return str;
}



/* Driver function to test above functions */
int main()
{
	std::string test;
	test = "nishita";
	std::string result_str = strRev(test);
	std::cout << "reversed string is : " << result_str <<std::endl;
	return 0;
}
