#include<stdio.h>
#include<conio.h>

int isEmpty();
int isFull();
void Enqueue(int,int);
int getHighestPriority();
int dequeueHighestPriority();
void display();


struct priorityQueue{
    int ele;
    int priority;
}pq[5];

int rear = -1;//global variable

int main()
{
    int ch,ele,p;
    do{

        printf("\n1.Enqueue\t2.getHighestPriority\t3.dequeueHighestPriority\t4.DISPLAY\t5.EXIT\n");
        printf("Enter choice");
        scanf("\n%d",&ch);
    
        switch (ch)
        {
            case 1:
                if(isFull())
                    printf("Queue is Full");
                else
                {
                    printf("\nEnter the element");
                    scanf("\n%d",&ele);
                    printf("\nEnter the priority");
                    scanf("\n%d",&p);
                    Enqueue(ele,p);
                }
                break;
            case 2:
                if(isEmpty())
                    printf("\nQueue is Empty");
                else
                {
                    ele=getHighestPriority();
                    printf("\n%d is of the highest priority",ele);
                }
                break;

            case 3:
                if(isEmpty())
                    printf("\nQueue is Empty");
                else
                {
                    ele=dequeueHighestPriority();
                    printf("\n%d is dequeued",ele);
                }
                break;

            case 4:
                if(isEmpty())
                    printf("Queue is Empty");
                else
                    display();
                break;

            case 5:
                printf("Program Terminated...");
                break;
        
            default:
                break;
        }
    }while(ch!=5);

    return 0;

}

int isEmpty()
{
    if(rear==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear==4)
        return 1;
    else
        return 0;
}

void Enqueue(int ele, int p)
{
    rear = rear + 1;
    pq[rear].ele = ele;
    pq[rear].priority = p;
}

int getHighestPriority()
{
    int i, p=-1,ele;
    if(!isEmpty())
    {
        for(i=0;i<=rear;i++)
        {
            if(pq[i].priority>p)
            {
                p=pq[i].priority;
                ele = pq[i].ele;
            }
        }
    }
    return ele;
}

int dequeueHighestPriority()
{

    int i,j,ele,p;
    p=getHighestPriority();
    for(i=0;i<=rear;i++)
    {
        if(pq[i].priority==p)
        {
            ele = pq[i].ele;
            break;
        }
    }
    if(i<rear)
    {
        for(j=i;j<rear;j++)
        {
            pq[j].ele = pq[j+1].ele;
            pq[j].priority = pq[j+1].priority;
        }
    }

rear = rear - 1;
return ele;
}

void display()
{
    int i;
    printf("\nPriority Queue is:-");
    for(i=0;i<=rear;i++)
    {
        printf("\nELEMENT = %d  and PRIORITY = %d",pq[i].ele,pq[i].priority);
    }
}