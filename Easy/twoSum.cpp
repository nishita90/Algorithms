/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
      std::vector<int> result;
      std::unordered_map<int,int>hashmap;
      for(int i=0; i<nums.size();i++){
        int diff = target - nums.at(i);
        if(hashmap.find(diff) != hashmap.end()){
          result.push_back(hashmap[diff]);
          result.push_back(i);
        }
        hashmap[nums.at(i)] = i;
      }
      return result;
    }
  };
