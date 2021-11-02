#include<stdio.h>
int main()
{
    struct student_score
    {
        int mid;
        int end;
        int ave;
    }score;
    printf("Please input score (midterm and end of term):");
    scanf("%d,%d",&score.mid, &score.end);
    score.ave = (score.mid + score.end) / 2;
    printf("average = %d\n", score.ave);
}