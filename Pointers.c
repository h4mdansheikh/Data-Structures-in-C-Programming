#include<stdio.h>
int main(){
//GENERAL SYNTAX <data_type>*<pointer_name>

int x=10;
int*p;
p=&x;
printf("%d", *p); // *p DEREFERENCES p -> prints value of x, i.e. 10
printf("%p", (void*)p); 

//POINTER TO POINTER FUNCTION DECLARATION
int x=5;
int *p=&x;        
int **pp=&p;            // pp holds the address of p
printf("%d",**p);        // double dereference -> 5

//* Function pointer — stores the address of a function */
int add(int a, int b){
  return a+b;
}
  int (*fptr)(int, int) = add; // fptr points to function add
printf("%d", fptr(3, 4)); // calls add(3,4) -> 7

  
}
