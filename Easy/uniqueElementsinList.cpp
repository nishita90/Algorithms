/*
Given lists L1 and L2,
return a list L3 which contains all the elements in L1
except any that also appear in L2.
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main()
{
    // std::list<int> L1 = {1,2,3,4,5};
    // std::list<int> L2 = {2,5,3,7};
    // std::list<int> L3;
    std::vector<int> L1;
    std::vector<int> L2;
    std::vector<int> L3;
    // L1.push_back(1);
    // L1.push_back(2);
    // L1.push_back(3);
    // L1.push_back(4);
    L1.push_back(5);
    L1.push_back(9);

    L2.push_back(1);
    L2.push_back(2);
    L2.push_back(3);
    L2.push_back(2);
    L2.push_back(2);
    L2.push_back(2);

    //This is O(n^2)
    // for (int p  : L1)
    // {
    //     int count = 0 ;
    //     for (int q : L2 )
    //     {
    //         if (p != q)
    //             count++;
    //         else
    //             break;
    //     }
    //     if (count == L2.size())
    //         L3.push_back(p);
    // }
    //
    // std::cout << '\n';
    // for (int n : L3)
    //     std::cout << n << ' ';


    // O(nlogn) complexity
    // std::sort(L1.begin(), L1.end());
    // std::sort(L2.begin(), L2.end());
    // int p=0; int q=0;
    // int len1 = L1.size(); int len2= L2.size();
    // while(p<len1 && q<len2)
    // {
    //   if(L1[p] < L2[q])
    //     L3.push_back(L1[p++]);
    //   else if(L1[p] == L2[q])
    //     {
    //       while(L1[p] == L2[p])
    //         q++;
    //       }
    //   else if (L1[p] > L2[q])
    //   {
    //     //Do something
    //   }
    // }

    // Set L2 to unordered_set() O(n)
    //Constant time
    std::unordered_set<int>L_2(L2.begin(), L2.end());
    for(std::vector<int>::iterator it= L1.begin(); it<L1.end(); it++)
    {
      //This search is Constant time
      if(L_2.find(*it) == L_2.end())
        L3.push_back(*it);
    }
    std::cout << '\n';
    for (int n : L3)
        std::cout << n << ' ';

      std::cout << '\n';
   return 0;
}
