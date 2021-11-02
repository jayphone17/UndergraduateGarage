#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int n, i, k;
    char s1[101], s2[101], d1[101], d2[101];

    while(gets(s1))
    {
        gets(s2);
        if(strlen(s1)==0 && strlen(s2)==0)printf("YES\n");
        else
        {
            k = 0;
            for(i = 0 ; s1[i]!='\0' ; i++)
            {
                if(s1[i]>='0' && s1[i]<='9') d1[k++] = s1[i];
                if(s1[i]>='a' && s1[i]<='z') d1[k++] = s1[i];
                if(s1[i]>='A' && s1[i]<='Z') d1[k++] = s1[i]-'A'+'a';
            }
            d1[k] = '\0';
            k = 0 ;
            for(i = 0 ; s2[i]!='\0' ; i++)
            {
                if(s2[i]>='0' && s2[i]<='9') d2[k++] = s2[i];
                if(s2[i]>='a' && s2[i]<='z') d2[k++] = s2[i];
                if(s2[i]>='A' && s2[i]<='Z') d2[k++] = s2[i]-'A'+'a';
            }
            d2[k] = '\0';
            if(strcmp(d1,d2) == 0)printf("YES\n");
            else printf("NO\n");
        }
    }
    //system("PAUSE");
    return 0;
}
