#include <linux/module.h>
#include <linux/kernel.h>

#define SIZE 3

static int n = 0;
module_param(n, int, S_IRUSR | S_IWUSR);

static int m = 0;
module_param(m, int, S_IRUSR | S_IWUSR);

static int matrixA[SIZE][SIZE] = {
    {0, 9, 2},
    {1, 15, 1},
    {7, 8, -4}
};

static int fact(int n)
{
    int i, f = 1;
    if (n < 1) return f;
    for (i = 1; i <= n; i++)  {
        f *= i;
    }
    return f;
}

static int findMinN(int matrix[SIZE][SIZE], int n)
{
    int i, j,  count = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] < n) {
                count++;
            }
        }
    }
    return count;
}

static int findDivN(int matrix[SIZE][SIZE], int n)
{
    int i, j,  count = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] % n == 0) {
                count++;
            }
        }
    }
    return count;
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

static int countPrimeN(int matrix[SIZE][SIZE], int n) {
    int i, j, count = 0;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(isPrime(matrix[i][j])) {
                if(matrix[i][j] >= n) {
                    count++;
                }
            }
        }
    }
    return count;
}

static int countPrimeNM(int matrix[SIZE][SIZE], int n, int m) {
    int i, j, count = 0;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
                if(matrix[i][j] >= m && matrix[i][j] <= n) {
                    count++;
                }
        }
    }
    return count;
}

static int __init matrix_init(void)
{
    printk("====================================================");
    printk("SO PHAN TU < %d: %d\n", n, findMinN(matrixA, n));
    printk("SO PHAN TU CHIA HET %d: %d\n", n, findDivN(matrixA, n));
    printk("SO PHAN TU NGUYEN TO >= %d: %d\n", n, countPrimeN(matrixA, n));
    printk("%d! = %d\n", n, fact(n));
    if (m > n) printk("M khong thoa man dieu kien.");
    else printk("SO PHAN TU THUOC [%d,%d]: %d\n", m, n, countPrimeNM(matrixA, n, m));
    return 0;
}

static void __exit matrix_exit(void)
{
    printk(KERN_INFO "Exiting matrix module\n");
}

module_init(matrix_init);
module_exit(matrix_exit);
MODULE_LICENSE("GPL");