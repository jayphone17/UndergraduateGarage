#include <stdio.h>
#include <stdlib.h>
#define N 3

struct student
{
    int num;
    char name[20];
    float score[3];
    float aver;
};

void input(struct student stu[])
{
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%d%s%f%f%f",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);

        stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }

}

struct student max(struct student stu[])
{
    int i;
    int m=0;
    for(i=0;i<N;i++)
    {
        if(stu[i].aver>stu[m].aver)
            m=i;
        return stu[m];
    }
}

void ouput(struct student stud)
{
    printf("%d\n%s\n%.2lf\n%.2lf\n%.2lf\n%.2f\n", stud.num , stud.name , stud.score[0] , stud.score[1] , stud.score[2],stud.aver);
}


int main()
{
    void input(struct student stu[]);
    struct student max(struct student stu[]);
    void ouput(struct student stu);
    struct student stu[N];
    struct student *p=stu;
    input(p);
    ouput(max(p));
    return 0;
}
