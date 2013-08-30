/*************************************************************
*
*10_numberof1.cpp: count the number of 1 
*auther     : caowg
*Written on : 07/24/13.
*
*************************************************************/

#include <iostream>

using namespace std;

int get1number(int n)
{
    unsigned  int flag = 1;
    int count = 0;
    
    while(flag)
    {
        if(n&flag)
            count++;
        flag = flag << 1;
        
    }
    return count;
    
    
}

int get1number_1(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n = (n-1)& n;
    }
    return count;
}


int main(int arg ,char *arv[])
{
    cout<<get1number(3)<<endl;
    cout<<get1number(-1)<<endl;
    cout<<get1number(-2)<<endl;
    cout<<get1number_1(-2)<<endl;
    cout<<get1number_1(3)<<endl;
        
}
