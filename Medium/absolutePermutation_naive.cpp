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
*/
// This is the brute force solution. Works for small T and N. Times out for large values
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

vector<int> nextPerm(vector<int> perm){
    int i = perm.size() - 1;
    //find index i for decending subset of integers
    while(i>0 && perm[i-1] > perm[i])
        i--;
    if(i<=0){
        //std::cout<<"No more permutations"<<std::endl;
        return perm;
    }
    // find the next highest int to perm[i-1]
    int j = perm.size() - 1;
    while(j > i && perm[j] <= perm[i-1]){
        j--;
    }
    // swap perm[i-1] and perm[j]
    perm[i-1] = perm[i-1] ^ perm[j];
    perm[j] = perm[i-1] ^ perm[j];
    perm[i-1] = perm[i-1] ^ perm[j];

    // reverse all elements from i to end of number
    j = perm.size() - 1;
    while(i < j){
        perm[i] = perm[i] ^ perm[j];
        perm[j] = perm[i] ^ perm[j];
        perm[i] = perm[i] ^ perm[j];
        i++;
        j--;
    }
    return perm;
}
bool isAbsolute(vector<int> perm, int T){
    int idx = 1;
    for (std::vector<int>::const_iterator i = perm.begin(); i !=perm.end(); ++i){
        int diff = abs(*i - idx);
        if (diff != T)
            return false;
        idx++;
    }
    for (std::vector<int>::const_iterator i = perm.begin(); i !=perm.end(); ++i)
        std::cout << *i << ' ';
    std::cout<<std::endl;
    return true;
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        // Find the next permutation and calculate the absolute condition. Break when condition met.
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 1);
        //for (std::vector<int>::const_iterator i = perm.begin(); i != perm.end(); ++i)
        //    std::cout << *i << ' ';
        // First check if initialized perm is an absolute perm.
        bool isPerm = isAbsolute(perm, k);
        while(!isPerm){
            vector<int>next = nextPerm(perm);
            if(next == perm){
                std::cout<<-1<<std::endl;
                break;
            }
            isPerm = isAbsolute(next, k);
            perm = next;
        }

    }



    return 0;
}
