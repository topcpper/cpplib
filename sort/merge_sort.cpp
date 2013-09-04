/*************************************************************
*
*merge_sort.cpp: 
*auther     : caowg
*Written on : 09/01/13.
*
*************************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;


void print_data(int * array,int length)
{
    for (int i = 0; i < length; ++i)
        cout<<array[i]<<" ";
    cout<<endl;
}


void merge(int * array,int * copy, int start,int middle,int end)
{
    int i =start;
    int j = middle+1;
    int k = start;
    for (; i <= middle && j<= end;)
    {
        if(array[i]< array[j])
            copy[k]=array[i++];
        else
            copy[k] = array[j++];
        ++k;
    }
    while(i<=middle)
        copy[k++]= array[i++];
    while(j<=end)
        copy[k++]= array[j++];
    for ( i = start; i <= end; ++i)
        array[i] = copy[i];
}


void msort(int * array,int * copy, int start , int end)
{
    int middle;
    if(start != end)
    {
        middle = (start+end)/2;
        msort(array,copy,start,middle);
        msort(array,copy,middle+1,end);
        merge(array,copy,start,middle,end);
    }
}




void merge_sort(int * array,int length)
{
    int *copy= new int[length];
    memcpy(copy,array,length*sizeof(int));
    print_data(copy,length);
    msort(array,copy,0,length-1);
    delete [] copy;
}



int main(int arg ,char *arv[])
{
    int array[11];
    srand(time(0));
    for (int i = 0; i < 11; ++i)
    {
        array[i] = rand()%100;
    }
    print_data(array,11);
    merge_sort(array,11);
    print_data(array,11);
}
