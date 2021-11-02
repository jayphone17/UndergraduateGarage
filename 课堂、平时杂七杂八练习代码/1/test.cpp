#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>


// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
//#pragma ��һ��������ָ��,
//�Ǹ����߱�������Ҫ����һЩ������
//Ȼ���ں����comment���浼��winmm.lib�⣬
//�������ſ���֧�ֶ�windows ��ý��ı��.

#define High 700  // ��Ϸ����ߴ�
#define Width 580

struct plane
{
	float x;
	float y;
};

struct bullet
{
	float x;
	float y;
};

IMAGE img_bk; // ����ͼƬ

plane myplane, enemyplane;
bullet mybullet; // �ӵ�λ��

IMAGE img_planeNormal1,img_planeNormal2; // �����ɻ�ͼƬ
IMAGE img_planeExplode1,img_planeExplode2; // ��ը�ɻ�ͼƬ
IMAGE img_bullet1,img_bullet2; // �ӵ�ͼƬ
IMAGE img_enemyPlane1,img_enemyPlane2; // �л�ͼƬ
int isExplode = 0; // �ɻ��Ƿ�ը
int score = 0; // �÷�
int gameStatus = 0; // ��Ϸ״̬��0Ϊ��ʼ�˵����棬1Ϊ������Ϸ��2Ϊ������Ϸ״̬��3Ϊ��Ϸ��ͣ

void startMenu(); // ��ʼ�˵�����
void pauseMenu(); // ��Ϸ��ͣ��˵����棬һ�㰴ESC���������ý���
void startup();  // ���ݳ�ʼ��	
void show();  // ��ʾ����
void updateWithoutInput();  // ���û������޹صĸ���
void updateWithInput();     // ���û������йصĸ���
void gameover();     // ��Ϸ��������������
void readRecordFile();
void writeRecordFile();

void startMenu()
{
	putimage(0,0,&img_bk);
	//��ʾ����
	setbkmode(TRANSPARENT);
	//���ñ���ģʽΪTRANSPARENT��͸���ģ�������������ַ�����ͼ�εı���ɫ���ɼ���
	settextcolor(BLACK);
	//�����ı�����ɫ�Ǻ�ɫ��
	settextstyle(50,0,_T("����"));
	//�����ı����������Ǻ���

	outtextxy(Width*0.3,High*0.2,"1 ������Ϸ");
	outtextxy(Width*0.3,High*0.3,"2 ��ȡ��Ϸ�浵");
	outtextxy(Width*0.3,High*0.4,"3 �˳���Ϸ");
	//�ڶ�Ӧ��λ������ַ���
	
	settextcolor(BLUE);
	settextstyle(30,0,_T("����"));

	outtextxy(Width*0.25,High*0.6,"�������Ʒɻ��ƶ�");
	outtextxy(Width*0.25,High*0.65,"�����������ӵ�");
	outtextxy(Width*0.25,High*0.7,"��ESC��ͣ��Ϸ");
	outtextxy(Width*0.25,High*0.75,"����׹����������¿�ʼ");

	FlushBatchDraw();
	Sleep(2);

	char input;
	if(kbhit())
	{
		input=getch();
		if(input=='1')
			gameStatus=1; //1�ǽ�����Ϸ
		else if(input=='2')
		{
			readRecordFile();
			gameStatus = 1; //2�Ǵ浵
		}
		else if (input=='3')
		{
			gameStatus=2;
			exit(0); //�˳����ڣ�3���˳���Ϸ
		}
	}
}

void pauseMenu()
{
	putimage(0,0,&img_bk);
	//��ʾ����
	setbkmode(TRANSPARENT);
	//���ñ���ģʽΪTRANSPARENT��͸���ģ�������������ַ�����ͼ�εı���ɫ���ɼ���
	settextcolor(BLACK);
	//�����ı�����ɫ�Ǻ�ɫ��
	settextstyle(50,0,_T("����"));
	//�����ı����������Ǻ���

	outtextxy(Width*0.3,High*0.2,"1 ������Ϸ");
	outtextxy(Width*0.3,High*0.3,"2 ������Ϸ�浵");
	outtextxy(Width*0.3,High*0.4,"3 �˳���Ϸ");
	//�ڶ�Ӧ��λ������ַ���
	
	settextcolor(BLUE);
	settextstyle(30,0,_T("����"));

	outtextxy(Width*0.25,High*0.6,"�������Ʒɻ��ƶ�");
	outtextxy(Width*0.25,High*0.65,"�����������ӵ�");
	outtextxy(Width*0.25,High*0.7,"��ESC��ͣ��Ϸ");
	outtextxy(Width*0.25,High*0.75,"����׹����������¿�ʼ");

	FlushBatchDraw();
	Sleep(2);

	char input;
	if(kbhit()) 
	{
		input=getch();
		if(input=='1')      //��1������Ϸ
			gameStatus=1;
		else if(input=='2') //��2�浵
		{
			writeRecordFile(); //�浵����
			gameStatus=1;
		}
		else if (input=='3') //��3�˳���Ϸ
		{
			gameStatus=2;
			exit(0);
		}
	}
}


void readRecordFile()//������ȡ��Ϸ�ĵ����ļ��浵
{
    FILE *fp;
	//����һ��ָ���ļ���ָ�����
    fp= fopen ("gameRecord.dat","r");
	//��fopen�����ķ���ֵ����ָ�����fp
    fscanf(fp,"%f %f",&myplane.x,&myplane.y);
    fscanf(fp,"%f %f",&mybullet.x,&mybullet.y);
    fscanf(fp,"%f %f",&enemyplane.x,&enemyplane.y);
    fscanf(fp,"%d %d",&isExplode,&score);
	//����һ����Ϸ�ɻ���λ�ã��ӵ���λ�ã��л���λ�ã��������Ƿ�ײ������Ϣ��¼����
    fclose(fp);
	//��ʹ����һ���ļ���Ӧ�ùر������Է�ֹ�ٴα����á�
}

void writeRecordFile()//������Ϸ�����ļ��浵
{
    FILE *fp;
	//����һ��ָ���ļ���ָ�����
    fp=fopen("gameRecord.dat","w");
	//��fopen�����ķ���ֵ����ָ�����fp
    fprintf(fp,"%f %f",&myplane.x,&myplane.y);
    fprintf(fp,"%f %f",&mybullet.x,&mybullet.y);
    fprintf(fp,"%f %f",&enemyplane.x,&enemyplane.y);
    fprintf(fp,"%d %d",&isExplode,&score);
	//����һ����Ϸ�ɻ���λ�ã��ӵ���λ�ã��л���λ�ã��������Ƿ�ײ������Ϣ��ȡ����
    fclose(fp);
    
}


void startup()
{
	mciSendString("open D:\\game_music.mp3 alias bkmusic", NULL, 0, NULL);//�򿪱�������
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // ѭ������

	initgraph(Width,High);
	//��ȡһ�����ڣ���ȡ���ھ����
	HWND hwnd = GetHWnd();
	//���ô�������
	SetWindowText(hwnd,"�ɻ���ս v1.0");
	//��������

	loadimage(&img_bk, "D:\\background.jpg");
	loadimage(&img_planeNormal1, "D:\\planeNormal_1.jpg");
	loadimage(&img_planeNormal2, "D:\\planeNormal_2.jpg");
	loadimage(&img_bullet1, "D:\\bullet1.jpg");
	loadimage(&img_bullet2, "D:\\bullet2.jpg");
	loadimage(&img_enemyPlane1, "D:\\enemyPlane1.jpg");
	loadimage(&img_enemyPlane2, "D:\\enemyPlane2.jpg");
	loadimage(&img_planeExplode1, "D:\\planeExplode_1.jpg");
	loadimage(&img_planeExplode2, "D:\\planeExplode_2.jpg");

	myplane.x = Width*0.5;
	myplane.y = High*0.7;
	//��ʼ���ɻ���λ��
	mybullet.x = myplane.x;
	mybullet.y = -85;       
	//��ʼ���ӵ������λ��
	enemyplane.x = Width*0.5;
	enemyplane.y = 10;	      
	//��ʼ���л���λ��
	BeginBatchDraw();	  
	//BeginBatchDraw() ��ʾ����������ͼģʽ����������ͼģʽ�£����л�ͼ��䶼������ʾ
	//ֱ��ִ�� FlushBatchDraw() �Ż��֮ǰ���еĻ�ͼ������ʾ������
    //EndBatchDraw() ��ʾ����������ͼ��
	while(gameStatus==0)
	{
		startMenu();
		//��ʼ�˵�����
	}
}

void show()
{
	while(gameStatus==3)
	{
		pauseMenu();
		//��Ϸ��ͣ�����Ϸ���棬��ESC�����ý��档
	}

	putimage(0, 0, &img_bk);	// ��ʾ����	
	if (isExplode==0)
		//���ɻ�û�б����ƣ�����ɻ�������ͼƬ
	{
		putimage(myplane.x-50, myplane.y-60, &img_planeNormal1,NOTSRCERASE); // ��ʾ�����ɻ�	
		putimage(myplane.x-50, myplane.y-60, &img_planeNormal2,SRCINVERT);

		putimage(mybullet.x-7, mybullet.y, &img_bullet1,NOTSRCERASE); // ��ʾ�ӵ�	
		putimage(mybullet.x-7, mybullet.y, &img_bullet2,SRCINVERT);
		putimage(enemyplane.x, enemyplane.y, &img_enemyPlane1,NOTSRCERASE); // ��ʾ�л�	
		putimage(enemyplane.x, enemyplane.y, &img_enemyPlane2,SRCINVERT);
	}
	else
		//�ɻ�����׹������ɻ�����׹��ͼƬ
	{
		putimage(myplane.x-50, myplane.y-60, &img_planeExplode1,NOTSRCERASE); // ��ʾ��ը�ɻ�	
		putimage(myplane.x-50, myplane.y-60, &img_planeExplode2,SRCINVERT);
	}

	settextcolor(RED);              //�����������ɫ 
	settextstyle(20,0,_T("����"));  //��������ķ��

	outtextxy(Width*0.48, High*0.95, "�÷֣�");
	char s[5];
	sprintf(s, "  %d", score);
	outtextxy(Width*0.65,High*0.95, s);

	FlushBatchDraw();
	Sleep(2);
}

void updateWithoutInput() //���������ӵ����е��ٶȣ��л�����ĺ���
{
	if (isExplode==0)
	{		
		if (mybullet.y>-25)           //������������ӵ�����һֱ��
			mybullet.y = mybullet.y-2;  //ʹ�ӵ���������
		
		if (enemyplane.y<High-25)        //����ͬ��
			enemyplane.y = enemyplane.y+0.5;  //�л�������ٶ�
		else
			enemyplane.y = 10;		     
		if (abs(mybullet.x-enemyplane.x)+abs(mybullet.y-enemyplane.y) < 80)  // �ӵ����ел�
		{
			enemyplane.x = rand()%Width;
			enemyplane.y = -40;
			//������ɷɻ�
			mybullet.y = -85;	
			mciSendString("close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open D:\\gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // ������
			mciSendString("play gemusic", NULL, 0, NULL); // ������һ��
			score++;
			if (score>0 && score%5==0 && score%2!=0)
				//�������ﵽһ��������ʱ�򣬻ᷢ����������
			{
				mciSendString("close 5music", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
				mciSendString("open D:\\5.mp3 alias 5music", NULL, 0, NULL); // ������
				mciSendString("play 5music", NULL, 0, NULL); // ������һ��
			}
			if (score%10==0)
			{
				mciSendString("close 10music", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
				mciSendString("open D:\\10.mp3 alias 10music", NULL, 0, NULL); // ������
				mciSendString("play 10music", NULL, 0, NULL); // ������һ��
			}
		}
		
		if (abs(myplane.x-enemyplane.x)+abs(myplane.y-enemyplane.y) < 150)  // �л���������
		{
			isExplode = 1;
			mciSendString("close exmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open D:\\explode.mp3 alias exmusic", NULL, 0, NULL); // ������
			mciSendString("play exmusic", NULL, 0, NULL); // ������һ��		
		}
	}
}

void updateWithInput()
{
	if (isExplode==0)
	{
		MOUSEMSG m;		// ���������Ϣ
		while (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
		{
			m = GetMouseMsg();
			if(m.uMsg == WM_MOUSEMOVE)
			{
				// �ɻ���λ�õ���������ڵ�λ��
				myplane.x = m.x;
				myplane.y = m.y;			
			}
			else if (m.uMsg == WM_LBUTTONDOWN)
			{
				// �����������������ӵ�
				mybullet.x = myplane.x;
				mybullet.y = myplane.y-85;
				//�ӵ��ڷɻ����Ϸ�85���뷢���ȥ
				mciSendString("close fgmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
				mciSendString("open D:\\f_gun.mp3 alias fgmusic", NULL, 0, NULL); // ������
				mciSendString("play fgmusic", NULL, 0, NULL); // ������һ��
			}
		}	
	}

	char input;
	if(kbhit())
	//�ж��Ƿ�������
	{
		input=getch(); //����Ҫ�س�
		if(input==27)  //ESC��ASC II ��Ϊ27
		{
			gameStatus = 3; //������ͣ����

		}
	}
}

void gameover()
{
	EndBatchDraw();
	//��ʾ����������ͼ
	getch();
	closegraph();
}

int main()
{
	startup();  // ���ݳ�ʼ��	
	while (1)  //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
	gameover();     // ��Ϸ��������������
	return 0;
}