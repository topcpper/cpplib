/*************************************************************
*
*2_array_asc.cpp: the search of asc array
*auther     : caowg
*Written on : 07/18/13.
*
*************************************************************/

#include <iostream>

using namespace std;

bool _search(int  a[4][4] ,int row ,int col,int number)
{
    int cur_row = 0 ;
    int cur_col = col -1 ;
    int mark = 0 ;
    for (cur_row = 0 ,cur_col = col-1; cur_row < row && cur_col > -1 ; )
    {
        if(a[cur_row][cur_col] > number )
            cur_col--;
        else if (a[cur_row][cur_col] < number )
                cur_row++;
        else
        {
            mark = 1;
            break;
        }
                
    }
    return mark;
    
}

bool _search1(int  * a ,int row ,int col,int number)
{
    int cur_row = 0 ;
    int cur_col = col -1 ;
    int mark = 0 ;
    for (cur_row = 0 ,cur_col = col-1; cur_row < row && cur_col > -1 ; )
    {
        if(a[cur_row*col+cur_col] > number )
            cur_col--;
        else if (a[cur_row* col +cur_col] < number )
                cur_row++;
        else
        {
            mark = 1;
            break;
        }
                
    }
    return mark;
    
}

int main(int arg ,char *arv[])
    {
        int a[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
        for (int i = 0; i < 16; ++i)
        {
            if(_search(a,4,4,i))
            cout<<"find it "<<i<<endl;
            if(_search1(&a[0][0],4,4,i))
            cout<<"find it "<<i<<endl;
        }

        return 0;
        
    }



