# Notes for *C Programming: A Modern Approach, 2nd Edition*

At this directory, I will upload my write my notes here.

My practice results will be in [Practice](./Practice/) directory. Programming questions and notes for questions are [here](./Practice/README.md)

**Noted:** I'm using Chinese version, so some of the text may differ from the original book.

## Chapter 7: Primitive Data Types

### 7.4 Type Conversion

#### 7.4.4 Forced Type Conversion

Example in the book: 
```c
float f, frac_part;
frac_part = f - (int) f;
```

### 7.5 Type Definition

In Section 2 in Chapter 5, we can use `#define` to create a macro to define a Boolean data type: 

```c
#define BOOL int
```

But there's a better way to define a Boolean data type is **type definition** feature: 

```c
typedef int Bool;
```

**Notice:** `Bool` is a name of a new type.

Now `Bool` can be used in variable declaration, forced type conversion expression, and etc.. For example, we can use `Bool` to declare a variable: 

```c
Bool flag; // same as int flag
```

The compiler treats `Bool` type as synonymous with `int` type. Therefore, `flag` is just a common `int` variable.

#### 7.5.1 The Advantages of Type Definition

Type definition make the program more readable. For example, we use two variables, `cash_in` and `cash_out` to store the mount of dollars. We declare `Dollars` as: 

```c
typedef float Dollars;
```

then: 

```c
Dollars cash_in, cash_out;
```

This is more partical than `float cash_in, cash_out` .

## Chapter 8: Array

## Misc

1. `sizeof(var)` return a long unsigned int. So we should format '%ld' expects argument of this type of data.