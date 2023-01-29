#include <stdio.h>
#include<stdlib.h>
#include<math.h>


struct priorityq{
  int ele;
  int priority;
}pq[10];

int size = 0;
void swap(int a, int b) {
  int temp = b;
  b = a;
  a = temp;
}

void heapify(struct priorityq *pq, int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  }
  else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;  //here i starts with 0.
    int r = 2 * i + 2;
    if (l < size && pq[l].ele > pq[largest].ele)
      largest = l;
    if (r < size && pq[r].ele > pq[largest].ele)
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      // swap(pq[i].ele, pq[largest].ele);
      int temp =pq[i].ele;
      pq[i].ele = pq[largest].ele;
      pq[largest].ele = temp;
      heapify(pq, size, largest);
    }
  }
}

// Function to enqueue an element into the queue
void enqueue(struct priorityq *pq, int newNum,int p) 
{
    pq[size].ele = newNum;
    pq[size].priority = p;
    size += 1;

    for (int i = floor(size / 2); i >= 0; i--) {
      heapify(pq, size, i);
    }
  
}

// Function to delete an element from the queue
void deleteRoot(struct priorityq *pq) {
  int lar_pr=-1,i,ele;
  lar_pr=pq[0].priority;
  for(i=1;i<size;i++){
    if(lar_pr<pq[i].priority)
    {
      lar_pr = pq[i].priority;
      ele = pq[i].ele;
    }
  }

  // swap(pq[i].ele,pq[size - 1].ele);
    int temp = pq[size-1].ele;
    pq[size-1].ele = ele;
    ele = temp;

  size -= 1;
  for (int j = floor(size / 2); j >= 0; j--) {
    heapify(pq, size, j);
  }
}

// Print the array
void printArray(struct priorityq *pq, int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", pq[i].ele);
  printf("\n");
}

int main() {
  
  int array[10];
  int ch,ele,p;
  printf("\nHeap-Sort using priority queue\n");

  do{

  printf("\n1.ENQUEUE\t2.DEQUEUE\t3.DISPLAY\t4.EXIT\n");
  scanf("%d",&ch);

  switch (ch)
  {
  case 1:

    printf("Enter the number to enqueue?");
    scanf("%d",&ele);

    printf("\nPriority?");
    scanf("%d",&p);

    enqueue(pq, ele, p);
    break;
  
  case 2:
    if(size == 0)
      printf("EMPTY QUEUE");
    else{
      deleteRoot(pq);
      printf("After deleting an element: ");
      printArray(pq, size);
      }
    break;

  case 3:
    if(size == 0)
      printf("EMPTY QUEUE");
    else
    {
      printf("Max-Heap array: ");
      printArray(pq, size);
    }
    break;

  case 4:
    break;
  
  default:
    break;
  }
  }while(ch!=4);

}