#include <bits/stdc++.h>
#define maxn 60 //�������
#define Initialize_Pre 3000 //��·��ʼ��Ϣ����
#define DIS 0.5 //��Ϣ����ɢ����
#define SUPER_START 48 //����Դ��
using namespace std;

int Total_Step; //�ܲ���
int Step[maxn]; //��¼����
int Pheromone[maxn][maxn][maxn][maxn]; //��Ϣ�أ�������
int n ; //����������
int m; //����������
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
    int machine; //��������
    int len; //�ӹ���Ҫ��ʱ���
} job[maxn][maxn];

struct Ant
{
    int JobStep[maxn]; //�����Ѿ��ӹ��Ĳ���
    int Path[maxn]; //��¼���żӹ����������
    int Pathlen; //����
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

void Initialize() //��ʼ������
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
                    Pheromone[i][j][k][l]=Initialize_Pre; //��ʼ����Ϣ�ص�·����Ϣ��
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

void Dissipation() //��Ϣ����ɢ����
{
    for(int i=0; i<Total_Step; i++)
    {
        for(int j=0; j<Total_Step; j++)
        {
            for(int k=0; k<Total_Step; k++)
            {
                for(int l=0; l<Total_Step; l++)
                {
                    Pheromone[i][j][k][l] *=DIS; //������ɢ�ʣ�����ʱ����ɢ
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
    int start; //��ʼ��ʱ��
    int endd; //������ʱ��
    int job; //����
    int machine; //����
};

int time_caculation(int Job[],bool draw) //������Ҫ�ӹ���ʱ��ĺ���
{
    int sum=0; //�ܼӹ�ʱ��
    int MachineWorkTime[maxn]; //�����ӹ�ʱ��
    int JobLast[maxn]; //�ӹ�����ʱ��
    int JobStep[maxn]; //�ӹ����е��Ĳ���
    recording rec[maxn]; //��¼�ӹ�����
    //�������
    memset(MachineWorkTime,0,sizeof(MachineWorkTime));
    memset(JobLast,0,sizeof(JobLast));
    memset(JobStep,0,sizeof(JobStep));
    memset(rec,0,sizeof(rec));
    for(int k=0; k<Total_Step; k++)
    {
        int i=Job[k];//��¼���ڼӹ������Ĺ���
        rec[k].start=max(JobLast[i],MachineWorkTime[job[i][JobStep[i]].machine]);
        //ȡ�ӹ�˳����������ӹ���ɵ���Ϊ��ʼ��
        rec[k].job=i;//���ڼӹ������ļ���
        rec[k].endd=rec[k].start +job[i][JobStep[i]].len;//�ӹ�����ʱ��
        JobLast[i]=rec[k].endd; //����ʱ��
        rec[k].machine=job[i][JobStep[i]].machine; //�ڼ����ӹ�����
        MachineWorkTime[job[i][JobStep[i]].machine]=rec[k].endd;
        JobStep[i]++;
    }
    for(int i=0; i<m; i++)
    {
        sum=max(sum,MachineWorkTime[i]);
    }
    if(draw==true) //����ͼ����
    {
        int gantt[maxn][maxn];//����ͼ����
        memset(gantt,0,sizeof(gantt));//�������
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
                printf("%d%c",gantt[i][j],j==sum-1?'\n':' '); //�������ͼ
            }
        }
    }
    return sum; //�����ܼӹ�ʱ��
}

int main()
{
    cout << "�����빤���������Լ�����������:"<< endl;
    while(cin >> n >> m)
    {
        Total_Step=0;
        for(int i=0; i<n; i++)
        {
            cout << "������ӹ�����Ҫ�Ĳ�������:"<< endl;
            cin >> Step[i];
            Total_Step+=Step[i];
            cout << "��������Ҫ����ӹ��Ļ��������Լ�����Ҫ�ӹ���ʱ��:"<< endl;
            for(int j=0; j<Step[i]; j++)
            {
                cin >> job[i][j].machine >> job[i][j].len;
            }
        }
        Initialize(); //��ʼ����Ϣ��
        //�ⲿ�����������߲���
        int antnum=Total_Step*2;//��������
        Ant ant[antnum+5];
        Ant bestAnt;
        int Best_Process_Time=INF;
        for(int i=0; i<10; i++)
        {
            srand(time(0)); //��ʼ������������������������������ӡ����������
            memset(ant,0,sizeof(ant));
            for(int j=0; j<antnum; j++) //��jֻ���ϵ��ó̡�
            {
                int nowJob=SUPER_START;//��Ϊͼ�ĳ���Դ��
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
            Dissipation();//ÿ������������֮����Ϣ�ض�����ɢ
            //�ⲿ���Ƿ�������
            for(int i=0; i<antnum; i++)
            {
                int ans=time_caculation(ant[i].Path,false);
                if(ans <Best_Process_Time && Total_Step <=ans)
                {
                    Best_Process_Time =ans;
                    bestAnt=ant[i];
                }
                int reward =2000/ans; //���������еĻ���������ԽС������Խ��
                for(int j=0; j<ant[i].Pathlen-1; j++)
                {
                    int a=ant[i].paths[j].i;
                    int b=ant[i].paths[j].j;
                    int c=ant[i].paths[j+1].i;
                    int d=ant[i].paths[j+1].j;
                    Pheromone[a][b][c][d]+=reward;
                }
            }
            cout << "��ѵļӹ�ʱ���ǣ�"<< Best_Process_Time << endl;
            cout << "����ͼ�ǣ�"<< endl;
            time_caculation(bestAnt.Path,true);
            cout << "�ӹ�˳���ǣ�"<< endl;
            for(int i=0; i<Total_Step; i++)
            {
                printf("%d%s",bestAnt.Path[i]+1,i==Total_Step-1?"\n":"->");
            }
        }
        return 0;
    }
}
