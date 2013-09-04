/*************************************************************
*
*6_construct_btree.cpp: construct the binary tree use the pre order & in order
  用前序和中序 序列构建二叉树
*auther     : caowg
*Written on : 07/23/13.
*
*************************************************************/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node * lchild;
    Node * rchild;
};
int get_nleft(int dhead,int * b ,int b_l,int b_r)
{
    int count=0;
    for (int i = b_l; i <= b_r; ++i)
    {
        if(b[i] != dhead)
            count++;
        else
            break;
            
    }
    return count;
}

Node * _construct(int *a ,int a_l ,int a_r,int *b ,int b_l ,int b_r,Node * head)
{
    head->data = a[a_l];
    head->lchild = NULL;
    head->rchild = NULL;
    int number = get_nleft(a[a_l],b,b_l,b_r);
    
    if(number > 0) // 构建左子树
    {
        head->lchild = new Node;
        _construct(a,a_l+1,a_l+number,b,b_l,b_l+number-1,head->lchild);
    }
    if(a_r-a_l - number > 0) // 构建右子树
    {
        head->rchild = new Node;
        _construct(a,a_l+1+number,a_r,b,b_l+number+1,b_r,head->rchild);
    }
    return head;
    
}

Node * _construct_back(int *a ,int a_l ,int a_r,int *b ,int b_l ,int b_r,Node * head)
{
    head->data = a[a_r];
    head->lchild = NULL;
    head->rchild = NULL;
    int number = get_nleft(a[a_r],b,b_l,b_r);
    
    if(number > 0) // 构建左子树
    {
        head->lchild = new Node;
        _construct_back(a,a_l,a_l+number-1,b,b_l,b_l+number-1,head->lchild);
    }
    if(a_r-a_l - number > 0) // 构建右子树
    {
        head->rchild = new Node;
        _construct_back(a,a_l+number,a_r-1,b,b_l+number+1,b_r,head->rchild);
    }
    return head;
    
}





Node * construct_bitree(int * a ,int a_len,int *  b, int b_len)
{
    Node * head;
    if(a_len < 0)
        return NULL;
    head = new Node;
    head =_construct(a,0,a_len-1,b,0,b_len-1,head);
    return head;
}

Node * construct_bitree_back(int * a ,int a_len,int *  b, int b_len)
{
    Node * head;
    if(a_len < 0)
        return NULL;
    head = new Node;
    head =_construct_back(a,0,a_len-1,b,0,b_len-1,head);
    return head;
}

void test(int * a)
{
    cout<<a[0]<<endl;
}




int main(int arg ,char *arv[])
{
    int a[8]={1,2,4,7,3,5,6,8};
    int b[8]={4,7,2,1,5,3,8,6};
    int c[8]={7,4,2,5,8,6,3,1};
    
    
    Node * head;
    head =  construct_bitree(a,8,b,8);
    cout<<head->data;
    cout<<head->lchild->data<<endl;
    cout<<head->rchild->data<<endl;
    
    Node *p = head->lchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;
    p = p->lchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;

    p=head->rchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;
    p = p->rchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;

    Node * head1;
    head1 = construct_bitree_back(c,8,b,8);
    cout<<"back:"<<endl;
    
    cout<<head1->data;
    cout<<head1->lchild->data<<endl;
    cout<<head1->rchild->data<<endl;
    
    p = head1->lchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;
    p = p->lchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;

    p=head1->rchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;
    p = p->rchild;
    if(p->lchild)
        cout<<p->lchild->data<<endl;
    if(p->rchild)
        cout<<p->rchild->data<<endl;

    
        
}
