// 100-operations.c
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int sub(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int mul(int a, int b) {
    return a * b;
}

// Function to divide two numbers (integer division)
int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        // Handle division by zero
        return 0;
    }
}

// Function to calculate the modulus of two numbers
int mod(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        // Handle modulus by zero
        return 0;
    }
}
