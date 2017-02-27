/*
Given a number : return true if it is StroboGrammatic and false otherwise
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
bool checkStroboGrammatic(std::string number)
{
    //initialize to true
    bool isStrobo = true;
    std::unordered_map<std::string,std::string> strobo_map{
      {"0","0"},{"8","8"},{"1","1"},
      {"2","5"},{"5","2"},{"6","9"}
    };
    std::unordered_map<std::string,std::string>::iterator iter;//  = strobo_map.find(number);
   int i , j;
   int half = int(number.length()/2);
    if (number.length() % 2) // check if odd
        i = j = half;
    else
    {
        i = half -1;
        j = half;
    }

    for (int k = 0 ; k < half; k++)
    {
      std::string s (1,number.at(i-k));
      iter  = strobo_map.find(s);
      std::cout << "!!!!!" << iter->first << " " << iter->second;
      if ( (strobo_map.find(s))->second == std::string(1,number[j+k]) )
        {
            isStrobo = true;
            i--;
            j++;
        }
        else
            return false;
    }
    return isStrobo;
}
int main()
{
    std::string number;
    std::cout << "Enter number to be checked.";
    std::cin >> number;
    bool isStrobo = checkStroboGrammatic(number);
    std::cout << "Number entered is " << isStrobo << " for StroboGrammatic. " << std::endl ;
   return 0;
}
