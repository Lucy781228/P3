#include <linux/module.h>
#include <linux/kernel.h>

#define SIZE 3

static int matrixA[SIZE][SIZE] = {
    {0, 9, 2},
    {1, 15, 1},
    {7, 8, -4}
};

static int matrixB[SIZE][SIZE] = {
    {1, 8, 2},
    {4, 4, 1},
    {5, 10, 7}
};

static int result[SIZE][SIZE];

static void display(int matrix[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printk("%d", matrix[i][j]);
        }
        printk("\n");
    }
}

static void sumMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    display(c);
}

static void productMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE])
{
    int i, j, k;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            for(k = 0; k < SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    display(c);
}

static int find_max(int matrix[SIZE][SIZE])
{
    int i, j,  max = matrix[0][0];
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

static int find_min(int matrix[SIZE][SIZE])
{
    int i, j, min = matrix[0][0];
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

static int isPrime(int num) {
    int i;
    if(num < 2) {
        return 0;
    }
    for(i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

static int countPrime(int matrix[SIZE][SIZE]) {
    int i, j, count = 0;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(isPrime(matrix[i][j])) {
                count++;
            }
        }
    }
    return count;
}

static int __init matrix_init(void)
{
    // int min, max, prime;
    // min = find_min(matrixA);
    // max = find_max(matrixA);
    // prime = countPrime(matrixA);
    printk("MIN: %d\n", find_min(matrixA));
    printk("MAX: %d\n", find_max(matrixA));
    printk("SO PHAN TU NGUYEN TO: %d\n", countPrime(matrixA));
    printk("TONG 2 MA TRAN:\n");
    sumMatrix(matrixA, matrixB, result);
    printk("TICH 2 MA TRAN:\n");
    productMatrix(matrixA, matrixB, result);
    return 0;
}

static void __exit matrix_exit(void)
{
    printk(KERN_INFO "Exiting matrix module\n");
}

module_init(matrix_init);
module_exit(matrix_exit);
MODULE_LICENSE("GPL");