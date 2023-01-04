#include<stdio.h>
#include<stdlib.h>
struct sll{
    int data;
    struct sll *next;
};
struct sll *first,*last = NULL;
void insertion_at_beginning(int element)
{
    struct sll *NewNode;
    NewNode = (struct sll*) malloc(sizeof(struct sll));
    NewNode->data=element;
    NewNode->next=NULL;

    if(first==NULL)
    {
        first=last=NewNode;
    }
    else{
        NewNode->next = first;
        first = NewNode;
    }

}
void insertion_at_end(int element)
{
    struct sll *NewNode;
    NewNode = (struct sll *) malloc(sizeof(struct sll));
    NewNode->data=element;
    NewNode->next=NULL;
    if(first==NULL)
    {
        first=last=NewNode;
    }
    else{
        last->next = NewNode;
        last=NewNode;
    }


}
void insertion_at_specific_position(int element)
{
    struct sll *NewNode;
    NewNode = (struct sll *) malloc(sizeof(struct sll));
    NewNode->data=element;
    NewNode->next=NULL;
    if(first==NULL)
    {
        first=last=NewNode;
    }
    else
    {
        int position;
        printf("Enter position?");
        scanf("%d",&position);
        struct sll *temp,*temp2;
        temp=first;
        for(int i=1;i<position-1;i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next=NewNode;
        NewNode->next =temp2;

    }

}
int main()
{
    int element,choice;
    struct sll *temp;
    
    do
    {
    printf("\n1.INSERTION_AT_BEGINNING\n2.INSERTION_AT_END\n3.INSERTION_AT_SPECIFIC_PLACE\n4.DISPLAY\n5.EXIT");
    scanf("\n%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nElement insertion?");
        scanf("\n%d",&element);
        insertion_at_beginning(element);
        break;

    case 2:
        printf("\nElement insertion?");
        scanf("\n%d",&element);
        insertion_at_end(element);
        break;

    case 3:
        printf("\nElement insertion?");
        scanf("\n%d",&element);
        insertion_at_specific_position(element);
        break;

    case 4:
        temp=first;
        do{
            printf("%d\n",temp->data);
            temp=temp->next;
        }while(temp!=NULL);
        break;
    case 5:
        printf("Program terminated");
        break;
    default:
        printf("Enter a valid number...");
        break;
    }    /* code */
    } while (/* condition */choice!=5);

}