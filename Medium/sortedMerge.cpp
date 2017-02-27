/*
Given two sorted integer arrays array1 and array2, merge array2 into array1 as one sorted array
*/

#include <iostream>

using namespace std;
int* sortedMerge (int arr1[] , int arr2[], int len1, int len2)
{
  int p = 0; int q=0; int k=0;
  int len3 = len1 + len2;
  int *arr3 = new int[len3];
  //First check if any one array is empty. If yes, return non empty
  if (len1 == 0)
    return array2;
  if (len2 == 0)
    return array1;
  //Loop till you run out of one array
  while(p < len1 && q < len2)
    {
      if (arr1[p] < arr2[q])
	     arr3[k++] = arr1[p++];
      else
	      arr3[k++] = arr2[q++];
    }
  //Loop over the remaining elements  
  while(p < len1)
    arr3[k++] = arr1[p++];

  while(q < len2)
    arr3[k++] = arr2[q++];

  return arr3;
}

int main()
{
  // Take arrays as user input with " cin >> "
  int array1[4] = {2,5,7,20};
  int array2[3] = {3,8,15};
  int* array3;
  array3 = sortedMerge(array1,array2,4,3);
  for (int c = 0; c < 7 ; c++)
    std::cout << array3[c] << " ";
  return 0;
}
