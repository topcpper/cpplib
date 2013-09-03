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




using namespace std;

bool find_para(Node<int> * root,int f_data1,int f_data2,int data1,int data2,Node<int> * &ppara)
{
    if(root == NULL)
        return 0;
    if(find_para(root->left,f_data1,f_data2,data1,data2,ppara))
        return 1;
    if(find_para(root->right,f_data1,f_data2,data1,data2,ppara))
        return 1;
    if(f_data1 == 1 && f_data2==1)
    {
        ppara = root;
        return 1;
    }
    if(root->data == data1)
        f_data1 = 1;
    if(root->data == data2)
        f_data2 = 1;
    return false;
}


int main(int arg ,char *arv[])
{

    vector< vectype<int> > vec ;
    vectype<int> node[6] ;
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
    for(int i = 0 ; i< 5  ;i++)
        vec.push_back(node[i]);
    
    bittree<int> tree ;
    tree.createBittree(vec);
    tree.preOrder();
    tree.inOrder();
    cout<<endl;
    int f_data1 = 0;
    int f_data2 = 0;
    int data1 = 4;
    int data2 =5;
    Node<int>* ppara;
    
    if(find_para(tree.proot,f_data1,f_data2,data1,data2,ppara))
        cout<<"find it :"<<(*ppara).data <<endl;
    
}
