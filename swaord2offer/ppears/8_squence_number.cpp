/*************************************************************
*
*8_squence_number.cpp: 
*auther     : caowg
*Written on : 09/12/13.
*
*************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int who_min_to_numer(int data1, int data2, int number)
{
    int temp1 = (data1 - number)>0? (data1 -number): (number - data1);
    int temp2 = (data2 -number) > 0? (data2 - number) : (number -data2);
    return temp1 < temp2 ? data1 : data2;
}

// 平方算法
int find_min_to_number(int * array,int length ,int number)
{

    int sum = 0;
    int approximation = 9999;
    int begin = 0;
    int end = 0;
    for (int i = 0; i < length; ++i)
    {
        sum = 0;
        for (int j = i ; j < length; ++j)
        {
            sum += array[j];
            approximation = who_min_to_numer(approximation,sum,number);
            if(approximation == sum)
            {
                begin = i;
                end = j;
            }
        }
    }
    cout<<approximation<<endl;
    cout<<"begin:"<<begin<<"end:"<<end<<endl;
}

// nlogn 算法
inline int abs(int data)
{
    return data>0? data:0-data;
}


int find_min_to_number(vector <int> & vec, int number)
{
    vector<int> vecsum;
    vector<int> ::iterator it = vec.begin();
    int sum = 0;

    // sum
    for (it ; it != vec.end(); ++it)
    {
        sum+= *it;
        vecsum.push_back(sum);
    }
    // back_up
    vector<int> vecsum_un_sort(vecsum);
    // sort
    sort(vecsum.begin(),vecsum.end());

    // max
    int approximation = 9999;

    it = vecsum.begin();
    vector<int> ::iterator itend = vecsum.end();
    itend--;
    vector<int>::iterator itbegin ;
    vector<int>::iterator mid;

    vector<int>::iterator lbegin= it ;
    vector<int>::iterator lend = it ;

    int temp;
    int steps;
    bool flag_equal = 0;
    for (it ; it != vecsum.end() && flag_equal != 1; ++it)
    {
        itbegin = it;
        itend = vecsum.end();
        itend--;
        while(itbegin!=itend)
        {
            steps = itend - itbegin;
            mid = itbegin+steps/2;
            temp = *mid - *it -number;
            if(abs(temp)< abs(approximation))
            {
                lbegin = it;
                lend = mid;
                approximation = temp;
            }
            
            if(temp ==0)
            {
                flag_equal = 1;
                break;
            }
            else if (temp < 0)
                itbegin = mid + 1;
            else
                itend = mid -1;
        }
    }
    cout<<approximation+number<<endl;
    // find the begin sum & end sum int the backup_sum
    itbegin = vecsum_un_sort.end();
    itend = vecsum_un_sort.end();
    for(it = vecsum_un_sort.begin() ; it != vecsum_un_sort.end() ; ++it)
    {
        if(itbegin != vecsum_un_sort.end() && itend != vecsum_un_sort.end())
            break;
        if(*it == *lbegin)
            itbegin = it;
        if(*it == *lend )
            itend = it;
    }
    // print
    itbegin = vec.begin()+( itbegin - vecsum_un_sort.begin()) +1;
    itend = vec.begin() + (itend - vecsum_un_sort.begin());
    for(it = itbegin ;it != itend ; ++it)
        cout<<*it<<" ";
    cout<<*it<<endl;
}




int main(int arg ,char *arv[])
{
    int array[10] ;
    int data;
    int i = 0;
    vector<int> vec ;
    
    for ( i = 0; i < 10; ++i)
    {
        cin>>data;
        if(data == -9999)
            break;
        array[i] = data;
        vec.push_back(data);
    }
    int number;

    cin>>number;
    
    find_min_to_number(array,i,number);

    find_min_to_number(vec,number);
}


