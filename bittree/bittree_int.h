#ifndef BITTREE_H
#define BITTREE_H
#include <vector>
using namespace std;

/* the node of the tree */

struct Node
{
     Node * left ; /* point to left */
     Node * right ; /* point to right */
     int data; /* data  */
};

/* the container type of the tempopary data array */

struct vectype
{
     int data ;
     bool isnull ;
};



class bittree
{
public:
     Node * proot;

public:
     
     bittree ():proot(NULL)
     {
     }
         
     /* create the tree from vec
      * vec can support flexible interface */
     void createBittree(const vector<vectype > &vec);
     
     void preOrder();
     /* void preOrderR(bittree & tree); */

     /* 中序遍历，非递归 */
     void inOrder();
     
     /* void inOrderR(bittree & tree); */
     /* ~bittree(); */
     
};


#endif
