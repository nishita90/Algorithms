/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
log n means binary search!!!!!
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      while(left < right){
          int mid = left + ((right-left)/2);
          // EVEN
          if ( mid % 2 == 0 ){
              if(nums.at(mid) == nums.at(mid - 1)) right = mid - 2;
              else if(nums.at(mid) == nums.at(mid + 1)) left  = mid + 2;
              else return nums.at(mid);
          }
          // ODD
          else{
              if(nums.at(mid) == nums.at(mid - 1)) left  = mid + 1;
              else if(nums.at(mid) == nums.at(mid + 1)) right = mid - 1;
              //you never have this next case cause if mid is odd, both sides of
              // mid will have odd number of ints which means that nums[mid] will
              // never be the single val
              //else return nums.at(mid);
          }
      }
      return nums.at(left);
    }
};
