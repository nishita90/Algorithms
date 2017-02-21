/*
Given an image, return the median-filtered image with kernel size k.
*/
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
    int k; //filter size : k = 3 for 3x3 filter 
    std::cout << "Enter size of median filter : " << std::endl;

    std::cin >> k;

    cv::Mat src = imread("input.jpg");
    int lim = k/2;
    cv::Mat filtered_img;

    std::vector<int> arr_sort;
    for (int rows= lim; rows < src.rows - lim ; rows++ )
    {
        for (int cols = lim; cols < src.cols - lim ; cols++)
        {
            for (int i=0; i<k; i++)
            {
                 for (int j=0; j<k; j++)
                {
                     arr_sort.append(src.at(rows - 1 + i )(cols - 1 + j));
                }
            }
            std::sort(arr_sort.begin(),arr_sort.end());
            filtered_img.at(rows)(cols) = arr_sort.at((k+1));
        }
    }


   return 0;
}
