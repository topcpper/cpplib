#ifndef BITTREE_H
#define BITTREE_H
#include <vector>
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



#endif
