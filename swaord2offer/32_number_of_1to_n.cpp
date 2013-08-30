/*************************************************************
*
*32_number_of_1to_n.cpp: ..
*auther     : caowg
*Written on : 08/30/13.
*
*************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;

int Numberof1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n%10 == 1)
            number++;
        n = n/10;
    }
    return number;
}


int numberof1_between1andn(unsigned int n)
{
    int number = 0;
    for (int i = 1; i <= n; ++i)
    {
        number+= Numberof1(i);
    }
    return number;
}


// methond2


int PowerBase10(unsigned int n)
{
    int result =1;
    for (unsigned int i=0; i < n; ++i)
    {
        result *= 10;
    }
    return result;
}


int Numberof1_(const char * strN)
{
    int first = *strN -'0';
    unsigned int length = static_cast<unsigned int > (strlen(strN));

    if(length ==1 && first ==0)
        return 0;
    if(length ==1 && first >0)
        return 1;
    
    
    int numFirstDigit = 0;
    if(first >1)
    {
        numFirstDigit = PowerBase10(length -1);
    }
    else if(first ==1)
    {
        numFirstDigit = atoi(strN+1) +1;
    }
    int numOtherDigits = first * (length -1)* PowerBase10(length-2);
    int numRecursive = Numberof1_(strN +1);
    return numFirstDigit + numOtherDigits + numRecursive;
}


int numberof1between1_to_n(unsigned int n)
{
    if(n<=0)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);
    return Numberof1_(strN);
}





int main(int arg ,char *arv[])
    {
        int n = 0;
        cin>>n;
        
        
        cout<< numberof1_between1andn(n)<<endl;
        cout<< numberof1between1_to_n(n)<<endl;
    }
