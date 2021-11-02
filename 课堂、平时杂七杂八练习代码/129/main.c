//OJ 1321 Ä¾°ôºÍÈý½ÇÐÎ


#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        int bor[4] = {0};
        scanf("%d %d %d %d", &bor[0], &bor[1], &bor[2], &bor[3]);
        int a, b, c;
        int statu = 2;
        //0 == T  1 == S   2 == I
        for(int i = 0; i < 4; i ++)
        {
            a = bor[i];
            for(int j = 0; j < 4; j ++)
            {
                if(j == i)
                    continue;
                b = bor[j];
                for(int k = 0; k < 4; k ++)
                {
                    if(k == j || k == i)
                        continue;
                    c = bor[k];
                    if(a + b > c && a + c > b && b + c > a)
                    {
                        statu = 0;
                    }
                    else if(a + b == c || a + c == b || b + c == a)
                    {
                        if(statu != 0)
                            statu = 1;
                    }
                }
            }
        }
        switch(statu)
        {
            case 0:
                printf("T\n");
                break;
            case 1:
                printf("S\n");
                break;
            case 2:
                printf("I\n");
                break;
        }
    }
}
