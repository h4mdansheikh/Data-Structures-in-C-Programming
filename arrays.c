//Pointers and arrays
void printArr(int *a, int n) { // equivalent to: void printArr(int a[], int n)
 for (int i = 0; i < n; i++)
 printf("%d ", *(a + i)); // same as a[i]
}
int main() {
 int arr[5] = {1,2,3,4,5};
 printArr(arr, 5); // only the base address of arr is passed
 return 0;
}
