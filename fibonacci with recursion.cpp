#include<stdio.h>
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &num);
    
    printf("Fibonacci Series: ");
    for (int i = 0; i < num; i++) {
	printf("%d",fibonacci(i));
}
}
