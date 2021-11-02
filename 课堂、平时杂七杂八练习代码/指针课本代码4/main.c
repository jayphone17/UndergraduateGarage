#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#pragma comment(lib,"Winmm.lib")


void misic()
{
    mciSendString("open D://Genji's Ultimate.mp3 alias bkmusic);
    mciSendString("play bkmusic repeat",NULL,0,NULL);
}

int main()
{
    char input;
    if(kbhit())
    {
        input=getch();
        if(input == '1' )
            music();
    }
    return 0;
}
