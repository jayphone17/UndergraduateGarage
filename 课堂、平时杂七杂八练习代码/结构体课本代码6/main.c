#include <stdio.h>
#include <stdlib.h>

struct student
{
    int num;
    char name [20];
    char sex;
    int age;

};

struct student stu[3]={{10101,"wang",'M',18},{10102,"lin",'M',19},{10103,"qi",'M',18}};

int main()
{
    struct student *p;
    for(p=stu;p<stu+3;p++)
    {
        printf("%d %s %c %d\n",p->num,p->name,p->sex,p->age);
    }
    return 0;
}
