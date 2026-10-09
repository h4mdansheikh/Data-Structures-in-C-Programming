//=====================================================\\
//Stack Implementation using dynamically allocated array\\
//=======================================================\\



#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int *arr;        //Pointer to the dynamically allocated array
  int top;         //Index of the current top element
  int capacity;    //current allocated size of arr
} Stack;

Stack* createStack(int initialCapacity){
  Stack* = (Stack*)malloc(sizeof(Stack));
  s->capacity-intialCapacity;
  s->top=-1;
  s->arr=(int*)malloc(s->capacity*sizeof(int));
  return s;
}

void resizeStack(Stack *s){
  s->capacity*=2;
  s->arr=(int*)realloc(s->arr,s->capacity*sizeof(int));
  printf("[Resized stack to capacity %d]\n",s->capacity);
}

//-----Push Operation-----\\
void push(Stack*s , int item){
  if(s->top==s->capacity-1)
      resizeStack(s);
  s->arr[++(s->top)]=item;
}

//-----Pop Operation-----\\

int pop(Stack *s){
  if(s->top==-1){
    printf("Stack Underflow\n");
    return -1;
  }
  return s->arr[(s->top)--]
}

//-----Peek Operation-----\\

int peek(Stack *s){
  if(s->top==-1({
    printf("Stack is empty\n");
    return -1;
  }
return s->arr[s->top];
}

//-----Check is Stack is empty-----\\

int isEmpty(Stack *s){
  return s->top==-1;
}

//-----Display Stack-----\\

