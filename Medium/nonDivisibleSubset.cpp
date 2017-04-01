/*
Given a set,S, of n distinct integers, print the size of a maximal subset,Si,
 of S where the sum of any 2 numbers in S is not evenly divisible by k.

 The first line contains 2 space-separated integers, n and k, respectively.
 The second line contains n space-separated integers (we'll refer to the ith value as ai)
 describing the unique values of the set.
Constraints:
1 <= n <= 10^5
1 <= k <= 100
1 <= ai <= 10^9

*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin>>n>>k;
    vector<int> array(n);
    for(int arr_i=0;arr_i<n; arr_i++){
        cin>> array.at(arr_i);
    }
    std::vector<int> subset(k,0);
    for(int i=0; i< array.size() ; i++){
        subset.at(array.at(i) % k)++;
    }

    for (std::vector<int>::iterator it = subset.begin(); it<subset.end(); it++){
        std::cout<<*it<<" ";
    }

    std::cout<<std::endl;

    int count =0;
    //Special cases :
    // If subset[0] > 0, add 1 to count.
    // If k is even and subset.at(k/2) > 0, add 1 to count.
    // Else regular operation.
    if (subset.at(0) > 0)
        count++;
    if (k%2 == 0 && (subset.at(k/2) > 0))
        count++;

    std::cout<<"!!!"<<count<<std::endl;
    for(int index = 1; index <= k/2; index++){
      while(index != (k-index))
        count += max(subset.at(index),subset.at(k-index));
    }
    std::cout<<count<<std::endl;
    return 0;
}
