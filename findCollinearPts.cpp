/*
Write function to find collinear points
*/
#include <iostream>

using namespace std;
bool isCollinear(int x1 , int x2, int x3, int y1, int y2, int y3)
{
    return ((y2-y1)*(x2 - x3) == (x2 - x1)*(y2 - y3));
}

int main()
{
   int x1 , x2,  x3,  y1,  y2,  y3;
   x1 = y1 = 1;
   x2 = y2 = 2;
   x3 = y3 = 3;
    bool isColl = isCollinear(x1,x2,x3,y1,y2,y3);
    std::cout << "isCollinear ?? " << isColl << std::endl;
   return 0;
}
