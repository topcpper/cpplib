#ifndef BITTREE_H
#define BITTREE_H

#include <vector>
#include <list>
#include <iostream>
#include "bittree.h"
#include <queue>
#include <stack>
#include <string>

using namespace std;

/* the node of the tree */
template<typename T>
struct Node
{
     Node * left ; /* point to left */
     Node * right ; /* point to right */
     T data; /* data  */
};

/* the container type of the tempopary data array */
template<typename T>
struct vectype
{
     T data ;
     bool isnull ;
};


template<typename T>
class bittree
{
public:
     Node<T> * proot;

public:
     
     bittree ():proot(NULL)
     {
     }
         
     /* create the tree from vec
      * vec can support flexible interface */
     void createBittree(const vector<vectype<T> > &vec);

     void preOrder();
     /* void preOrderR(bittree & tree); */

     /* 中序遍历，非递归 */
     void inOrder();
     
     /* void inOrderR(bittree & tree); */
     /* ~bittree(); */
     
};

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


#endif
