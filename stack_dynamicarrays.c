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


