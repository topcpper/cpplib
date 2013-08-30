/*************************************************************
*
*31_greatest_sumof_sub_array.cpp: find the greatest sum of the sub array
*auther     : caowg
*Written on : 08/30/13.
*
*************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void find_greatest_sum_of_subarray(int * array, int length,vector<int> & vec,int & sum)
{
    vector<int> nvec;
    sum = -9999999;
    int nsum = 0;
    
    for (int i = 0; i < length; ++i)
    {
        if(nsum <= 0)
        {
            nsum = array[i] ;
            nvec.clear();
            nvec.push_back(array[i]);
        }
        else
        {
            nsum+= array[i];
            nvec.push_back(array[i]);
        }
        if(nsum > sum)
        {
            sum = nsum;
            vec = nvec;
        }
    }
}


int main(int arg ,char *arv[])
{
    int array[12];
    array[0] = 1;
    array[1] = -2;
    array[2] = 0;
    array[3] =3;
    array[4] = 10;
    array[5] = -4;
    array[6] =-2;
    array[7] = -3;
    array[8] = 5;
    array[9] = -2;
    array[10] = 8;
    array[11] = -30;
    array[12] =20;
    int sum;
    vector<int> vec;
    find_greatest_sum_of_subarray(array,12,vec,sum);
    cout<<sum<<endl;
    vector<int> ::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}
