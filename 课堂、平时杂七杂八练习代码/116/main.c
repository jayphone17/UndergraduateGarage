#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int x1,t1,x2,t2,w;
    while(~scanf("%d%d%d%d%d",&x1,&t1,&x2,&t2,&w))
    {
      float Vshun,Vni;
      float time;
      Vshun=x1*1.0/t1;
      Vni=x2*1.0/t2;
      float Vshui,Vchuan;
      Vchuan=(Vshun+Vni)*1.0/2;
      Vshui=Vshun*1.0-Vchuan*1.0;
      //printf("顺流的速度为%d 逆流的速度为%d 静止时的速度为%d 水速为%d",Vshun,Vni,Vchuan,Vshui);
      if(Vchuan>Vshui) //船能保持垂直岸边渡河
      {
        time=w*1.0/sqrt(Vchuan*Vchuan-Vshui*Vshui);
        printf("%.2f\n",time);
      }

    }
    return 0;
}
