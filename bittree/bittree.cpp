/*************************************************************
*
*bittree.cpp: it is my impletion of bittree
*auther     : caowg
*Written on : 04/01/13.
*
*************************************************************/
#include <list>
#include <iostream>
#include "bittree.h"
#include <queue>
#include <stack>
#include <string>

using namespace std;

template<typename T>
void bittree<T>:: createBittree( const vector<vectype<T> > &vec)
{
    // the keyword typename is used ，来表明 vector < vectype<T> > :: const_iterator
    // 是个类型，而不是对象
    typename vector< vectype<T> > :: const_iterator itert = vec.begin() ;
    if(itert == vec.end())
        return ;
    queue<Node<T> *> quep;
    
    proot = new Node<T> ;
    Node<T> * ptemp ;
    ptemp = proot ;
    
    proot->data = (*itert).data ;
    proot->left = NULL;
    proot->right = NULL;
    
    quep.push(ptemp);
    itert ++ ;

    while( itert != vec.end() && !quep.empty())
    {
        ptemp = quep.front();
        quep.pop();

        if(ptemp == NULL)
        {
            itert++ ;
            itert++ ;
            continue ;
        }
        
        // left data not null
        if((*itert).isnull == 0 )
        {
            ptemp->left = new Node<T>;
            ptemp->left->left=NULL ;
            ptemp->left->right=NULL ;
            
            ptemp->left->data = (*itert).data;
        }
        else
            ptemp->left = NULL ;
        quep.push(ptemp->left);
        // right data not null
        if(++itert == vec.end())
            break ;
        
        if((*itert).isnull == 0 )
        {
            ptemp->right = new Node<T>;
            ptemp->right->left =NULL ;
            ptemp->right->right = NULL ;
            
            ptemp->right->data = (*itert).data;
        }
        else
            ptemp->right = NULL ;
        quep.push(ptemp->right);
        itert++ ;        
    }
}

template <typename T>
void bittree<T> :: preOrder()
{
    if(proot==NULL)
        return ;
    
    stack<Node<T>* > s;
    Node<T>*  ptemp ;
    s.push(proot) ;
    while(!s.empty())
    {
        ptemp = s.top() ;
        s.pop() ;
        cout<<ptemp->data <<endl;
        if(ptemp->right) s.push(ptemp->right);
        if(ptemp->left) s.push(ptemp->left);
    
    }
}



template <typename T>
void bittree<T> :: inOrder()
{
    if(proot==NULL)
        return ;
    stack<Node<T>* > s;
    Node<T>*  ptemp = proot ;
    while(ptemp || !s.empty())
    {
        if(ptemp)
        {
            s.push(ptemp) ;
            ptemp = ptemp->left;
        }
        else
        {
            ptemp= s.top();
            s.pop() ;
            cout<<ptemp->data <<endl;
            ptemp = ptemp->right;
        }
    }
    
}


void tstatic()
{
    static int a = 0;
    a++;
    cout<<a<<endl;
    
}


int main(int arg ,char *arv[])
{

    // test 
    vector< vectype<int> > vec ;
    vectype<int> node[6] ;
    node[0].data = 1;
    node[0].isnull = 0;

    node[1].data = 2;
    node[1].isnull = 0;
    node[2].data = 3;
    node[2].isnull = 0;
    node[3].data = 4;
    node[3].isnull = 1;
    node[4].data = 5;
    node[4].isnull = 0;
    node[5].data = 6;
    node[5].isnull = 0;
    for(int i = 0 ; i< 6  ;i++)
        vec.push_back(node[i]);
    
    bittree<int> tree ;
    tree.createBittree(vec);
    tree.preOrder();
    tree.inOrder();
    cout<<"begin:"<<endl;
    
    for(int i = 0 ; i<5 ; i++)
        tstatic();
    
    cout<<"begin list:"<<endl;
    Node<int> * head = bitree2list(tree.proot);
    Node<int> * p =head;
    while(p)
    {
        cout<<p->data<<endl;
        p = p->right;
    }
    
        
}
