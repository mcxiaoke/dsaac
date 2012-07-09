#include "dlist.h"
struct NODE
{
    int value;
    Node* prev;
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
    head->prev=NULL;
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
    if(node->next==NULL||node->prev==NULL)
    {
        free(node);
        node=NULL;
    }
    else
    {
        node->prev->next=node->next;
        free(node);
        node=NULL;
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
    newNode->prev=node;
    newNode->next=node->next;
    node->next=newNode;
    return newNode;
}
void insertBefore(int value, Node* node, List list)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        fatal("memory alloc failed!");
    }
    Node* prev=node->prev;
    prev->next=newNode;
    node->prev=newNode;
    newNode->prev=prev;
    newNode->next=node;
}
Node* findPrev(Node* node, List list)
{
    return node->prev;
}
Node* findNext(Node* node, List list)
{
    return node->next;
}
List sort(List list)
{
    //TODO
    Node* cur=list->next;]
    Node* prev;
    Node* next;
    Node* tmp;
    Node* tail=NULL;
    if(cur!=NULL && cur->next!=NULL){
        prev=cur->prev;
        next=cur->next;
        tmp=next->next;
    }
    
    return list;
}
List reverse(List list)
{
    assert(list!=NULL);
    Node* cur;
    Node* next;
    Node* tmp;
    cur=list->next;
    if(cur!=NULL && cur->next!=NULL)
    {
        next=cur->next;
        cur->next=NULL;
        while(next!=NULL)
        {
            cur->prev=next;
            tmp=next->next;
            next->next=cur;
            cur=next;
            next=tmp;
        }
        cur->prev=list;
        list->next=cur;

    }
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
        //Node* current=insert(rand()%100, lastNode, list);
        Node* current=insert(i, lastNode, list);
        lastNode=current;
    }
    print(list);
    print(reverse(list));
    print(sort(list));
    return 0;
}
