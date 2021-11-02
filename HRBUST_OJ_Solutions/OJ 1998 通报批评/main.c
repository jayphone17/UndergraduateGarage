#include <stdio.h>
#include <stdlib.h>

struct note
{
    char name[25];
    int number;
};//student[105];


int main()
{
    int n;
    struct note student[105];
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0; i<n; i++)
        {
            scanf("%s%d",student[i].name,&student[i].number);
        }
        for(i=0; i<n; i++)
        {
            if(student[i].number==0)
            {
                printf("%s\n",student[i].name);
            }
        }
        printf("\n");
    }
    return 0;
}
