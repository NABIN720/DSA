#include<stdio.h>
#include<stdlib.h>
struct sll{
    int data;
    struct sll *next;
};
typedef struct sll Nodetype;
Nodetype *first,*last;
Nodetype* createNode(int element)
{
    Nodetype *newnode;
    newnode = (Nodetype*)malloc(sizeof(Nodetype));
    if(newnode = NULL)
    {
        printf("New memory allocation failed:");
        return newnode;
    }
    else{
        newnode->data = element;
        newnode->next = NULL;
        return newnode;
    }
} 

void insert (int element)
{
    Nodetype *newnode;
    newnode = Createnode(element);
    if(first == NULL)
    {
        first = last = newnode;
        printf("sucess");
    }
    else
    {
        newnode->next = first;
        first=newnode;
        printf("Sucess");
    }
}

void remove ()
{
    Nodetype *temp,*temp2;
    if(first==NULL)
    {
        printf("List Empty\n");
    }
    else if(first == last)
    {
        temp = first;
        first = last= NULL;
        free(temp);
    }
    else {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        printf("deleted item is %d\n",temp);
        
    }
}