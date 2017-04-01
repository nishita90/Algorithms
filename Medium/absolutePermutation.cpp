/*
We define P to be a permutation of the first  natural numbers in the range(1,N).
Let pos_i denote the position of i in permutation P(please use -based indexing).
P is considered to be an absolute permutation if  holds true for every .
Given N and K, print the lexicographically smallest absolute permutation,P ;
if no absolute permutation exists, print -1.

Input Format:
The first line of input contains a single integer,T, denoting the number of test cases.
Each of the  subsequent lines contains  space-separated integers describing the
respective N and K values for a test case.

Constraints:
1 <= T <= 10
1 <= N <= 10^5
1 <= K <= N

Output Format:
On a new line for each test case, print the lexicographically smallest absolute permutation;
if no absolute permutation exists, print -1.

Complexity: O(n)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 1);
        //Consider special cases
        if(k == 0){
          //print the initialized vector itself - that is the permutation that
          // gives abs difference as 0.
          for(std::vector<int>::iterator it = perm.begin(); it<perm.end(); it++)
            std::cout<< *it << " ";
        }
        else if ((n % (2*k)) != 0)
          std::cout<<-1;
        else{
            std::vector<int> next;
            bool add = true;
            for(int i=1; i<=n; i++){
                if(add){
                    next.push_back(i+k);
                }
                else
                    next.push_back(i-k);
                if(i%k == 0)
                    if (add)
                        add = false;
                    else
                        add = true;
             }
            for(std::vector<int>::iterator it = next.begin(); it<next.end(); it++)
                std::cout<< *it << " ";
            }
        std::cout<<std::endl;
    }
    return 0;
}
