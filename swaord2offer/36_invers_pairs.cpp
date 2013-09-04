/*************************************************************
*
*36_invers_pairs.cpp: ..
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


int merge(int * array,int * copy, int start,int middle,int end)
{
    int i =middle;
    int j = end;
    int k = end;
    int count = 0;
    for (; i >= start && j> middle ; )
    {
        if(array[i] > array[j])
        {
            count+= j-middle;
            copy[k]=array[i--];
        }
        else
            copy[k] = array[j--];
        --k;
    }
    while(i>=start)
        copy[k--]= array[i--];
    while(j>middle)
        copy[k--]= array[j--];
    for ( i = start; i <= end; ++i)
        array[i] = copy[i];
    return count;
}


void msort(int * array,int * copy, int start , int end,int & count)
{
    int middle;
    if(start != end)
    {
        middle = (start+end)/2;
        msort(array,copy,start,middle,count);
        msort(array,copy,middle+1,end,count);
        count += merge(array,copy,start,middle,end);
    }
}




int merge_sort(int * array,int length)
{
    int *copy= new int[length];
    memcpy(copy,array,length*sizeof(int));
    print_data(copy,length);
    int count=0;
    msort(array,copy,0,length-1,count);
    delete [] copy;
    return count;
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
    cout<<"pairs:"<<merge_sort(array,11)<<endl;
    print_data(array,11);
}
