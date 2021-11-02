#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

        printf("Man   Women   Children\n");
        for (int i=0;i<16;i++)
        {
            for(int j=0;j<25;j++)
            {
                for(int z=0;z<50;z++)
                {
                    if(i+j+z==30&&3*i+2*j+z==50)
                        printf("%3d%8d%8d\n",i,j,z);
                }
            }
        }
    return 0;
}
