#include<stdio.h>

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(n==15){
            printf("A+\n");
        }
        if(n>=13&&n<=14){
            printf("A\n");
        }
        if(n>=10&&n<=12){
            printf("B\n");
        }
        if(n>=7&&n<=9){
            printf("C\n");
        }
        if(n>=4&&n<=6){
            printf("D\n");
        }
        if(n>=2&&n<=3){
            printf("E\n");
        }
        if(n>=0&&n<=1){
            printf("E-\n");
        }
    }
}