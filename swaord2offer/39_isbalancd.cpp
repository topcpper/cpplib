/*************************************************************
*
*39_isbalancd.cpp: 判断是否是平衡二叉树
*auther     : caowg
*Written on : 09/02/13.
*
*************************************************************/

#include <iostream>

int get_depth(node * root)
{
    if(root == NULL)
        return 0;
    int left,right;
    left = get_depth(root->left);
    right = get_depth(root->right);
    return 1+(left > right ? left:right);
}

bool _isbalance(node * root, int & depth)
{
    if(root == NULL)
    {
        depth = 0;
        return true;
    }
    int left,right;
    if(_isbalance(root->left,left) && _isbalance(root->right,right))
    {
        int diff = left - right;
        if(diff >= -1 && diff <= 1)
        {
            *depth = 1+(left > right ? left  : right);
            return true;
        }
    }
    return false;
}

bool isbalance(node* root)
{
    int depth = 0;
    return _isbalance(root,depth);
}


using namespace std;

int main(int arg ,char *arv[])
    {
        
    }
