/*
LeetCode - Medium
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function
like __builtin_popcount in c++ or in any other language.
*/

// This is using builtin functions of bitset.
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> res(num+1);
        for(int i=0; i<= num; i++){
            std::bitset<64>bin(i);
            res.at(i) = bin.count();
        }
        return res;
    }

};

// This is w/o using builtin functions of bitset.
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> res(num+1,0);
        for(int i=1; i<= num; i++){
            res.at(i) = 1 + res.at(i & (i-1));
        }
        return res;
    }

};

// This is w/o using builtin functions of bitset. Also using even odd
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> res(num+1,0);
        if(num == 0)
            return res;
        res.at(1) = 1;
        for(int i=2; i<= num; i++){
            res.at(i) = res.at(i >> 1) + (i&1); // i>>1 : right shift operator = (i/2)
                                                // i&1 = 1 for odd and 0 for even.
        }
        return res;
    }

};
