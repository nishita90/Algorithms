/*
LeetCode
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only
one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
// One way to solve is to sort and then scan. Time complexity = O(nlogn) for sorting
//                                                        and   O(n) for scanning.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())
            return 0;
        std::sort(nums.begin(),nums.end());
        for(std::vector<int>::iterator it = nums.begin(); it < nums.end(); it++){
            if(*it == *(it+1))
                return *it;
        }
    }
};

// O(n) soution: 
