#include <stdio.h>
#include <stdlib.h>

struct information
{
    int number;
    char name[5];
    int yuwen;
    int shuxue;
    int yingyu;
} student;

int main()
{
    while(~scanf("%d%s%d%d%d",&student.number,&student.name,&student.yuwen,&student.shuxue,&student.yingyu))
    {
        if(student.yuwen<60 || student.shuxue<60 || student.yingyu<60)
        {
            printf("%ed%s\n",student.number,student.name);
        }
    }
    return 0;
}
