/*************************************************************
*
*heap_sort.cpp: the heap sort
*auther     : caowg
*Written on : 09/18/13.
*
*************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;


inline void  swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print_data(int * array,int length)
{
    for (int i = 0; i < length; ++i)
        cout<<*(array+i)<<" ";
    cout<<endl;
}


// 小顶，降序排序
//下标 从0开始计算
// i 的 leftchild 下标 = 2*i +1,rightchild =2*i+2
void heap_ajust_small(int * array,int begin,int end)
{
    int temp = array[begin];
    int j = begin*2 +1;
    for ( j ; j <= end; j= j*2 +1)
    {
        if(j<end &&  array[j] > array[j+1])
            j++;
        if(temp <= array[j])
            break;
        array[begin]=array[j];
        begin = j;
    }
    array[begin] = temp;
}

// 大顶堆，升序排序
void heap_ajust_large(int * array,int begin,int end)
{
    int temp = array[begin];
    int j = begin*2 +1;
    for ( j ; j <= end; j= j*2 +1)
    {
        if ( j< end &&  array[j] < array[j+1])
            j++;
        if(temp >= array[j])
            break;
        array[begin]=array[j];
        begin = j;
    }
    array[begin] = temp;
}


// 默认升序排列，即调用大顶堆函数
void heap_sort(int * array,int length,bool sort_type=0)
{
    int i;
    typedef void (* func_type) (int * ,int ,int) ; // 函数指针
                                                   // 指向调用函数
    func_type pfunc= heap_ajust_large; // 默认升序
    if(sort_type==1) // 降序
        pfunc=heap_ajust_small;
    
    for ( i = length/2 -1; i >= 0; --i) // 第一次调整
        pfunc(array,i,length-1);
    swap(*array,*(array+length-1));

    for ( i = length-2; i !=0 ; --i) // 依次调整
    {
        pfunc(array,0,i);
        swap(*array,*(array+i));
    }
}



int main(int arg ,char *arv[])
{
    
    int array[10];
    srand(time(0));
    for (int i = 0; i < 10; ++i)
        array[i] = rand()%10;
    print_data(array,10);

    heap_sort(array,10,1);
    print_data(array,10);

    heap_sort(array,10,0);
    print_data(array,10);
    
    return 0;
    
    
        
}
