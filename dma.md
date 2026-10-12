## Dynamic Memory Allocation (DMA) in C

Static memory allocation, such as normal array declarations, fixes the size of memory at compile time. **Dynamic Memory Allocation (DMA)** allows memory to be requested and released at runtime from a pool of free memory called the **heap**.

DMA functions are declared in the `<stdlib.h>` header file. They are essential for implementing data structures whose sizes are not known in advance, such as linked lists, dynamic arrays, trees, and graphs.

### DMA Functions in C

| Function | Prototype | Purpose | Initializes Memory? |
|---|---|---|---|
| `malloc()` | `void *malloc(size_t size);` | Allocates a single block of `size` bytes. | No. Memory contains indeterminate values. |
| `calloc()` | `void *calloc(size_t n, size_t size);` | Allocates memory for `n` elements, each of `size` bytes. | Yes. All bytes are initialized to zero. |
| `realloc()` | `void *realloc(void *ptr, size_t newSize);` | Resizes a previously allocated memory block. | Preserves existing data up to the smaller of the old and new sizes. Any additional memory is uninitialized. |
| `free()` | `void free(void *ptr);` | Releases a previously allocated memory block back to the heap. | Not applicable. |

### 1. `malloc()` — Memory Allocation

Allocates a single block of memory of the specified size in bytes.

```c
int *arr = malloc(5 * sizeof(int));
```

- Allocates enough memory for five integers.
- The allocated memory is not initialized.
- Returns a pointer to the allocated memory, or `NULL` if allocation fails.

### 2. `calloc()` — Contiguous Allocation

Allocates memory for multiple elements and initializes all allocated bytes to zero.

```c
int *arr = calloc(5, sizeof(int));
```

- Allocates memory for five integers.
- Initializes all bytes to zero.
- Returns a pointer to the allocated memory, or `NULL` if allocation fails.

### 3. `realloc()` — Reallocation

Changes the size of a previously allocated memory block.

```c
int *temp = realloc(arr, 10 * sizeof(int));

if (temp != NULL) {
    arr = temp;
}
```

- Resizes the memory block to accommodate ten integers.
- Preserves existing data up to the smaller of the old and new sizes.
- The newly added portion is uninitialized when the block grows.
- Using a temporary pointer prevents losing the original allocation if `realloc()` fails.

### 4. `free()` — Deallocation

Releases dynamically allocated memory when it is no longer needed.

```c
free(arr);
arr = NULL;
```

- Returns the allocated memory to the heap.
- Helps prevent memory leaks.
- Setting the pointer to `NULL` helps avoid accidentally using that pointer after deallocation.

### Important Points to Remember

- Include `<stdlib.h>` to use DMA functions.
- Always check whether `malloc()`, `calloc()`, or `realloc()` returns `NULL`.
- Use `sizeof()` to calculate the required memory size correctly.
- Every successfully allocated block should eventually be released with `free()` when it is no longer needed.
- Never access memory after it has been freed.
- Do not call `free()` twice on the same allocation.

**In short:** `malloc()` allocates memory, `calloc()` allocates and zero-initializes memory, `realloc()` resizes memory, and `free()` releases memory.
