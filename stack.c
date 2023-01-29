#include <stdio.h>
#define true 1
#define false 0
#define MAX 5

struct stack{
    int top;
    int data[MAX];
};
int isFull( struct stack *Q)
{
    if(Q->top == MAX-1)
    return true;

    else
    return false;
}
int isEmpty(struct stack *Q)
{
    if(Q->top == -1)
        return true;
    else
    return false;
}

void push(struct stack *Q,int element)
{
    if(isFull(Q) == true)
    printf("StackOverflow\n");
    else{
    Q->top += 1;
    Q->data[Q->top] = element;
    printf("Data Entered : %d",Q->data[Q->top]);
    }
}

void pop(struct stack *Q)
{
    if(isEmpty(Q) == true)
    {
    printf("StackUnderFlow");
    }
    else{
    int element;
    element = Q->data[Q->top];
    Q->top -= 1;
    printf("Data poped : %d",element);
    }
}


void display(struct stack Q)
{
    for(int i = Q.top; i>=0 ;i--,Q.top--)
    {
        printf("\n%d",Q.data[Q.top]);
    }
}



   
int main()
{
    struct stack s;
    s.top = -1;
    int choice,element;
     do
    {
        printf("\n--------STACK OPERATION USING ARRAY---------");
        printf("\n--------------------------------------------");
        printf("\n1. PUSH\n2. POP\n3. END POINT\n4. DISPLAY");
        printf("\nEnter the choice!!!");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed.");
            scanf("%d",&element);
            push(&s,element);
            break;

        case 2:
            pop(&s);
            break;

        case 3:
            printf("End point....");
            printf("\nProgram terminated");
            break;

        case 4:
            display(s);
            break;

        default:
            printf("Enter valid option carefully!!!");
            break;
        }

        /* code */
    }while (choice!=3);


}





    
    


