#include<stdio.h>
#define MAXSIZE 5  

int queue[MAXSIZE];
int front=-1,rear=-1;

int isEmpty(){
  return front==-1;
}

int isFull(){
  return rear==MAXSIZE-1;
}

void enqueue(int item){
  if(isFull()){
    printf("Queue Overflow : Cannot insert %d\n",item);
    return;
  }
  if(isEmpty())
    front=0;
    queue[++rear]=item;
    printf("Enqueued %d\n",item);
}

int dequeue(){
  if(isEmpty()){
    printf("Queue Underflow: Queue is empty\n");
    return -1;
  }
  int item=queue[front];
  front++;
  if(front>rear)
    front=rear=1;
  return item;
}

int peek(){
  if(isEmpty()){
    printf("Queue is Empty\n");
    return -1;
  }
  return queue[front];
}

void display(){
  if(isEmpty()){
    printf("Queue Underflow: Queue is empty\n");
    return;
  }
  printf("Queue(front->rear): ");
  for(int i=front;i<=rear;i++)
    printf("%d",queue[i]);
  printf("\n");
}

int main(){
  enqueue(10);
  enqueue(20);
  enqueue(30);
  display();
  printf("Dequeued: %d\n",dequeue());
  display();
  printf("Front element (peek):%d\n",peek());
  enqueue(40);
  enqueue(50);
  enqueue(60);
  display();
  return 0;
}
