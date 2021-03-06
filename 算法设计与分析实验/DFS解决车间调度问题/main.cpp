#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int totalStep,minTime;
int n,m;
int Step[105];
struct Job
{
    int machine;
    int len;
} job[105][105];
int jobEnd[105][105];
int jobStep[105];
int machineWorkTime[105];
struct Recording
{
    int start;
    int ed;
    int job;
    int machine;
} best[105],now[105];
void init()
{
    totalStep=0;
    minTime = 999999999;
    memset(jobStep,0,sizeof(jobStep));
    memset(machineWorkTime,0,sizeof(machineWorkTime));
    memset(best,0,sizeof(best));
    memset(jobEnd,-1,sizeof(jobEnd));
}
void dfs(int step,int time)
{
    if (time>=minTime) return;
    if (step == totalStep)
    {
        minTime = time;
        for (int i=0; i<totalStep; i++)
            best[i]=now[i];
        /*int gantt[105][105];
        for (int i=0;i<totalStep;i++)
        {
            for (int j=best[i].start;j<best[i].ed;j++)
            {
                gantt[best[i].machine][j]=best[i].job;
            }
        }
        for (int i=0;i<m;i++)
            for (int j=0;j<minTime;j++)
                printf("%d%c",gantt[i][j],j==minTime-1?'\n':' ');
            printf("\n");*/
        return;
    }

    for (int i=0; i<n; i++)
    {
        int j = jobStep[i];
        if (j >= Step[i]) continue;
        int thisMachine = job[i][j].machine;
        now[step].machine = thisMachine;
        now[step].job = i+1;
        int temp =  machineWorkTime[thisMachine];
        int beginTime = max(jobEnd[i][j-1],machineWorkTime[thisMachine]);
        now[step].start = beginTime;
        machineWorkTime[thisMachine] =beginTime + job[i][j].len;
        jobEnd[i][j] = now[step].ed = machineWorkTime[thisMachine];
        jobStep[i]++;
        //printf("%d %d %d\n",step,i,j);
        dfs(step+1, max(time,machineWorkTime[thisMachine]) );
        jobStep[i]--;
        machineWorkTime[thisMachine]=temp;
    }
}
int main()
{
    printf("输入工作数量：");
    scanf("%d",&n);
    printf("输入机器数量：");
    scanf("%d",&m);
    init();
    for (int i=0; i<n; i++)
    {
        printf("输入工作%d的步骤数量：",i);
        scanf("%d",&Step[i]);
        totalStep+=Step[i];
        for (int j=0; j<Step[i]; j++)
        {
            printf("步骤%d运行于哪个机器，消耗时间：",j+1);
            scanf("%d%d",&job[i][j].machine,&job[i][j].len);
        }

    }
    dfs(0,0);
    printf("最短时间为：%d\n",minTime);

    int gantt[105][105];
    for (int i=0; i<totalStep; i++)
    {
        for (int j=best[i].start; j<best[i].ed; j++)
        {
            gantt[best[i].machine][j]=best[i].job;
        }
    }

    for (int i=0; i<m; i++)
        for (int j=0; j<minTime; j++)
            printf("%d%c",gantt[i][j],j==minTime-1?'\n':' ');
}
