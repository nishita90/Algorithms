/*
Given lists L1 and L2,
return a list L3 which contains all the elements in L1
except any that also appear in L2.
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main()
{
    // std::list<int> L1 = {1,2,3,4,5};
    // std::list<int> L2 = {2,5,3,7};
    // std::list<int> L3;
    std::vector<int> L1;
    std::vector<int> L2;
    std::vector<int> L3;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    L1.push_back(5);

    L2.push_back(2);
    L2.push_back(5);
    L2.push_back(3);
    L2.push_back(7);
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
    std::sort(L1.begin(), L1.end());
    std::sort(L2.begin(), L2.end());
    int count = 0;
    for (int i = 0; i<L1.size(); i++)
    {
      if(L1[i] < L2[count])
        L3.push_back(L1[i]);
      if(L1[i] == L2[count])
        count++;
    }
    std::cout << '\n';
    for (int n : L3)
        std::cout << n << ' ';

      std::cout << '\n';
   return 0;
}
