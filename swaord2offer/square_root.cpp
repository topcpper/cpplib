/*************************************************************
*
*square_root.cpp: 
*auther     : caowg
*Written on : 09/18/13.
*
*************************************************************/

#include <iostream>

using namespace std;

double square_root(double n,double accuracy)
{
    double begin = 0;
    double end = n;
    double mid =(begin+end)/2;
    double lastmid=1;
    while(lastmid -mid > accuracy || mid -lastmid > accuracy)
    {
        lastmid = mid;
        if(mid*mid > n)
            end = mid;
        else
            begin = mid;
        mid = (begin+end)/2;

    }
    return mid;
    
}


double square_root1(double n,double accuracy)
{
    double begin = 0;
    double end = n;
    double mid =(begin+end)/2;
    double lastmid=1;
    while(mid*mid -n > accuracy*accuracy || n-mid*mid > accuracy*accuracy)
    {
        if(mid*mid > n)
            end = mid;
        else
            begin = mid;
        mid = (begin+end)/2;
    }
    return mid;
    
}



int main(int arg ,char *arv[])
{
    for (int i = 5; i < 10; ++i)
    {
        cout<<i<<" "<<square_root(i,0.0001)<<endl;
    }

    for (int i = 5; i < 10; ++i)
    {
        cout<<i<<" "<<square_root1(i,0.0001)<<endl;
    }
}
