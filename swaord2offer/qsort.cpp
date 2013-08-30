/*************************************************************
*
*qsort.cpp: qsort
*auther     : caowg
*Written on : 08/29/13.
*
*************************************************************/

#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;


void init_array(int * array, int low, int high)
{
    int temp ;
    int middle = (low+high)/2;
    if( array[middle] > array[high]) // middle < high
        swap(array[middle],array[high]);
    if( array[low] < array[middle])
        swap(array[middle],array[low]);
    else
    {
        if( array[low] > array[high])
            swap(array[high],array[low]);
    }
}



int partition(int * array ,int low, int high)
{
    init_array(array,low,high);
    int pivotkey = array[low];
    while(low < high)
    {
        while(low < high && array[high] >= pivotkey)
            --high;
        array[low] = array[high];
        while(low < high && array[low] <= pivotkey)
            ++low;
        array[high] = array[low];
    }
    array[low] = pivotkey;
    return low;
}

void my_qsort(int * array ,int low ,int high)
{
     if( low < high)
    {
        int index = partition(array,low,high);
        my_qsort(array,low, index-1);
        my_qsort(array,index+1,high);
    }
}




int main(int arg ,char *arv[])
{
    int array[10];
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        array[i] = rand()%10;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    my_qsort(array,0,9);
    for (int i = 0; i < 10; ++i)
    {
        cout<<array[i]<<" ";
    }
}
