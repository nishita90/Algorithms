/*
Given a vector of numbers, remove duplicates
Solultions are O(nlogn) and O(n^2)
*/
#include <iostream>
#include <vector>
#include <algorithm>

//Sorting the vector and comparing consecutive elements.
std::vector<int> removeDuplicates(std::vector<int> L1)
{
  std::vector<int> L2;
  //Best case for sort is O(nlogn)
  std::sort(L1.begin(), L1.end());
  int count = 0;
  L2.push_back(L1.at(0));
  //Scan through the vector once = O(n)
  for(std::vector<int>::iterator it = L1.begin(); it<L1.end(); it++)
  {
    if(L1.at(count) != *it)
    {
      L2.push_back(*it);
      count = it - L1.begin();
    }
  }
  // Below is O(n^2) since for every i, you use std::find which is O(n).
  // int i = L1.size() - 1;
  // while (i > 0)
  // {
  //   if (L1.at(i) == L1.at(i-1))
  //   {
  //       std::vector<int>::iterator n = std::find(L1.begin(), L1.end(), L1.at(i));
  //       L1.erase(n);
  //   }
  //
  //   i--;
  // }
  return L2;
}

int main()
{
  //Sample vector
  std::vector<int> list;
  list.push_back(2);
  list.push_back(2);
  list.push_back(1);
  list.push_back(3);
  list.push_back(5);
  list.push_back(2);
  list.push_back(1);
  list.push_back(1);
  list.push_back(2);
  list.push_back(5);
  std::vector<int> unique_list = removeDuplicates(list);
  std::cout << "Unique Elements are : " << std::endl;
  for(std::vector<int>::iterator i = unique_list.begin(); i < unique_list.end(); i++)
    std::cout << " " << *i ;

  std::cout<<std::endl;
  return 0;
}
