#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct student
    {
        long num;
        char name[20];
        char sex;
        float score;
    };

    struct student stu1;
    struct student *p;
    p=&stu1;

    stu1.num=10101;
    strcpy(stu1.name,"wang");
    stu1.sex='M';
    stu1.score=89.5;

    printf("%ld %s %c %f\n",(*p).num,(*p).name,(*p).sex,(*p).score);

    printf("%ld %s %c %f\n",stu1.num,stu1.name,stu1.sex,stu1.score);

    printf("%ld %s %c %f\n",p->num,p->name,p->sex,p->score);


    return 0;
}
