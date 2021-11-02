#include<math.h>
#include<stdio.h>
int main()
{
    int year;
    double rate, deposit, capital;
    char x;
    printf("Input capital, year:");
    scanf("%lf,%d", &capital, &year);
    printf("Compound interest (Y/N)?");
    getchar();
    x=getchar();
    switch(year)
    {
        case 1:
            rate = 0.0225;
            break;
        case 2:
            rate = 0.0243;
            break;
        case 3:
            rate = 0.0270;
            break;
        case 5:
            rate = 0.0288;
            break;
        case 8:
            rate = 0.0300;
            break;
        default:
            {
                printf("Error year!\n");
                return 0;
            }
    }
    switch(x)
    {
        case'y':
            deposit = capital * pow((1 + rate), year);
            break;
        case'Y':
            deposit = capital * pow((1 + rate), year);
            break;
        case'N':
            deposit = capital * (1 + rate * year);
            break;
        case'n':
            deposit = capital * (1 + rate * year);
            break;
    }
    printf("rate = %.4f, deposit = %.4f\n", rate, deposit);
    return 0;
}
