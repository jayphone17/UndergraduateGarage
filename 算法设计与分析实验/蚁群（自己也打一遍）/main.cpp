#include <bits/stdc++.h>
#define maxn 60 //最大工作量
#define Initialize_Pre 3000 //道路初始信息素量
#define DIS 0.5 //信息素消散速率
#define SUPER_START 48 //超级源点
using namespace std;

int Total_Step; //总步数
int Step[maxn]; //记录步数
int Pheromone[maxn][maxn][maxn][maxn]; //信息素，费洛蒙
int n ; //工件的数量
int m; //机器的数量
const int INF=9999999;

struct Pair
{
    int i;
    int j;
    void get(int a,int b)
    {
        i=a;
        j=b;
    }
} Jobnum[maxn];

struct Job
{
    int machine; //机器数量
    int len; //加工需要的时间段
} job[maxn][maxn];

struct Ant
{
    int JobStep[maxn]; //任务已经加工的步数
    int Path[maxn]; //记录最优加工次序的数组
    int Pathlen; //长度
    int get_Full_Path()
    {
        int sum=0;
        for(int i=0; i<Pathlen; i++)
        {
            sum+=Path[i];
        }
        return sum;
    }
    Pair paths[maxn];
};

void Initialize() //初始化函数
{
    memset(Pheromone,0,sizeof(Pheromone));
    for(int i=0; i<Total_Step; i++)
    {
        for(int j=0; j<Total_Step; j++)
        {
            for(int k=0; k<Total_Step; k++)
            {
                for(int l=0; l<Total_Step; l++)
                {
                    Pheromone[i][j][k][l]=Initialize_Pre; //初始化信息素道路的信息素
                }
            }
        }
    }
    for(int i=0; i<Total_Step; i++)
    {
        for(int j=0; j<Total_Step; j++)
        {
            Pheromone[SUPER_START][SUPER_START][i][j]=Initialize_Pre;
        }
    }
    return;
}

void Dissipation() //信息素消散函数
{
    for(int i=0; i<Total_Step; i++)
    {
        for(int j=0; j<Total_Step; j++)
        {
            for(int k=0; k<Total_Step; k++)
            {
                for(int l=0; l<Total_Step; l++)
                {
                    Pheromone[i][j][k][l] *=DIS; //乘以消散率，随着时间消散
                }
            }
        }
    }
    for(int i=0; i<Total_Step; i++)
    {
        for(int j=0; j<Total_Step; j++)
        {
            Pheromone[SUPER_START][SUPER_START][i][j] *=DIS;
        }
    }
    return;
}

struct recording
{
    int start; //开始的时间
    int endd; //结束的时间
    int job; //工件
    int machine; //机器
};

int time_caculation(int Job[],bool draw) //计算需要加工的时间的函数
{
    int sum=0; //总加工时间
    int MachineWorkTime[maxn]; //机器加工时间
    int JobLast[maxn]; //加工持续时间
    int JobStep[maxn]; //加工进行到的步数
    recording rec[maxn]; //记录加工次序
    //清空数组
    memset(MachineWorkTime,0,sizeof(MachineWorkTime));
    memset(JobLast,0,sizeof(JobLast));
    memset(JobStep,0,sizeof(JobStep));
    memset(rec,0,sizeof(rec));
    for(int k=0; k<Total_Step; k++)
    {
        int i=Job[k];//记录现在加工工件的工序
        rec[k].start=max(JobLast[i],MachineWorkTime[job[i][JobStep[i]].machine]);
        //取加工顺序里面最晚加工完成的作为起始点
        rec[k].job=i;//现在加工工件的件号
        rec[k].endd=rec[k].start +job[i][JobStep[i]].len;//加工结束时间
        JobLast[i]=rec[k].endd; //持续时间
        rec[k].machine=job[i][JobStep[i]].machine; //第几个加工机器
        MachineWorkTime[job[i][JobStep[i]].machine]=rec[k].endd;
        JobStep[i]++;
    }
    for(int i=0; i<m; i++)
    {
        sum=max(sum,MachineWorkTime[i]);
    }
    if(draw==true) //甘特图绘制
    {
        int gantt[maxn][maxn];//甘特图数组
        memset(gantt,0,sizeof(gantt));//清空数组
        for(int i=0; i<Total_Step; i++)
        {
            for(int j=rec[i].start; j<rec[i].endd; j++)
            {
                gantt[rec[i].machine][j]=rec[i].job+1;
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<sum; j++)
            {
                printf("%d%c",gantt[i][j],j==sum-1?'\n':' '); //输出甘特图
            }
        }
    }
    return sum; //返回总加工时间
}

int main()
{
    cout << "请输入工件的数量以及机器的数量:"<< endl;
    while(cin >> n >> m)
    {
        Total_Step=0;
        for(int i=0; i<n; i++)
        {
            cout << "请输入加工所需要的步骤数量:"<< endl;
            cin >> Step[i];
            Total_Step+=Step[i];
            cout << "请输入需要在其加工的机器号码以及所需要加工的时间:"<< endl;
            for(int j=0; j<Step[i]; j++)
            {
                cin >> job[i][j].machine >> job[i][j].len;
            }
        }
        Initialize(); //初始化信息素
        //这部分是蚂蚁行走部分
        int antnum=Total_Step*2;//蚂蚁数量
        Ant ant[antnum+5];
        Ant bestAnt;
        int Best_Process_Time=INF;
        for(int i=0; i<10; i++)
        {
            srand(time(0)); //初始化随机数发生器，并且设置启动种子。生成随机数
            memset(ant,0,sizeof(ant));
            for(int j=0; j<antnum; j++) //第j只蚂蚁的旅程。
            {
                int nowJob=SUPER_START;//作为图的超级源点
                ant[i].JobStep[nowJob]=SUPER_START;
                for(int k=0; k<Total_Step; k++)
                {
                    int allpre=0;
                    for(int l=0; l<m; l++)
                    {
                        if(ant [i].JobStep[l]==Step[l])
                        {
                            continue;
                        }
                        allpre+=Pheromone[nowJob][ant[i].JobStep[nowJob]][l][ant[i].JobStep[l]];
                    }
                    int randSelectNum=rand()*rand()%allpre;
                    int select=0;
                    while(randSelectNum>=0)
                    {
                        if(ant[i].JobStep[select]==Step[select])
                        {
                            select++;
                            continue;
                        }
                        randSelectNum -= Pheromone[nowJob][ ant[i].JobStep[nowJob] ][select][ ant[i].JobStep[select] ];
                        select++;
                    }
                    select--;
                    ant[i].Path[ant[i].Pathlen]=select;
                    ant[i].paths[ant[i].Pathlen++].get(select,ant[i].JobStep[select]);
                    //ant[i].JobStep[select]++;
                    nowJob=select;
                }
            }
            Dissipation();//每次蚂蚁行走完之后，信息素都会消散
            //这部分是反馈部分
            for(int i=0; i<antnum; i++)
            {
                int ans=time_caculation(ant[i].Path,false);
                if(ans <Best_Process_Time && Total_Step <=ans)
                {
                    Best_Process_Time =ans;
                    bestAnt=ant[i];
                }
                int reward =2000/ans; //回馈机制中的回馈，数字越小，回馈越大。
                for(int j=0; j<ant[i].Pathlen-1; j++)
                {
                    int a=ant[i].paths[j].i;
                    int b=ant[i].paths[j].j;
                    int c=ant[i].paths[j+1].i;
                    int d=ant[i].paths[j+1].j;
                    Pheromone[a][b][c][d]+=reward;
                }
            }
            cout << "最佳的加工时间是："<< Best_Process_Time << endl;
            cout << "甘特图是："<< endl;
            time_caculation(bestAnt.Path,true);
            cout << "加工顺序是："<< endl;
            for(int i=0; i<Total_Step; i++)
            {
                printf("%d%s",bestAnt.Path[i]+1,i==Total_Step-1?"\n":"->");
            }
        }
        return 0;
    }
}
