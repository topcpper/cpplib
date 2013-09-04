/*************************************************************
*
*tvectotate.cpp: : left rotate the vec
*auther     : caowg
*Written on : 04/12/13.
*
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

template<typename T>
void reverse(T * array , int begin ,int end  );

template<typename T>
void rotate(T * array, int distance);

int main(int arg ,char *arv[])
{
    int a[10];
    for(int i = 0 ; i< 10  ; i++)
        a[i] = i ;
    reverse(a,0,3);
    reverse(a,4,9);
    reverse(a,0,9);
    
    for(int i = 0 ; i< 10  ; i++)
        cout<<a[i]<<' ';
    return 0 ;
            
}

template<typename T>
void reverse(T * array , int begin ,int end  )
{
    int j ;
    int array_centre = (begin+end)/2 ;
    int temp ;
    
        
    for(j=begin ; j< array_centre ; j++)
    {
        temp = array[j] ;
        array[j] = array[end-j+begin] ;
        array[end-j+begin] = temp ;
    }
    
}
