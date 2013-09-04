/*************************************************************
*
*16_reverse_list.cpp: reverse the list
*auther     : caowg
*Written on : 08/08/13.
*
*************************************************************/

#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node * next ;
};

typedef Node * PNode ;


void init_list_other(PNode & list)
{
    PNode p;
    for(int i = 5 ; i > 0 ; i--)
    {
        p = new Node;
        p->data = i;
        p->next = list;
        list = p;
    }
}


void init_listwith_head(PNode & list)
{
    PNode p;
    for(int i = 5 ; i > 0 ; i--)
    {
        p = new Node;
        p->data = i;
        p->next = list->next;
        list->next = p;
    }
}


PNode reverse_list(PNode & list)
{
    PNode pre,p,flow;
    p = pre = list;
    if(p == NULL || pre->next == NULL)
        return p;

    p = p->next;
    flow = p->next;
    pre->next = NULL;
    
    while( flow)
    {
        p->next = pre;
        pre = p;
        p = flow;
        flow = flow->next;
    }
    p->next = pre;
    return p;
}

void print_list(const PNode & list)
{
    PNode pre = list;
    while(pre)
    {
        cout<<pre->data<<",";
        pre = pre->next;
    }
    
}


int main(int arg ,char *arv[])
    {
        PNode list = NULL;
        init_list_other(list);
        print_list(list);
        list = reverse_list(list);
        print_list(list);
    }
