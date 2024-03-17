# Notes for questions in *C Programming: A Modern Approach, 2nd Edition*

## Chapter 7: Primitive Data Types

1. If `i * i` exceeds the maximum value of type `int`, the program [`square2.c`](../Chapter-6/3-for-Statement/square2.c) in Section 3 in Chapter 6 would fail (usually display some strange numbers). Run the program and find the minimum value of `n` which lead to failure. Try to change the type of `i` into `short` and run it again. (Don't forget to update the conversion description in the `printf` function call) Then change it into `long`. From these experiments, can you figure out how many bits of integer type are stored in your machine?

    **Answer:** 

    1. Empty now...
    <!-- 1. The minimum value of `n` is 46341. -->

2. Modify [`square2.c`](../Chapter-6/3-for-Statement/square2.c) in Section 3 in Chapter 6. pause after every 24 square computation and display:

    ```
    Press Enter to continue...
    ```

    After that, the program should use `getchar` function to read a character. When `getchar` function read the Enter key entered by the user, the program continue.

    **Answer:** Empty now...