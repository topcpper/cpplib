/*************************************************************
*
*3_insteadch_str.cpp: instead the very char to other string
*auther     : caowg
*Written on : 07/22/13.
*
*************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

void instead_char(char * str , char schar, const char * str1)
{
    int length = strlen(str);
    int number_schar = 0 ;
    char * p = str;
    int i = 0 ;
    
    while(p[i]!= '\0')
    {
        if (p[i]==schar)
            number_schar++;
        i++;
    }
    cout<<number_schar<<endl;
    
    p = str + length;
    char * p2 = str + length+ number_schar*(strlen(str1)-1);
    
    int str1_len = strlen(str1);
    
    while(p2 != p)
    {
        if(*p == schar)
        {
            for (int j = str1_len-1; j >= 0; --j)
            {
                *p2 = str1[j];
                p2--;
            }
            --p;
        }
        else
        {
            *p2 = *p;
            p2--;
            p--;
        }
        cout<<*p<<", "<<*p2<<endl;

        
    }
    
}


int main(int arg ,char *arv[])
{
    char str[100]="haha wo men chi";
    instead_char(str,' ',"%20");
    cout<<str<<endl;
    return 0;
}

