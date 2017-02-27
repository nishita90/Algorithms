/*
Given an image, rotate it by 90 degrees
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
   int image[5][5];

   // Transpose the matrix in place
   for (int i=0; i< (sizeof(image)/sizeof(image[0][0])); i++)
   {
       for(int j=0 ; j<i && j!=i ; j++ )
       {
           image[j][i] = image[j][i] ^ image[i][j];
           image[i][j] = image[j][i] ^ image[i][j];
           image[j][i] = image[j][i] ^ image[i][j];
       }
   }

   //Reverse the columns
   int length = sizeof(image)/sizeof(image[0][0]);
   for (int i=0; i<length; i++)
   {
       for(int j=0; j<(length)/2 ; j++)
       {
           int temp = image[i][j];
           image[i][j] = image[i][length - j - 1];
           image[i][length - j - 1] = temp;
       }
   }
   
   return 0;
}
