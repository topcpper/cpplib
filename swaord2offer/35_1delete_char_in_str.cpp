/*************************************************************
*
*35_1delete_char_in_str.cpp: 产出重复元素
*auther     : caowg
*Written on : 08/31/13.
*
*************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

void delete_char_in_str( char * str, const char * str1)
{
    bool hash_table_str[256];
    for (int i = 0; i < 256; ++i)
        hash_table_str[i]=0;
    const char * p = str1;
    for (p; *p != '\0'; ++p)
        hash_table_str[*p]=1;
    char *pd = str;
    char *pchar = str;
    for (p=str; *p != '\0'; ++p)
    {
        if(hash_table_str[*p]==0)
        {
            *pd = *p;
            pd++;
        }
    }
    *pd = '\0';
}

void delete_duplite_char(char * str)
{
    bool hash_table_str[256];
    for (int i = 0; i < 256; ++i)
        hash_table_str[i]=0;
    char *pd = str;
    for(str; *str!= '\0' ;++str)
    {
        if(hash_table_str[*str]==0)
        {
            hash_table_str[*str]=1;
            *pd = * str;
            pd++;
        }
    }
    *pd = '\0';
}


void delete_duplite_number(vector<int> &ivec)
{
    set<int> iset;
    vector<int> :: iterator itd = ivec.begin() ;
    vector<int> :: iterator it = ivec.begin() ;
    for(it; it!= ivec.end();++it)
    {
        if(iset.count(*it)== 0)
        {
            *itd = *it;
            itd++;
            iset.insert(*it);
        }
    }
    ivec.erase(itd,ivec.end());
}

void print_vec(vector<int> &ivec)
{
    vector<int> :: iterator it = ivec.begin() ;
    for(it; it!= ivec.end();++it)
        cout<<*it<<" ";
    cout<<endl;
}



int main(int arg ,char *arv[])
    {
        // char str[100]={0};
        // string str0;
        // string str1;
        
        // cout<<"please input the source string:";
        // getline(cin,str0);
        // cout<<"please input the filter string:";
        // getline(cin,str1);
        
        // strcpy(str,str0.c_str());
        // delete_char_in_str(str,str1.c_str());
        // cout<<str<<endl;

        // string s2;
        // getline(cin,s2);
        // char str2[100];
        // strcpy(str2,s2.c_str());
        // cout<<str2<<endl;
        // delete_duplite_char(str2);
        // cout<<str2<<endl;

        vector<int> ivec;
        ivec.push_back(1);
        ivec.push_back(8);
        ivec.push_back(2);
        ivec.push_back(5);
        ivec.push_back(2);
        ivec.push_back(6);
        ivec.push_back(3);
        ivec.push_back(5);
        ivec.push_back(8);
        ivec.push_back(8);
        ivec.push_back(9);
        print_vec(ivec);
        delete_duplite_number(ivec);
        print_vec(ivec);
        
    }
