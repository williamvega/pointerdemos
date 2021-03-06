# Pointer specific topics

## What is a pointer?
 *Sample code below found in pointerdemo1*

A pointer is a datatype that "points" to a memory address, such that it has that memory address as its value.

## How do we declare a pointer?
We delcare a pointer much like other declarations, with a type and name.
```cpp
	int* x; // this a a declaration of a pointer
```
We read this right to left, as x is a pointer to an int.

If we declare a list of variables like this:
```cpp
	int* xPtr, y;
```
Only the xPtr is a pointer to an int, the y is simply an int.

## Initializing pointers
Valid initializations include `nullptr`, `0`, and `NULL`, but nullptr is the standard as of C++11.

## Pointer Operations

**The `&` Operator**
The Address of Operator is called on a variable to reference the address of the variables, such that if `x` is a variable with an integer datatype, `&y` is a reference to the memory address of the variable x.
```cpp
	int x = 50;
	int* yPtr =  &x;
```

**The `*` Operator**
The Contents of Operator(also called a dereferencing operator) is a called on a pointer to get the value of the pointer. This does not get a copy of the value, rather operators on a dereferenced variable will actuallly be performed on that value.

```cpp
	int x = 5;
	int* pPtr = &x;
	*pPtr = 10; // here we are dereferncing pointer p
	cout << x << endl; // this value will be 10
```

*p is simply an alias for x.

*Do not dereference a nullptr, as this leads to undefined behavior.*

**Pass By Reference with a Pointer**
As we have seen before, the three ways to pass arguments to a function in C++ as pass by value (ex: `void foo(int);`) pass by reference with a reference argument(ex: `void foo(int&);`), and pass by reference with a pointer argument(ex: `void foo(int*);`). 

Here, we cover the third method.
For example, we can square a number using the function below, assuming proper imports:

```cpp
void squareByReference(int*);

int main() {
    int number = 5;
    squareByReference(&number); // using memory address operator 
    cout << number << endl; // this will output 25
}

void squareByReference(int* xPtr) {
     *nPtr = *nPtr * *nPtr; // evaluate from right to left
}
```

If we pass-by-reference with a pointer, we actually pass the pointer by value, and must dereference the pointer to use the value later.

To make it very clear, we are NOT using a return statement to change the value of number. We are accessing the value from another function.

## Using `const` with Pointers

`const` tells the compiler that the value of a variable should not be modified. We determine `const` usage based on the principle of least privelege.

This is relevant to the discussion of pointers because of the interchangeability of pointers and built-in arrays, and the fast that built-in arrays are always passed by reference, thus leaving them mutatable in the called function.

There are four ways to pass a pointer to a function: a nonconstant pointer to nonconstant data, a nonconstant pointer to constant data, a constant pointer to nonconstant data, and a constant pointer to constant data.

 *Method 1: Nonconstant pointer to nonconstant data*
Highest access to data possible. Data may be modified through dereferenced pointer, pointer may be modified to point to other data.

*Method 2: Nonconstant pointer to constant data*
Pointer may be modified to point to other data, but the data cannot be modified through the pointer.

`const int* countPtr` and `int const* countPtr` are both refering to a countPtr being a pointer refering to an integer constant`, while the pointer itself is not constant. The data (an integer) is constant, the pointer is not.

*Method 3: Constant pointer to nonconstant data*
A constant pointer to nonconstant data always points to the same memory location, but may be modified through the pointer.
Pointers declared const must be initialized when declared, and if it is a function parameter, it is initialized when the pointer is passed to the function.
```cpp
int* const ptr = &x;
```

*Method 4: Constant pointer to constant data*
Minmum possible privelege given.
A pointer that always points to the same memory address, AND the value can not be modified through the pointer.
```cpp
const int* const ptr = &x;
```

## Pointer Expressions and Pointer Arithmetic
Some arithmetic operations may be performed on pointers.
Pointer arithmetic is only appropriate for pointers that point to built-in arrays. The operations include `++`, `--`, `+=`, `+`, `-=`, `-`, and subratracting one pointer from another of the same type (when tjey point to the elements of the same built in array).

**Adding**
The addition will not only be the integer, but the integer times to sizeof the datatype the pointer refers to. For example, if `vPntr` points to memory address 1000, and each item in the array is 8 bytes, then `vPntr+=1` will point to 1008.
There is no bounds checking.

Subtracting works the same way.

**Subtracting Pointers**
Pointer variables pointing to the same built-in array can be subtracted from eachother. If `vPtr1` points to 3000 and `vPtr2` points to 3008, then
```cpp
x = vPtr2 - vPtr1; // x would be the number of built in array elements between the two pointers
```

**Pointer assignment**
Pointers may be assigned to other pointers if both pointers are of the same time. The only expection is a pointer to `void`, such as `void*`. This generic pointer can represent any pointer type.

A void* pointer cannot be dereferrenced, as it contains memory address for an unknown datatype, and cannot know which datattype this should be.

**Comparing pointers**
Most often we just make sure it doesn't point to null.

# Pointer Related Topics
## Built-in Arrays

## Relationship between built-in arrays and pointers

## `sizeof` Operator

## Pointer-based strings

## Smart Pointers notes