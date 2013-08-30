/*************************************************************
*
*30_ksmall.cpp: the k small number
*auther     : caowg
*Written on : 08/29/13.
*
*************************************************************/

#include <iostream>
#include <set>
#include <stdlib.h>

using namespace std;

void klest_numbers(int * array,int length ,int k)
{
    multiset<int, greater<int> > mset;
    multiset<int ,greater<int> >::iterator msit;
    for (int i = 0; i < length; ++i)
    {
        if(mset.size() < k )
            mset.insert(array[i]);
        else
        {
            msit = mset.begin();
            if(array[i] < *msit)
            {
                mset.erase(msit);
                mset.insert(array[i]);
            }
        }
    }
    for(msit = mset.begin(); msit != mset.end(); msit++)
        cout<<*msit<<" ";
    cout<<endl;
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
    klest_numbers(array,10,4);
}
