#include <stdio.h>

double polynomial(int a[], double x, int n)
{
    double result = 0.0;
    for (int i = 0; i <= n; i++)
    {
        double term = a[i];
        for (int j = 0; j < i; j++)
        {
            term *= x;
        }
        result += term;
    }
    return result;
}

int main()
{
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    int coefficients[n + 1];
    printf("Enter the coefficients from highest to lowest degree:\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &coefficients[i]);
    }

    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    double result = polynomial(coefficients, x, n);
    printf("Result: %lf\n", result);

    return 0;
}