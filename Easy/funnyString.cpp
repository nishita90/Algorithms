/*
Suppose you have a String,S, of length N that is indexed from 0 to N-1.
You also have some String,R , that is the reverse of String S.
S is funny if the condition |S(i) - S(i-1)| = |R(i) - R(i-1)|  is true for every character from  to 1 to N-1.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int num_strings=0;
  std::cin >> num_strings;
  std::vector<std::string> strings;
  std::string curr_string;
  for(int nums=0;nums < num_strings; nums++){
    std::cin >> curr_string;
    strings.push_back(curr_string);
  }
  for(std::vector<std::string>::iterator iter=strings.begin(); iter != strings.end(); iter++){
    curr_string = *iter;
    int length = curr_string.length();
    int i = length - 1, count=0;
    while(i > 0){
      if(abs(curr_string[i] - curr_string[i-1]) == abs(curr_string[length-i-1] - curr_string[length-i]))
	     count++;
      i--;
    }
    if(count == (length-1))
      std::cout<<"Funny"<<std::endl;
    else
      std::cout<<"Not Funny"<<std::endl;
  }
  return 0;
}
