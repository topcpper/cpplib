/*************************************************************
*
*8_find_min.cpp: find the minix number of the array,the array is rotated
*auther     : caowg
*Written on : 07/23/13.
*
*************************************************************/

#include <iostream>

using namespace std;

int search_min(int * a ,int len)
{
    int low = 0 ;
    int high = len-1;
    int mid;
    int min = a[len-1];
    
    while(low<= high)
    {
        mid = (low+high)/2;
        if(a[mid] < min)
        {
            min = a[mid];
            high = mid -1 ;
        }
        else  (a[mid] > min)
            low = mid +1;
        // else // a[min] = min
        // {
        //     if (a[low] < min)
        //     {
        //         high = mid -1 ;
        //     }
        //     else if (a[low] > min)
        //     {
                
        //     }
            
        // }
        
    }
    return min;
    
}

int search_max(int * a,int len)
{
    int low = 0 ;
    int high = len-1;
    int mid;
    int max = a[len-1];
    
    while(low<= high)
    {
        mid = (low+high)/2;
        if(a[mid] >= max)
        {
            max = a[mid];
            low = mid +1 ;
        }
        else
            high = mid -1 ;
    }
    return max;
}



int main(int arg ,char *arv[])
{
    // int a[10]={9,10,1,2,3,4,5,6,7,8};
    // int a[10]={1,1,1,1,1,1,1,1,0,1}; // <= error
    // 有重复数据的时候会出错
    int a[10]={1,0,1,1,1,1,1,1,1,1}; // < error
    cout<<search_min(a,10)<<endl;
    cout<<search_max(a,10);
    return 0;
    
    
}
