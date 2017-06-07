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
int myAtoi_string(std::string strs)
{

    int num = 0; int sign = 1;
    int index = 0;
    int total = 0;
    // 1. Remove all spaces in the string.
    //strs.erase(std::remove(strs.begin(), strs.end(), ' '), strs.end());
    while(strs[index] == ' ' && index < strs.length())
        index++;
    //2. Check for empty string.
    if (strs.empty())
        return 0;

    //3. Check for sign.
    if(strs[index] == '+' || strs[index] == '-'){
        sign = (strs[index++] == '-') ? -1 : 1;
    }

    //4. Iterate while value is between 0 and 9
    int bound = INT_MAX/10;
    while(index < strs.length()){
        num = strs[index] - '0';
        if( num < 0 || num > 9) break;
        //Check for overflow.
        if( bound < total || (total == bound && num > INT_MAX % 10 )){
            return (sign == 1 ? INT_MAX : INT_MIN);
        }

        total =  total*10 + num;
        index++;
    }

  return total*sign;
}


int main()
{
    char str[] = "-123";
    int val = myAtoi(str);
    std::string strings = "  -9867402  ";
    int val2 = myAtoi_string(strings);
    std::cout << val << " " << strings << std::endl;

   return 0;
}
