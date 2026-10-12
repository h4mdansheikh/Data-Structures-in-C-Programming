#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100;
int stack[MAX];
int top=-1;

void push(int x){
  stack[++top]=x;
}
int pop(){
  return stack[top--];
}

int evaluatePostfix(char postfix[]){
  int op1,op2,result;
  for(i=0;i!='\0';i++){
    char c=postfix[i];
  if (isdigit(c)){
    push(c-'0');
  }else{
    op2=pop();
    op1=pop();
    switch(c){
      case '+': result = op1 + op2;
      break;
      case '-': result = op1 - op2;
      break;
      case '*': result = op1*op2;
      break;
      case '/': result = op1/op2;
      break;
      case'^': result= (int)pow(op1,op2);
      break;
      default:
      printf("Invalid operator: %c\n",c);
      exit(1);
    }
    push(result);
  }
}
return pop();
}

int main(){
  char postfix[Max];
  printf("Enter the Postfix Expression: ");
  scanf("%s",postfix);
  printf("Result=%d\n",evaluatetoPostfix(postfix));
  return 0;
  
}

