/*
LeetCode
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?
Example: Input:
        [4,3,2,7,8,2,3,1]
        Output:
        [2,3]
*/

// This runs in O(nlogn) because of the sort function.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> result;
        for(std::vector<int>::iterator it = nums.begin(); it < nums.end(); it++){
            if(*it == *(it+1))
                result.push_back(*it);
        }
        return result;
    }
};

// This runs in O(n) time.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> result;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if((nums.at(i) % (n+1)) == n)
                nums.at(0) += (n+1);
            else
            nums.at((nums.at(i) % (n+1))) += (n+1);
        }
        for(int i=0; i<n; i++){
            if((nums.at(i)/(n+1)) > 1){
                if(i == 0)
                    result.push_back(n);
                else
                    result.push_back(i);
            }
        }
        return result;
    }
};
