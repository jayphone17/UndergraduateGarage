#include<stdio.h>
#include<string.h>
#define MAXSIZE 1001
int prime[MAXSIZE];
void Prime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2; i < MAXSIZE; i++)
    {

        if(prime[i])
        {
            continue;
        }
        else
        {
            for(int j = i*i; j < MAXSIZE; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    int i,M,sum,x;
    printf("Input n:");
    Prime();
    prime[1] = 1;
    prime[0] = 1;
    sum = 0;
    scanf("%d",&M);
    for(i = 0; i < M; i++)
    {
        if(prime[i] == 0)
        {
            sum += i;
        }
    }
    printf("sum=%d\n",sum);
    return 0;
}
