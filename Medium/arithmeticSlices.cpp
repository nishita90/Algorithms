/*
LeetCode
A sequence of number is called arithmetic if it consists of at least three
elements and if the difference between any two consecutive elements is the same.
Example: A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int length = A.size();
        if(length < 3)// Since we want to return number of subsequences that are of length >= 3 only.
            return 0;

        int diff = A.at(1) - A.at(0);
        int count = 2;
        int res=0;
        for (int i=2; i<length; i++){
            if(A.at(i) - A.at(i-1) == diff){
                count++;
            }
            else{
                if(count>2){
                    res += (count*(count -1))/2;
                    res -= (count - 1); //getting rid of sequences of length 2
                }
                count = 2;
                diff = A.at(i) - A.at(i-1);
            }
        }
        // For the last sequence after reaching end of vector A.
        if(count>2){
            res += (count*(count -1))/2;
            res -= (count - 1); //getting rid of sequences of length 2
        }
        return res;
    }
};
