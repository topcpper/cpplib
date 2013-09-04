/*************************************************************
*
*50_first_para.cpp: ..
*auther     : caowg
*Written on : 09/03/13.
*
*************************************************************/

#include <iostream>
#include "bittree.h"
#include <vector>
#include <deque>

using namespace std;

bool path_search_of_bitree(int data,Node<int>* root,deque<Node<int> * > &deq)
{
    if(root == NULL)
        return 0;
    deq.push_back(root);
    if(root->data == data)
        return 1;
    if(path_search_of_bitree(data,root->left,deq) == 1)
        return 1;
    if(path_search_of_bitree(data,root->right,deq) == 1)
        return 1;
    deq.pop_back();
    return 0;
}

bool find_fist_rara(Node<int>* root,int data1,int data2,int &first_para)
{
    deque< Node<int> * > deq;
    deque< Node<int> * > deq1;
    deque< Node<int> * > ::iterator it;
    
    if(path_search_of_bitree(data1,root,deq) != 1)
        return 0;
    if(path_search_of_bitree(data2,root,deq1) != 1)
        return 0;
    
    Node<int>* last = *(deq.begin());
    while(!deq1.empty() && !deq.empty())
    {
        if(*deq1.begin() == * deq.begin())
        {
            last = *(deq1.begin());
            deq1.pop_front();
            deq.pop_front();
        }
        else
            break;
    }
    first_para = (*last).data;
    return 1;
}



int main(int arg ,char *arv[])
{

    vector< vectype<int> > vec ;
    vectype<int> node[12] ;
    node[0].data = 1;
    node[0].isnull = 0;

    node[1].data = 2;
    node[1].isnull = 0;
    node[2].data = 3;
    node[2].isnull = 0;
    node[3].data = 4;
    node[3].isnull = 0;
    node[4].data = 5;
    node[4].isnull = 0;
    node[5].data = 6;
    node[5].isnull = 0;
    node[6].data = 7;
    node[6].isnull = 0;
    node[7].data = 8;
    node[7].isnull = 0;
    node[8].data = 9;
    node[8].isnull = 0;
    node[9].data = 10;
    node[9].isnull = 0;
    node[10].data = 11;
    node[10].isnull = 0;
    node[11].data = 12;
    node[11].isnull = 9;
        

    for(int i = 0 ; i< 11  ;i++)
        vec.push_back(node[i]);
    
    bittree<int> tree ;
    tree.createBittree(vec);
    cout<<"pre:"<<endl;
    
    tree.preOrder();
    cout<<"in order:"<<endl;
    tree.inOrder();
    cout<<endl;
    int f_data1 = 0;
    int f_data2 = 0;
    cout<<"please input tow datas:";
    
    int data1 = 4;
    int data2 =6;
    cin>>data1;
    cin>>data2;
    Node<int>* ppara=0;
    int para=0;
    if(find_fist_rara(tree.proot,data1,data2,para))
        cout<<"find it:"<<para<<endl;
    
}
