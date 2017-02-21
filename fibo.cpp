/*
Write the fibonacci series upto 'num' numbers.
*/
/*
This can also be used in the Climbing stairs problem.
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Solution: Num of ways you can climb = (n+1) value of the fibonacci series.
So if n = 5 (stairs). ways = fibo(6) = 8 (1 1 2 3 5 '8')
*/
#include <iostream>

using namespace std;
//////////////////////////////////////////////////////////////////
// A simple RECURSIVE program to find n'th fibonacci number
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}

// Returns number of ways to reach s'th stair
int countWays(int s)
{
    return fib(s + 1);
}
//////////////////////////////////////////////////////////////////
int main()
{
    // Regular way of calculating fibo.
    int num = 10;
    int first = 0;
    int second = 1;
    int next;
    std::cout << "fibonacci series is :  "
    for (int i =0; i<num; i++)
    {
        next = first + second;
        first = second;
        second = next;
        std::cout << first << ' ';
    }
   std::cout << " " <<std::endl;
   return 0;
}
