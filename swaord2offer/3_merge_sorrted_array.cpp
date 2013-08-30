/*************************************************************
*
*3_merge_sorrted_array.cpp: merge the sored array
*auther     : caowg
*Written on : 07/22/13.
*
*************************************************************/

#include <iostream>

using namespace std;

void merge_array(int * array_a , int len_a, int  * array_b, int len_b)
{
    int i = len_a-1 ;
    int j = len_b-1 ;
    int k = len_a + len_b -1 ;
    
    while(j>=0)
    {
        if(array_a[i]>array_b[j])
        {
            array_a[k] = array_a[i];
            i--;
        }
        
        else
        {
            array_a[k] = array_b[j];
            j--;
        }
        k--;
        
    }
    
    
}



int main(int arg ,char *arv[])
{
    int array_a[100]={1,7,9,12,15,18};
    int array_b[10]={2,3,4,9,10};
    merge_array(array_a,6,array_b,5);
    for (int i = 0; i < 11; ++i)
    {
        cout<<array_a[i]<<endl;
    }
    
        
}
