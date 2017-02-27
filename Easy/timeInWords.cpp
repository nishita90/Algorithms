/*
Given the time in numerals we may convert it into words, as shown below:
5:00 -> five o' clock          |   5:45 -> quarter to six
5:15 -> quater past five       |   5:38 -> twenty two minutes to six
5:30 -> half past five         |   5:38 -> thirty eight minutes past five
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int h;
  cin >> h;
  int m;
  cin >> m;
  std::string time;
  std::vector<std::string> time_map = {
    " o' clock", "one" , "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "tewenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"
  };
  if(m == 0)
    time = time_map.at(h) + time_map.at(0);
  else{
    if(m == 30 || m == 15){
      time = time_map.at(m) + " past ";
      time += time_map.at(h);
    }
    else if(m == 45){
      time = time_map.at(60-m) + " to ";
      time += time_map.at(h+1);
    }
    else if(m < 30){
      if (m == 1)
	time = time_map.at(m) + " minute past ";
      else
	time = time_map.at(m) + " minutes past ";
      time += time_map.at(h);
    }
    else if(m > 30){
      if ((60 - m) == 1)
	time = time_map.at(m) + " minute to ";
      else
	time = time_map.at(60-m) + " minutes to ";
      time += time_map.at(h+1);
    }

  }

  std::cout<<time<<std::endl;
  return 0;
}
