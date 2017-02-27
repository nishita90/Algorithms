/*
String to int conversion. Take care of negative sign as well.
TO DO: Functions below do not cover all test cases. Eg: Whitespaces in a string or
characters that are not relavant to int.
*/


#include <iostream>
#include <string>
#include <climits>
#include <stdio.h>

using namespace std;

//This is using char *
int myAtoi(char *str)
{
    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit

    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;
        i++;  // Also update index of first digit
    }

    // Iterate through all digits and update the result
    // You subtract the ASCII value of 0 from ASCII value of string[i]
    // this is because int value of 0 = 48.
    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    // Return result with sign
    return sign*res;
}
//This is using std::string with mostly all test cases. CHECK!
int myAtoi_string(std::string)
{
    int val = 0;
    //set sign to 1 for +ve
    int sign = 1;
    for (int i = 0; i < str.size();i++)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '-')? -1 : 1;
        while('0' <= str[i] <= '9')
        {
            val = val*10 + str[i] -'0';
            if(val*sign >= INT_MAX) return INT_MAX;
            if(val*sign <= INT_MIN) return INT_MIN;
        }
    }
    return val*sign;
}


int main()
{
    char str[] = "-123";
    int val = myAtoi(str);
    std::string strings = "  9867402";
    int val2 = myAtoi_string(strings);
    std::cout << val << " " << strings << std::endl;

   return 0;
}
