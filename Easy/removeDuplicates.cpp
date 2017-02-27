/*
Given a vector of numbers, remove duplicates
*/
#include <iostream>
#include <vector>
#include <algorithm>

//Sorting the vector and comparing consecutive elements.
std::vector<int> removeDuplicates(std::vector<int> L1)
{
  std::sort(L1.begin(), L1.end());
  int i = L1.size() - 1;
  while (i > 0)
  {
    if (L1.at(i) == L1.at(i-1))
    {
        std::vector<int>::iterator n = std::find(L1.begin(), L1.end(), L1.at(i));
        L1.erase(n);
    }

    i--;
  }
  return L1;
}

int main()
{
  //Sample vector
  std::vector<int> list;
  list.push_back(1);
  list.push_back(3);
  list.push_back(5);
  list.push_back(2);
  list.push_back(1);
  list.push_back(1);
  std::vector<int> unique_list = removeDuplicates(list);
  std::cout << "Unique Elements are : " << std::endl;
  for(std::vector<int>::iterator i = unique_list.begin(); i < unique_list.end(); i++)
    std::cout << " " << *i << std::endl;

  return 0;
}
