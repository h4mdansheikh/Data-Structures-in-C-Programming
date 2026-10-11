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

int isRightAssociative(char ch){
  return ch=='^';
}

void infixtoPostfix(char infix[], char postfix[]){
  int i, k=0;
  for(i=0; infix[i] !='\0';i++){
    char c=infix[i];
    if(isalnum(c)){
      postfix[k++]=c;
    }
    else if(c=='('){
      push(c);
    }
    else if(c==')'){
      while(top!=-1 && peekTop() !='(')
        postxi[k++]=pop();
      pop();
    }
    else{
      while(top!=-1 && peektop() !='('&& (precedence(peekTop())>precedence(c) || (precedence(peekTop))==precedence(c) && !isRightAssociative(c)))){
        postfix[k++]=pop();
      }
      push(c);
    }
  }
  while(top!=-1)
    postfix[k++]=pop();
  postfix[k]='\0';
}

int main(){
  char infix[MAX],postfix[MAX];
  printf("Enter infix expression(No SPACES): ");
  scanf("%s",infix);
  infixtoPostfix(infix,postfix);
  printf("Postfix expression: %s\n" , postfix);
  return 0;
}
