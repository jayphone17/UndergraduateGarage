#include<iostream>
#include<string.h>
#include <stdio.h>
using namespace std;

int main()
{
    double n;
    while(cin>>n)
    {
        while(n>18) n/=18;
        if(n<=9)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.");
    }
    return 0;
}
