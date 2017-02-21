/*
Given lists L1 and L2,
return a list L3 which contains all the elements in L1
except any that also appear in L2.
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    std::list<int> L1 = {1,2,3,4,5};
    std::list<int> L2 = {2,5,3,7};
    std::list<int> L3;
    for (int p  : L1)
    {
        int count = 0 ;
        for (int q : L2 )
        {
            if (p != q)
                count++;
            else
                break;
        }
        if (count == L2.size())
            L3.push_back(p);
    }

    std::cout << '\n';
    for (int n : L3)
        std::cout << n << ' ';

   return 0;
}
