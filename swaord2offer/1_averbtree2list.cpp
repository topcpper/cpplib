/*************************************************************
*
*1_averbtree2list.cpp: averrage bitree to list
*auther     : caowg
*Written on : 07/17/13.
*
*************************************************************/

#include <iostream>

using namespace std;

template <typename T>
Node<T> * bitree2list(Node<T> * proot)
{
    static Node<T> * temp, * phead=NULL;
    if(proot==NULL)
        return phead;
    bitree2list(proot->left);
    if(phead==NULL)
    {
        phead = proot;
        temp = proot;
    }
    else
    {
        temp->right = proot;
        proot->left = temp;
        temp = proot;
    }
    bitree2list(proot->right);
    return phead;
}


int main(int arg ,char *arv[])
    {
        
    }
