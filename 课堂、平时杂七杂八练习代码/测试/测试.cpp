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

IMAGE img_bk; // ����ͼƬ

float position_x,position_y; // �ɻ�λ��
float bullet_x,bullet_y; // �ӵ�λ��
float enemy_x,enemy_y; // �л�λ��

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
    fp= fopen (".\\gameRecord.dat","r");
    fscanf(fp,"%f %f %f %f %f %f %d %d",&position_x,&position_y,&bullet_x,&bullet_y,&enemy_x,&enemy_y,&isExplode,&score);
    fclose(fp);
}

void writeRecordFile()//������Ϸ�����ļ��浵
{
    FILE *fp;
    fp=fopen(".\\gameRecord.dat","w");
	fprintf(fp,"%f %f %f %f %f %f %d %d",&position_x,&position_y,&bullet_x,&bullet_y,&enemy_x,&enemy_y,&isExplode,&score);
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

	position_x = Width*0.5;
	position_y = High*0.7;
	//��ʼ���ɻ���λ��
	bullet_x = position_x;
	bullet_y = -85;       
	//��ʼ���ӵ������λ��
	enemy_x = Width*0.5;
	enemy_y = 10;	      
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
		putimage(position_x-50, position_y-60, &img_planeNormal1,NOTSRCERASE); // ��ʾ�����ɻ�	
		putimage(position_x-50, position_y-60, &img_planeNormal2,SRCINVERT);

		putimage(bullet_x-7, bullet_y, &img_bullet1,NOTSRCERASE); // ��ʾ�ӵ�	
		putimage(bullet_x-7, bullet_y, &img_bullet2,SRCINVERT);
		putimage(enemy_x, enemy_y, &img_enemyPlane1,NOTSRCERASE); // ��ʾ�л�	
		putimage(enemy_x, enemy_y, &img_enemyPlane2,SRCINVERT);
	}
	else
		//�ɻ�����׹������ɻ�����׹��ͼƬ
	{
		putimage(position_x-50, position_y-60, &img_planeExplode1,NOTSRCERASE); // ��ʾ��ը�ɻ�	
		putimage(position_x-50, position_y-60, &img_planeExplode2,SRCINVERT);
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
		if (bullet_y>-25)           //������������ӵ�����һֱ��
			bullet_y = bullet_y-2;  //ʹ�ӵ���������
		
		if (enemy_y<High-25)        //����ͬ��
			enemy_y = enemy_y+0.5;  //�л�������ٶ�
		else
			enemy_y = 10;		     
		if (abs(bullet_x-enemy_x)+abs(bullet_y-enemy_y) < 80)  // �ӵ����ел�
		{
			enemy_x = rand()%Width;
			enemy_y = -40;
			//������ɷɻ�
			bullet_y = -85;	
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
		
		if (abs(position_x-enemy_x)+abs(position_y-enemy_y) < 150)  // �л���������
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
				position_x = m.x;
				position_y = m.y;			
			}
			else if (m.uMsg == WM_LBUTTONDOWN)
			{
				// �����������������ӵ�
				bullet_x = position_x;
				bullet_y = position_y-85;
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
