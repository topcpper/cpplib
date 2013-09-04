/*************************************************************
*
*bittree.cpp: it is my impletion of bittree
*auther     : caowg
*Written on : 04/01/13.
*
*************************************************************/
#include <list>
#include <iostream>
#include "bittree_int.h"
#include <queue>
#include <stack>
#include <string>

using namespace std;


void bittree:: createBittree( const vector<vectype > &vec)
{
    // the keyword typename is used ，来表明 vector < vectype > :: const_iterator
    // 是个类型，而不是对象
     vector< vectype > :: const_iterator itert = vec.begin() ;
    if(itert == vec.end())
        return ;
    queue<Node *> quep;
    
    proot = new Node ;
    Node * ptemp ;
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
            ptemp->left = new Node;
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
            ptemp->right = new Node;
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


void bittree :: preOrder()
{
    if(proot==NULL)
        return ;
    
    stack<Node* > s;
    Node*  ptemp ;
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




void bittree :: inOrder()
{
    if(proot==NULL)
        return ;
    stack<Node* > s;
    Node*  ptemp = proot ;
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
