/*
Given an array sort using insertion sort algorithm.
*/
#include <iostream>

using namespace std;
void insertion_sort(int array[] , int length)
{
    int value, i;
    //Start from second element.
    for (int index=1; index < length ; index++)
    {
        value = array[index];
        i = index - 1;
        while (i >= 0 && (value < array[i]))
        {
                array[i+1] = array[i];
                array[i] = value;
                //For swapping in place:
                //array[i+1] = array[i+1] ^ array[i];
                //array[i]   = array[i+1] ^ array[i];
                //array[i+1] = array[i+1] ^ array[i];
                i--;
        }

    }
}
int main()
{
   cout << "Hello World" << endl;
   int a[5]= {2,1,4,9,3};
   insertion_sort(a,5);
   for(int i =0 ; i < 5; i++)
        std::cout << a[i] << " ";

    std::cout << "\n";
   return 0;
}
