/*************************************************************
*
*35_fist_char_ofstr.cpp: ..
*auther     : caowg
*Written on : 08/31/13.
*
*************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

char get_first_char_of_str(const char * str)
{
    unsigned int times[256];
    for (int i = 0; i < 256; ++i)
        times[i] = 0;
    vector<char> vec;
    char * p = const_cast<char*> (str);
    while(*p != '\0')
    {
        if(times[*p] == 0)
            vec.push_back(*p);
        times[*p]++;
        p++;
    }
    for (vector<char> :: iterator it = vec.begin(); it !=vec.end(); ++it)
    {
        if(times[*it] == 1)
            return *it;
    }
    return '\0';
}


int main(int arg ,char *arv[])
    {
        string str;
        cin>>str;
        cout<<get_first_char_of_str(str.c_str());
    }
