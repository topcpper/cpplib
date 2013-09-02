/*************************************************************
*
*34_uglynumber.cpp: ..
*auther     : caowg
*Written on : 08/31/13.
*
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

inline int getlest(int &t2 , int &t3 ,int &t5 ,vector<int>&vec)
{
    int min = (vec[t2]*2 < vec[t3]*3) ? vec[t2]*2: vec[t3]*3;
    min = (min < vec[t5]*5) ? min: vec[t5]*5;
    if(vec[t5]*5 == min)
        t5++;
    if(vec[t3]*3 == min)
        t3++;
    if(vec[t2]*2 == min)
        t2++;
    return min;
}


int getUglynumber(int n)
{
    vector<int> vec;
    int count = 1;
    vec.push_back(1);
    int t2 =0;
    int t3 = 0;
    int t5 = 0;
    cout<<1<<" ";
    while(count<n)
    {
        vec.push_back(getlest(t2,t3,t5,vec));
        cout<<vec[count]<<" ";
        count++;
    }
    cout<<endl;
    return *(vec.rbegin());
}


int main(int arg ,char *arv[])
{
    int n;
    cin>>n;
    cout<<getUglynumber(n);
    
}
