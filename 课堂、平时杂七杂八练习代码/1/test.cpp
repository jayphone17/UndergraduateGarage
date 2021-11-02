#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>


// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
//#pragma 是一条编译器指令,
//是给告诉编译器你要链接一些东西，
//然后在后面的comment里面导入winmm.lib库，
//有了它才可以支持对windows 多媒体的编程.

#define High 700  // 游戏画面尺寸
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

IMAGE img_bk; // 背景图片

plane myplane, enemyplane;
bullet mybullet; // 子弹位置

IMAGE img_planeNormal1,img_planeNormal2; // 正常飞机图片
IMAGE img_planeExplode1,img_planeExplode2; // 爆炸飞机图片
IMAGE img_bullet1,img_bullet2; // 子弹图片
IMAGE img_enemyPlane1,img_enemyPlane2; // 敌机图片
int isExplode = 0; // 飞机是否爆炸
int score = 0; // 得分
int gameStatus = 0; // 游戏状态，0为初始菜单界面，1为正常游戏，2为结束游戏状态，3为游戏暂停

void startMenu(); // 初始菜单界面
void pauseMenu(); // 游戏暂停后菜单界面，一般按ESC键后启动该界面
void startup();  // 数据初始化	
void show();  // 显示画面
void updateWithoutInput();  // 与用户输入无关的更新
void updateWithInput();     // 与用户输入有关的更新
void gameover();     // 游戏结束、后续处理
void readRecordFile();
void writeRecordFile();

void startMenu()
{
	putimage(0,0,&img_bk);
	//显示背景
	setbkmode(TRANSPARENT);
	//设置背景模式为TRANSPARENT（透明的），即让输出的字符串或图形的背景色不可见。
	settextcolor(BLACK);
	//设置文本的颜色是黑色的
	settextstyle(50,0,_T("黑体"));
	//设置文本的字体风格是黑体

	outtextxy(Width*0.3,High*0.2,"1 进入游戏");
	outtextxy(Width*0.3,High*0.3,"2 读取游戏存档");
	outtextxy(Width*0.3,High*0.4,"3 退出游戏");
	//在对应的位置输出字符串
	
	settextcolor(BLUE);
	settextstyle(30,0,_T("黑体"));

	outtextxy(Width*0.25,High*0.6,"用鼠标控制飞机移动");
	outtextxy(Width*0.25,High*0.65,"鼠标左键发射子弹");
	outtextxy(Width*0.25,High*0.7,"按ESC暂停游戏");
	outtextxy(Width*0.25,High*0.75,"被击坠后按任意键重新开始");

	FlushBatchDraw();
	Sleep(2);

	char input;
	if(kbhit())
	{
		input=getch();
		if(input=='1')
			gameStatus=1; //1是进入游戏
		else if(input=='2')
		{
			readRecordFile();
			gameStatus = 1; //2是存档
		}
		else if (input=='3')
		{
			gameStatus=2;
			exit(0); //退出窗口，3是退出游戏
		}
	}
}

void pauseMenu()
{
	putimage(0,0,&img_bk);
	//显示背景
	setbkmode(TRANSPARENT);
	//设置背景模式为TRANSPARENT（透明的），即让输出的字符串或图形的背景色不可见。
	settextcolor(BLACK);
	//设置文本的颜色是黑色的
	settextstyle(50,0,_T("黑体"));
	//设置文本的字体风格是黑体

	outtextxy(Width*0.3,High*0.2,"1 继续游戏");
	outtextxy(Width*0.3,High*0.3,"2 保存游戏存档");
	outtextxy(Width*0.3,High*0.4,"3 退出游戏");
	//在对应的位置输出字符串
	
	settextcolor(BLUE);
	settextstyle(30,0,_T("黑体"));

	outtextxy(Width*0.25,High*0.6,"用鼠标控制飞机移动");
	outtextxy(Width*0.25,High*0.65,"鼠标左键发射子弹");
	outtextxy(Width*0.25,High*0.7,"按ESC暂停游戏");
	outtextxy(Width*0.25,High*0.75,"被击坠后按任意键重新开始");

	FlushBatchDraw();
	Sleep(2);

	char input;
	if(kbhit()) 
	{
		input=getch();
		if(input=='1')      //按1继续游戏
			gameStatus=1;
		else if(input=='2') //按2存档
		{
			writeRecordFile(); //存档函数
			gameStatus=1;
		}
		else if (input=='3') //按3退出游戏
		{
			gameStatus=2;
			exit(0);
		}
	}
}


void readRecordFile()//用来读取游戏文档的文件存档
{
    FILE *fp;
	//定义一个指向文件的指针变量
    fp= fopen ("gameRecord.dat","r");
	//将fopen函数的返回值赋给指针变量fp
    fscanf(fp,"%f %f",&myplane.x,&myplane.y);
    fscanf(fp,"%f %f",&mybullet.x,&mybullet.y);
    fscanf(fp,"%f %f",&enemyplane.x,&enemyplane.y);
    fscanf(fp,"%d %d",&isExplode,&score);
	//将上一次游戏飞机的位置，子弹的位置，敌机的位置，分数、是否撞机的信息记录下来
    fclose(fp);
	//在使用完一个文件后应该关闭他，以防止再次被误用。
}

void writeRecordFile()//储存游戏数据文件存档
{
    FILE *fp;
	//定义一个指向文件的指针变量
    fp=fopen("gameRecord.dat","w");
	//将fopen函数的返回值赋给指针变量fp
    fprintf(fp,"%f %f",&myplane.x,&myplane.y);
    fprintf(fp,"%f %f",&mybullet.x,&mybullet.y);
    fprintf(fp,"%f %f",&enemyplane.x,&enemyplane.y);
    fprintf(fp,"%d %d",&isExplode,&score);
	//将上一次游戏飞机的位置，子弹的位置，敌机的位置，分数、是否撞机的信息读取出来
    fclose(fp);
    
}


void startup()
{
	mciSendString("open D:\\game_music.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  // 循环播放

	initgraph(Width,High);
	//获取一个窗口（获取窗口句柄）
	HWND hwnd = GetHWnd();
	//设置窗口文字
	SetWindowText(hwnd,"飞机大战 v1.0");
	//窗口文字

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
	//初始化飞机的位置
	mybullet.x = myplane.x;
	mybullet.y = -85;       
	//初始化子弹射出的位置
	enemyplane.x = Width*0.5;
	enemyplane.y = 10;	      
	//初始化敌机的位置
	BeginBatchDraw();	  
	//BeginBatchDraw() 表示启用批量绘图模式，在批量绘图模式下，所有绘图语句都不会显示
	//直到执行 FlushBatchDraw() 才会把之前所有的绘图内容显示出来。
    //EndBatchDraw() 表示结束批量绘图。
	while(gameStatus==0)
	{
		startMenu();
		//初始菜单画面
	}
}

void show()
{
	while(gameStatus==3)
	{
		pauseMenu();
		//游戏暂停后的游戏画面，按ESC启动该界面。
	}

	putimage(0, 0, &img_bk);	// 显示背景	
	if (isExplode==0)
		//若飞机没有被击破，输出飞机正常的图片
	{
		putimage(myplane.x-50, myplane.y-60, &img_planeNormal1,NOTSRCERASE); // 显示正常飞机	
		putimage(myplane.x-50, myplane.y-60, &img_planeNormal2,SRCINVERT);

		putimage(mybullet.x-7, mybullet.y, &img_bullet1,NOTSRCERASE); // 显示子弹	
		putimage(mybullet.x-7, mybullet.y, &img_bullet2,SRCINVERT);
		putimage(enemyplane.x, enemyplane.y, &img_enemyPlane1,NOTSRCERASE); // 显示敌机	
		putimage(enemyplane.x, enemyplane.y, &img_enemyPlane2,SRCINVERT);
	}
	else
		//飞机被击坠，输出飞机被击坠的图片
	{
		putimage(myplane.x-50, myplane.y-60, &img_planeExplode1,NOTSRCERASE); // 显示爆炸飞机	
		putimage(myplane.x-50, myplane.y-60, &img_planeExplode2,SRCINVERT);
	}

	settextcolor(RED);              //设置字体的颜色 
	settextstyle(20,0,_T("黑体"));  //设置字体的风格

	outtextxy(Width*0.48, High*0.95, "得分：");
	char s[5];
	sprintf(s, "  %d", score);
	outtextxy(Width*0.65,High*0.95, s);

	FlushBatchDraw();
	Sleep(2);
}

void updateWithoutInput() //用来控制子弹飞行的速度，敌机下落的函数
{
	if (isExplode==0)
	{		
		if (mybullet.y>-25)           //有了这个条件子弹不用一直飞
			mybullet.y = mybullet.y-2;  //使子弹可以下落
		
		if (enemyplane.y<High-25)        //作用同上
			enemyplane.y = enemyplane.y+0.5;  //敌机下落的速度
		else
			enemyplane.y = 10;		     
		if (abs(mybullet.x-enemyplane.x)+abs(mybullet.y-enemyplane.y) < 80)  // 子弹击中敌机
		{
			enemyplane.x = rand()%Width;
			enemyplane.y = -40;
			//随机生成飞机
			mybullet.y = -85;	
			mciSendString("close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open D:\\gotEnemy.mp3 alias gemusic", NULL, 0, NULL); // 打开音乐
			mciSendString("play gemusic", NULL, 0, NULL); // 仅播放一次
			score++;
			if (score>0 && score%5==0 && score%2!=0)
				//当分数达到一定倍数的时候，会发出鼓励语音
			{
				mciSendString("close 5music", NULL, 0, NULL); // 先把前面一次的音乐关闭
				mciSendString("open D:\\5.mp3 alias 5music", NULL, 0, NULL); // 打开音乐
				mciSendString("play 5music", NULL, 0, NULL); // 仅播放一次
			}
			if (score%10==0)
			{
				mciSendString("close 10music", NULL, 0, NULL); // 先把前面一次的音乐关闭
				mciSendString("open D:\\10.mp3 alias 10music", NULL, 0, NULL); // 打开音乐
				mciSendString("play 10music", NULL, 0, NULL); // 仅播放一次
			}
		}
		
		if (abs(myplane.x-enemyplane.x)+abs(myplane.y-enemyplane.y) < 150)  // 敌机击中我们
		{
			isExplode = 1;
			mciSendString("close exmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open D:\\explode.mp3 alias exmusic", NULL, 0, NULL); // 打开音乐
			mciSendString("play exmusic", NULL, 0, NULL); // 仅播放一次		
		}
	}
}

void updateWithInput()
{
	if (isExplode==0)
	{
		MOUSEMSG m;		// 定义鼠标消息
		while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
		{
			m = GetMouseMsg();
			if(m.uMsg == WM_MOUSEMOVE)
			{
				// 飞机的位置等于鼠标所在的位置
				myplane.x = m.x;
				myplane.y = m.y;			
			}
			else if (m.uMsg == WM_LBUTTONDOWN)
			{
				// 按下鼠标左键，发射子弹
				mybullet.x = myplane.x;
				mybullet.y = myplane.y-85;
				//子弹在飞机正上方85距离发射出去
				mciSendString("close fgmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
				mciSendString("open D:\\f_gun.mp3 alias fgmusic", NULL, 0, NULL); // 打开音乐
				mciSendString("play fgmusic", NULL, 0, NULL); // 仅播放一次
			}
		}	
	}

	char input;
	if(kbhit())
	//判断是否有输入
	{
		input=getch(); //不需要回车
		if(input==27)  //ESC的ASC II 码为27
		{
			gameStatus = 3; //进入暂停界面

		}
	}
}

void gameover()
{
	EndBatchDraw();
	//表示结束批量绘图
	getch();
	closegraph();
}

int main()
{
	startup();  // 数据初始化	
	while (1)  //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
	gameover();     // 游戏结束、后续处理
	return 0;
}