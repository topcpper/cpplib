/*************************************************************
*
*whole_Permutation.cpp: tt
*auther     : caowg
*Written on : 10/01/13.
*
*************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>


using namespace std;


void whole_permutation(string& str,int first)
{
    if(first == str.size())
        return ;
    for (int i = first; i < str.size(); ++i)
    {
        swap(str[i],str[first]);
        if(first+1 == str.size())
            cout<<str<<endl;
        whole_permutation(str,first+1);
        swap(str[i],str[first]);
    }
}

void whole_permutation(char * pstr,int first,int length)
{
    if(first == length)
        return ;
    for (int i = first; i < length; ++i)
    {
        swap(pstr[i],pstr[first]);
        if(first+1 == length)
        {
            for (int i = 0; i < length; ++i)
                cout<<*(pstr+i);
            cout<<endl;
        }
        
        whole_permutation(pstr,first+1,length);
        swap(pstr[i],pstr[first]);
    }
}


void _choose_length_ofn(char * pt, int first,int length,int num,string & str)
{
    if(length - first < num)
        return ;
    if(num == 0)
    {
        cout<<str<<endl;
        return ;
    }
    str.push_back(*(pt+first));
    _choose_length_ofn(pt,first+1,length,num-1,str);
    if(str.size()>0)
        str.erase(str.end()-1);
    _choose_length_ofn(pt,first+1,length,num,str);
}


void power_set(char * pt)
{
    string str;
    int length = strlen(pt);
    for (int i = 1; i <= length; i++)
    {
        str.clear();
        _choose_length_ofn(pt,0,length,i,str);
    }
}



int main(int arg ,char *arv[])
    {
        string str="abcd";
        char pstr[6]="abcdf";
        
        whole_permutation(str,0);
        cout<<"other:"<<endl;
        
        whole_permutation(pstr,0,4);

        power_set(pstr);
        
        
    }
