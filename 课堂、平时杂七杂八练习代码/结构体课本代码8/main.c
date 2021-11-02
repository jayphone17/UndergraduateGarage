#include <stdio.h>
#include <stdlib.h>

struct
{
    int num;
    char name[20];
    char sex;
    char job;
    union
    {
        int clas;
        char position[10];
    } category;
} person[2];

int main()
{
    int i;
    for(i=0; i<2; i++)
    {
        scanf("%d%s%c%c",&person[i].num,&person[i].name,&person[i].sex,&person[i].job);
        if(person[i].job=='s')
        {
            scanf("%d",person[i].category.clas);
        }
        else if(person[i].job=='t')
        {
            scanf("%s",person[i].category.position);
        }
        else
        {
            printf("Input error!\n");
        }
    }
    for(i=0; i<2; i++)
    {
        if(person[i].job=='s')
        {
            printf("%d %s %c %c %d\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.clas);
        }
        else
        {
            printf("%d %s %c %c %s\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.position);
        }
    }
    return 0;
}
