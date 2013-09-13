/*************************************************************
*
*rotate_str_split.cpp: ..
*auther     : caowg
*Written on : 09/13/13.
*
*************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

void rotate(char *p,char split)
{
    char * begin = p;
    char * end = p;
    for( end ;  *end!= '\0' ; ++end)
    {
        if(*end != split)
            continue;
        else
        {
            reverse(begin,end);
            begin =  end+1;
            end = begin;
        }
    }
    reverse(begin,end); // 翻转最后一个
    reverse(p,end);//整体翻转
}


int main(int arg ,char *arv[])
{
    char str[50]="www.163.com.sports.hahahah";
    rotate(str,'.');
    cout<<str<<endl;
}
