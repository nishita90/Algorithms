/*
Suppose you have N integers from 1 to N.
We define a beautiful arrangement as an array that is constructed by these
N numbers successfully if one of the following is true for the ith
position (1 ≤ i ≤ N) in this array:

1) The number at the ith position is divisible by i.
2) i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

*/

class Solution {
public:
    int count = 0;
    int countArrangement(int N) {
        if (N == 0)
            return 0;
        int used[N+1] = {0};
        helper(N, 1, used);
        return count;
    }

    void helper(int N, int pos, int used[]){
        if(pos > N){
            count++;
            return;
        }

        for(int i=1; i<=N; i++){
            if((used[i] == 0) && (i%pos==0 || pos%i==0)){
                used[i] = 1;
                helper(N, pos+1, used);
                used[i] = 0;
            }
        }
    }
};
