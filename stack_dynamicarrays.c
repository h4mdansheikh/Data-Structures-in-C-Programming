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

void display(Stack *s){
  printf("Stack (bottom->top): ");
  for (int i-0; i<=s->top;i++)
    printf("%d".s->arr[i]);
  printf("\n");
}

//-----Freeing the Stack-----\\
void freeStack(Stack *s){
  free(s->arr);
  free(s);
}

//================================\\
//---------Main Function-----------\\
//==================================\\

int main(){
     Stack *s=createStack(2);
     push(s, 10);
     push(s, 20);
     push(s, 30);                         /* triggers automatic resize */
     push(s, 40);
     display(s);
     printf("Popped: %d\n", pop(s));
     display(s);
     freeStack(s);
     return 0;
}
