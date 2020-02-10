## What is a pointer?
* Sample code below found in pointerdemo1*

A pointer is a datatype that "points" to a memory address.

## How do we declare a pointer?
We delcare a pointer much like other declarations, with a type and name.
```cpp
	int* x; // this a a declaration of a pointer
```
## Pointer Operations

**The `&` Operator**
The Address of Operator is called on a variable to reference the address of the variables, such that if `x` is a variable with an integer datatype, `&y` is a reference to the memory address of the variable x.
```cpp
	int x = 50;
	int* y =  &x;
```

**The `*` Operator**
The Contents of Operator(also called a dereferencing operator) is a called on a variable to get the value of the variable. This does not get a copy of the value, rather operators on a dereferenced variable will actuallly be performed on that value.

```cpp
	int x = 5;
	int* p = &x;
	*p = 10;
	cout << x << endl; // this value will be 10
```

*p is simply an alias for x.

