#include <stdio.h>
int a, b, temp;
//շת�����ʵ��
int Subtract(){
    printf("������������(a,b)��\n");
    scanf("%d,%d",&a,&b);
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while(a-b != 0){
            temp = a-b;
            a = b;
            b = temp;
    }
    printf("���Լ��Ϊ��%d\n",b);
    return 0;
}