#include<stdio.h>
#include(ctype.h>
#include<string.h>

#define MAX 100
char stack[MAX];
int top=-1;

void push(char x){
  stack[++top]=x;
}
char pop(){
  return stack[top--];
}
char peekTop(){
  return stack[top];
}

//Returns numeric precedence of an operator;higher value=binds tighter

int precedence(char ch){
  if (ch=='^') return 3;
  if (ch=='*' || ch=='/') return 2;
  if (ch=='+' || ch=='-') return 1;
  return -1;
}
