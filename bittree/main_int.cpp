/*************************************************************
*
*main.c: ..
*auther     : caowg
*Written on : 09/04/13.
*
*************************************************************/

#include <iostream>
#include "bittree_int.h"

using namespace std;

int main(int arg ,char *arv[])
{

    // test 
    vector< vectype > vec ;
    vectype node[6] ;
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
    
    bittree tree ;
    tree.createBittree(vec);
    tree.preOrder();
    tree.inOrder();
    cout<<"begin:"<<endl;
    
    cout<<"begin list:"<<endl;
    // Node<int> * head = bitree2list(tree.proot);
    // Node<int> * p =head;
    // while(p)
    // {
    //     cout<<p->data<<endl;
    //     p = p->right;
    // }
    // string str;
}
