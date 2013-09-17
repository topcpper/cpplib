/*************************************************************
*
*badhorse.cpp: tt
*auther     : caowg
*Written on : 09/14/13.
*
*************************************************************/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct line
{
    string str1;
    string str2;
    bool mark;
};



bool  _deal(line & temp, vector<string>vec[2] ,
            int vec_0_or_1,vector<string>::iterator& it,int &count)
{
    if(temp.str1 == *it)
    {
        if(find(vec[vec_0_or_1].begin(),vec[vec_0_or_1].end(),temp.str2)
           != vec[vec_0_or_1].end() )
            return 0;
        else
        {
            if(find(vec[1-vec_0_or_1].begin(),vec[1-vec_0_or_1].end(),temp.str2)
                == vec[1-vec_0_or_1].end())
               vec[1-vec_0_or_1].push_back(temp.str2);
        }
        
        temp.mark =1;
        count++;
    }
    else if(temp.str2 == *it)
    {
        if(find(vec[vec_0_or_1].begin(),vec[vec_0_or_1].end(),temp.str1)
           != vec[vec_0_or_1].end() )
            return 0;
        else
        {
            if(find(vec[1-vec_0_or_1].begin(),vec[1-vec_0_or_1].end(),temp.str1)
                == vec[1-vec_0_or_1].end())
            vec[1-vec_0_or_1].push_back(temp.str1);
        }
        
        temp.mark =1;
        count++;
    }
    return 1;
}

void print_data(vector<string> vecs[2])
{
    cout<<"begin 0:"<<endl;
    int i;
    for ( i = 0; i < vecs[0].size(); ++i)
        cout<<vecs[0][i]<<" ";
    cout<<endl;
    for ( i = 0; i < vecs[1].size(); ++i)
        cout<<vecs[1][i]<<" ";
    cout<<endl;
}



bool split_sucess(vector<line> & vecline)
{
    vector<string> vecs[2];
    vecs[0].reserve(200);
    vecs[1].reserve(200);
    int count = 1;
    line temp;
    temp = *(vecline.begin());
    (*vecline.begin()).mark = 1;
    
    vecs[0].push_back(temp.str1);
    vecs[1].push_back(temp.str2);
    vector<string>::iterator ita = vecs[0].begin();
    vector<string>::iterator itb = vecs[1].begin();
    bool veca_turn = 1;
    bool vecb_turn = 0;
    int i;
    
    while(count < vecline.size())
    {
//        cout<<"count:"<<count<<endl;
        
        if(veca_turn == 1)
        {
            for (ita;  ita != vecs[0].end(); )
            {
                for ( i = 0; i < vecline.size(); ++i)
                {
                    if(vecline[i].mark == 1)
                        continue;
                    if(_deal(vecline[i],vecs,0,ita,count)==0)
                    {
//                print_data(vecs);
                        return 0;
                    }

                }
                ++ita;
            }
            veca_turn = 0;
            vecb_turn = 1;
        }

        if(vecb_turn == 1)
        {
            for (itb;  itb != vecs[1].end(); )
            {
                for ( i = 0; i < vecline.size(); ++i)
                {
                    if(vecline[i].mark == 1)
                        continue;
                    if(_deal(vecline[i],vecs,1,itb,count)==0)
                    {
//                print_data(vecs);
                        return 0;
                    }

                }
                ++itb;
            }
            veca_turn = 1;
            vecb_turn = 0;
        }
        
        if(ita == vecs[0].end() && itb == vecs[1].end())
        {
            for ( i = 0; i < vecline.size(); ++i)
            {
                if(vecline[i].mark == 1)
                    continue;
                vecs[0].push_back(vecline[i].str1);
                vecs[1].push_back(vecline[i].str2);
                vecline[i].mark = 1;
                count++;
                break;
            }
        }
    }//endwhile
//    print_data(vecs);
    return 1;
}




int main(int arg ,char *arv[])
{
    string inputfile("input");
    string outputfile("output");

    ifstream ifile;
    ifile.open(inputfile.c_str());

    ofstream ofile;
    ofile.open(outputfile.c_str());
    
    
    int case_num ;
    ifile>>case_num;
    int lines;

    vector<line> vecline;
    vecline.reserve(200);
    
    
    int line_number =0;
    line temp;
    
    for(int i = 0  ; i<case_num ;i++)
    {
        ifile>>lines;
        vecline.clear();
        line_number = 0;
        while(line_number< lines)
        {
            ifile>>temp.str1;
            ifile>>temp.str2;
            temp.mark = 0;
            vecline.push_back(temp);
            line_number++;
        }
        if(split_sucess(vecline))
            ofile<<"Case #"<<i+1<<": Yes"<<endl;
        else
            ofile<<"Case #"<<i+1<<": No"<<endl;
    }
}
