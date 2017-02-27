/*
Given a word w, rearrange the letters of w to construct another word s in such a way that  is lexicographically greater than w. In case of multiple possible answers, find the lexicographically smallest one among them.

That is : Find the lexicographically next permutation of the same string.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  std::vector<std::string> w, s; int t;
  std::cin >> t;
  std::string input;
  for (int case_i=0;case_i < t; case_i++){
    std::cin >> input;
    w.push_back(input);
  }

  for (auto words : w){
    int i= words.length() - 1;
    while(i >0 && words[i-1] >= words[i]){
      i--;
    }
    //check if i is at the last permutation before proceding
    if(i <= 0){
      std::cout<<"no answer"<<std::endl;
    }
    else{
      //in the remaining array, i.e from current value of i to end of array,
      // find the right most value exceeding array[i]
      int j = words.length() - 1;
      while(j > i && words[j] <= words[i-1]) // why the '=' condition?
	j--;
      // now swap a[i-1] and a[j]
      words[i-1] = words[i-1] ^ words[j];
      words[j]   = words[i-1] ^ words[j];
      words[i-1] = words[i-1] ^ words[j];

      //now reverse the order of the characters from i to end of array.
      j = words.length() - 1;
      while(i < j){
	// now swap a[i] and a[j]
	words[i] = words[i] ^ words[j];
	words[j]   = words[i] ^ words[j];
	words[i] = words[i] ^ words[j];
	i++;
	j--;
      }
      std::cout<<words<<std::endl;
    }
  }


  return 0;
}
