#include<bits/stdc++.h>
#define MAXN 60 //最大工作量
#define INIT_PRE 3000//道路初始信息素量
#define K 2000 //循环次数
#define DIS 0.5 //信息素消散速率
#define SUPER_START 48
using namespace std;
int totalStep;
int Step[MAXN];
int phe[MAXN][MAXN][MAXN][MAXN];
int n,m;
struct Pair
{
    int i,j;
    void get(int a,int b)
    {
        i=a;j=b;
    }
}Jobnum[MAXN];
struct Job
{
    int machine;
    int len;
}job[MAXN][MAXN];
struct Ant
{
    int JobStep[MAXN]; //任务已运行步数
    int path[MAXN];
    int pathlen;
    int getFullPath()
    {
        int sum=0;
        for (int i=0;i<pathlen;i++)
            sum+=path[i];
        return sum;
    }
    Pair paths[MAXN];
};
void init()
{
    //totalStep=0;
    memset(phe,0,sizeof(phe));
    for (int i=0;i<totalStep;i++)
    for (int j=0;j<totalStep;j++)
    for (int k=0;k<totalStep;k++)
    for (int l=0;l<totalStep;l++)
        phe[i][j][k][l]=INIT_PRE;
    for (int i=0;i<totalStep;i++)
    for (int j=0;j<totalStep;j++)
        phe[SUPER_START][SUPER_START][i][j]=INIT_PRE;
    return;
}
void Dissipation()
{
    for (int i=0;i<totalStep;i++)
    for (int j=0;j<totalStep;j++)
    for (int k=0;k<totalStep;k++)
    for (int l=0;l<totalStep;l++)
        phe[i][j][k][l] *= DIS;
    for (int i=0;i<totalStep;i++)
    for (int j=0;j<totalStep;j++)
        phe[SUPER_START][SUPER_START][i][j]*= DIS;
    return;
}
struct Recording
{
    int start;
    int ed;
    int job;
    int machine;
};
int timeCalcu(int Job[], bool draw)
{
    int sum=0;
    int machineWorkTime[MAXN];
    int JobLast[MAXN];
    int JobStep[MAXN];
    Recording rec[MAXN];
    memset(machineWorkTime,0,sizeof(machineWorkTime));
    memset(JobLast,0,sizeof(JobLast));
    memset(JobStep,0,sizeof(JobStep));
    memset(rec,0,sizeof(rec));
    for (int k = 0; k < totalStep; k++)
    {
        int i = Job[k];
        rec[k].start = max(JobLast[i],machineWorkTime[job[i][JobStep[i]].machine]);
        rec[k].job = i;
        rec[k].ed = rec[k].start + job[i][JobStep[i]].len;
        JobLast[i] = rec[k].ed;
        rec[k].machine = job[i][JobStep[i]].machine;
        machineWorkTime[job[i][JobStep[i]].machine] = rec[k].ed;
        JobStep[i]++;
    }
    for (int i = 0; i < m; i++)
    {
        sum = max(sum,machineWorkTime[i]);
    }
    if (draw == true)
    {
        int gantt[MAXN][MAXN];
        memset(gantt,0,sizeof(gantt));
        for (int i=0;i<totalStep;i++)
        {
            for (int j=rec[i].start;j<rec[i].ed;j++)
            {
                gantt[rec[i].machine][j]=rec[i].job+1;
            }
        }

        for (int i=0;i<m;i++)
            for (int j=0;j<sum;j++)
                printf("%d%c",gantt[i][j],j==sum-1?'\n':' ');
    }
    return sum;
}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        totalStep = 0;
        for (int i=0;i<n;i++)
        {

            scanf("%d",&Step[i]);
            totalStep+=Step[i];
            for (int j=0;j<Step[i];j++)
            {
                scanf("%d%d",&job[i][j].machine,&job[i][j].len);
            }
        }
        init();
        int antnum=totalStep*2;
        Ant ant[antnum+5];
        Ant bestAnt;
        int bstime = 999999;
        for (int sl=0;sl<10;sl++)
        {
            //printf("%d/10\n",sl);
            srand(time(0));
            memset(ant,0,sizeof(ant));
            for (int i=0;i<antnum;i++)//第i只蚂蚁的旅程
            {
                //printf("sl=%d/%d\n",i,antnum);
                    int nowJob=SUPER_START; //作为图的超级源点
                    ant[i].JobStep[nowJob]=SUPER_START;
                for (int j=0;j<totalStep;j++)
                {
                    int allpre=0;

                    for (int k=0;k<m;k++)
                    {
                        //printf("i:%d j:%d k:%d l:%d ant:%d\n",nowJob,ant[i].JobStep[nowJob],k,ant[i].JobStep[k],i);
                        if (ant[i].JobStep[k]==Step[k]) continue;
                        allpre += phe[nowJob][ ant[i].JobStep[nowJob] ][k][ ant[i].JobStep[k] ];
                    }
                    //printf("%d\n",allpre);
                    int randSelectNum = rand()*rand() % allpre;//printf("OK\n");
                    //printf("摇到的数字是：%d\n",randSelectNum);
                    int select=0;
                    while (randSelectNum>=0)
                    {
                        if (ant[i].JobStep[select]==Step[select]) {select++;continue;}
                        randSelectNum -= phe[nowJob][ ant[i].JobStep[nowJob] ][select][ ant[i].JobStep[select] ];
                        select++;
                    }
                    select--;
                    //printf("蚂蚁选择了%d\n",select);
                     //蚂蚁选中的任务
                    ant[i].path[ant[i].pathlen]=select;
                    ant[i].paths[ant[i].pathlen++].get(select,ant[i].JobStep[select]);
                    ant[i].JobStep[select]++;
                    nowJob = select;
                    //printf("选择任务%d 阶段%d\n",select,ant[i].JobStep[select]);
                }
            }

            Dissipation(); //每次蚂蚁行走完后，信息素都会消散

            for (int i = 0; i < antnum; i++)
            {
                int ans = timeCalcu(ant[i].path,false);
                if (ans<bstime && totalStep<=ans)
                {
                    bstime = ans;
                    bestAnt = ant[i];
                }
                int reward = 2000/ans; //答案越小，奖励越多。
                for (int j=0;j<ant[i].pathlen-1;j++)
                {
                    int a = ant[i].paths[j].i;
                    int b = ant[i].paths[j].j;
                    int c = ant[i].paths[j+1].i;
                    int d = ant[i].paths[j+1].j;

                    phe[a][b][c][d] += reward;
                }
            }
        }
        printf("bestTime:%d\n",bstime);
        printf("甘特图：\n");
        timeCalcu(bestAnt.path,true);
        printf("加工顺序为：");
        for (int i=0;i<totalStep;i++)
            printf("%d%s",bestAnt.path[i]+1,i==totalStep-1?"\n":"->");
        return 0;
    }
}

