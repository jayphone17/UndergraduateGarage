#include <stdio.h>
#include <stdlib.h>

struct student
{
    int num;
    char name[20];
    float score;
}stu[5]={{10101,"lin",100},{10102,"qi",99},{10103,"wang",98},{10104,"ma",97},{10105,"song",96}};

int main()
{
    struct student temp;
    const int n=5;
    int i,j,k;

    for(i=0;i<n-1;i++)
    {
        i=k;
        for(j=i+1;j<n;j++)
            if(stu[j].score>stu[k].score)
            k=j;
        temp=stu[k];
        stu[k]=stu[i];
        stu[i]=temp;
    }

    for(i=0;i<n;i++)
    {
        printf("%d %s %f\n",stu[i].num,stu[i].name,stu[i].score);
    }
    return 0;
}
