#include "list.h"
struct NODE
{
    int value;
    Node* next;
};
List createList()
{
    List head;
    head=(List)malloc(sizeof(Node));
    if(head==NULL)
    {
        fatal("memory alloc failed!");
    }
    head->next=NULL;
    return head;
}
void destroyList(List list)
{
    assert(list!=NULL);
    Node* tmp;
    Node* p=list->next;
    list->next=NULL;
    while(p!=NULL)
    {
        tmp=p->next;
        free(p);
        p=tmp;
    }
}
Node* first(List list)
{
    assert(list!=NULL);
    return list->next;
}
Node* last(List list)
{
    assert(list!=NULL);
    Node* p=list->next;
    while(p!=NULL)
    {
        p=p->next;
    }
    return p;
}
int isEmpty(List list)
{
    return list->next==NULL;
}
int isLast(Node* node, List list)
{
    return node->next==NULL;
}
Node* find(int value, List list)
{
    Node* node=list->next;
    while(node!=NULL && node->value!=value)
    {
        node=node->next;
    }
    return node;
}
void delete(int value, List list)
{
    assert(list!=NULL);
    Node* prev=list;
    while(prev!=NULL && prev->next->value != value)
    {
        prev=prev->next;
    }
    Node* current=prev->next;
    prev->next=current->next;
    free(current);
}
void delete2(Node* node)
{
    assert(node!=NULL);
    Node* next=node->next;
    if(next==NULL)
    {
        free(node);
        node=NULL;
    }
    else
    {
        node->next=next->next;
        node->value=next->value;
        free(next);
        next=NULL;
    }
}
Node* insert(int value, Node* node, List list)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        fatal("memory alloc failed!");
    }
    newNode->value=value;
    newNode->next=node->next;
    node->next=newNode;
    return newNode;
}
void insertBefore(int value, Node* node, List list)
{
    fatal("not implemented!");
}
Node* findPrev(Node* node, List list)
{
    assert(list!=NULL);
    Node* current=list->next;
    while(current!=NULL && current->next!=node)
    {
        current=current->next;
    }
    return current;
}
Node* findNext(Node* node, List list)
{
    return node->next;
}
List sort(List list)
{
    Node* tail = NULL;
    while(tail != list->next)
    {
        Node* pre = list;
        Node* cur = pre->next;
        while(cur != tail && cur->next != tail)
        {
            Node *tmp=cur->next;
            if( cur->value > tmp->value )
            {
                //swap current and next node
                pre->next = tmp;
                cur->next = tmp->next;
                pre->next->next = cur;
            }
            pre = pre->next;
            cur = pre->next;
        }
        tail = cur;
    }
    return list;
}
List reverse(List list)
{
    assert(list!=NULL);
    if(list->next==NULL)
    {
        return list;
    }
    Node* p;
    Node* q;
    Node* tmp;
    p=list->next;
    q=p->next;
    p->next=NULL;
    while(q!=NULL)
    {
        tmp=q->next;
        q->next=p;
        p=q;
        q=tmp;
    }
    list->next=p;
    return list;
}
void print(List list)
{
    assert(list!=NULL);
    Node* node=list->next;
    while(node!=NULL)
    {
        printf("%d -> ", node->value);
        node=node->next;
    }
    printf("\n");
}
void clear(List list)
{
    Node* node=list->next;
    Node* tmp;
    while(node!=NULL)
    {
        tmp=node->next;
        free(node);
        node=tmp;
    }
    list->next=NULL;
}
int length(List list)
{
    assert(list!=NULL);
    int len=0;
    Node* node=list->next;
    while(node!=NULL)
    {
        len++;
        node=node->next;
    }
    return len;
}
void fatal(char *message)
{
    printf("Fatal error: %s",message);
    exit(0);
}
void swap(Node* p, Node* q)
{
    // just swap value, not pointer
    int tmp=p->value;
    p->value=q->value;
    q->value=tmp;
}
int main(int argc, char **argv)
{
    List list=createList();
    int i;
    Node* lastNode=list;
    for(i=0; i<10; i++)
    {
        Node* node=(Node*)malloc(sizeof(Node));
        if(node==NULL)
        {
            fatal("memory allocate failed.");
        }
        Node* current=insert(rand()%100, lastNode, list);
        //Node* current=insert(i, lastNode, list);
        lastNode=current;
    }
    print(list);
    sort(list);
    print(list);
    return 0;
}
