/*************************************************************
*
*kmp.cpp: kmp
*auther     : caowg
*Written on : 09/08/13.
*
*************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

void next(char * patern,int * next_loc)
{
    next_loc[0] = -1;
    next_loc[1] = 0;
    int i =1;
    int j = next_loc[i];
    while(patern[i+1]!='\0')
    {
        if(j==-1 || patern[i]==patern[j])
        {
            next_loc[i+1] = j+1;
            i++;
            j=next_loc[i];
        }
        else
            j = next_loc[j];
    }
}

int kmp_search(char*  source, char * pattern )
{
    int length = strlen(pattern);
    int *next_loc = new int[length];
    int i = 0;
    int j=0;
    next(pattern,next_loc);
    while(source[i]!='\0' && j!= length)
    {
        // 如果source[i]!=pattern[0],j=-1，此时
        // source要迁移以为然后和pattern[0]开始
        // 比较
        if(source[i] == pattern[j] || j==-1)
        {
            i++;
            j++;
        }
        else
            j = next_loc[j];
    }
    if(j==length)
            return i-length;
    return -1;
}

int main(int arg ,char *arv[])
{
    char source[100]="acabaabaabcacaabc";
    char pattern[20]="abaabcacab";
    cout<<kmp_search(source,pattern);
}
