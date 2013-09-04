/*************************************************************
*
*9_fibonaacci.cpp: get the fibonacci number
*auther     : caowg
*Written on : 07/24/13.
*
*************************************************************/

#include <iostream>

using namespace std;

long fibonacci(int n)
{
    long number_one = 0 ;
    long number_tow = 1;
    int a[2]={0,1};
    if(n<2)
        return a[n];
    long fn;
    
    for (int i = 2; i <= n; ++i)
    {
        fn = number_one + number_tow;
        number_one = number_tow;
        number_tow = fn;
    }
    return fn;
}


int main(int arg ,char *arv[])
{
    int n;
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}
