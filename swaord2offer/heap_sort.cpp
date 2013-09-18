/*************************************************************
*
*heap_sort.cpp: the heap sort
*auther     : caowg
*Written on : 09/18/13.
*
*************************************************************/

#include <iostream>

using namespace std;

// 小顶
void heap_ajust(int * array,int begin,int end)
{
    int temp = array[begin];
    int j = begin << 2;
    for ( j; j <= end; j*=2)
    {
        if(array[j] > array[j+1])
            j++;
        if(temp <= array[j])
            break;
        array[begin]=array[j];
        begin = j;
    }
    array[begin] = temp;
}

void heap_sort(int * array,int length)
{
    
}




int main(int arg ,char *arv[])
    {
        
    }
