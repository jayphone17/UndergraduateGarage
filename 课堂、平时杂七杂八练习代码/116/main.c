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
      //printf("˳�����ٶ�Ϊ%d �������ٶ�Ϊ%d ��ֹʱ���ٶ�Ϊ%d ˮ��Ϊ%d",Vshun,Vni,Vchuan,Vshui);
      if(Vchuan>Vshui) //���ܱ��ִ�ֱ���߶ɺ�
      {
        time=w*1.0/sqrt(Vchuan*Vchuan-Vshui*Vshui);
        printf("%.2f\n",time);
      }

    }
    return 0;
}
