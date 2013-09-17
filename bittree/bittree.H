/*************************************************************
*
*bittree.H  : the impletetion of bi tree
*auther     : caowg
*Written on : 05/04/13.
*
*************************************************************/

#ifndef BITTREE_H
#define BITTREE_H

#include <vector>
#include <list>
#include <iostream>
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

     /*获取层数 非递归 */
     int get_level();

     /* 层数递归 */
     int get_level_r();
     
     
private:
    int _get_level_r(const Node<T> * const root);

     
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

template <typename T>
int bittree<T>::get_level()
{
    if(proot==NULL)
        return 0;
    int level=0;
    queue< Node<T>* > que;
    que.push(proot);
    Node<T> * last = proot;
    Node<T> * pcur = proot;
    while(!que.empty())
    {
        pcur = que.front();
        que.pop();
        if(pcur->left)
            que.push(pcur->left);
        if(pcur->right)
            que.push(pcur->right);
        if(pcur == last)
        {
            level++;
            last = que.back();
        }
    }
    return level;
}

template <typename T>
int bittree<T>::_get_level_r(const Node<T> * const root)
{
    int l=0;
    int r=0;
    if(!root)
        return 0;
    l = _get_level_r(root->left);
    r = _get_level_r(root->right);
    return l>r ? (l+1) :(r+1);
}

template <typename T>
int bittree<T>::get_level_r()
{
    return _get_level_r(proot);
}




#endif
