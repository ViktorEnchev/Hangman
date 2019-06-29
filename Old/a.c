#include <stdio.h>
#include <string.h>

void squeeze(char *s, int c);
int readFile(FILE *fp, char *fileName, float *s);
int main()
{
    char string[] = "Tests examples", *pString;
    FILE *pFile = NULL;
    float sar;
    int res;
    printf("1. ");
    for(pString=string+strlen(string)-1;pString>=string;pString--){
        printf("%c",*pString);
        printf("\n");
        printf("2. ");
        pString = string;
        while(*pString != '\0')
        {
            printf("%c", *pString);
            pString++;
        }
        printf("\n");
        printf("3. ");
        pString = string + 6;
        printf("%c \n", *pString);
        printf("4. ");
        squeeze(string, 's');
        printf("%s\n",string);
        printf("5. ");
        res = readFile(pFile, "a.txt", &sar);
        if(res ==0)
        {
            printf("Error!");
            return 1;
        }
        printf("%.2f\n", sar);
        return 0;
    }
}

void squeeze(char *s, int c)
{
    char *p;
    p = s;
    while(*s != '\0')
    {
        if(*s != c)
        {
            *p = *s;
            p++;
        }
        s++;
    }
    *p = '\0';
}

int readFile(FILE *fp, char *fileName, float *s)
{
    int x,count= 0;
    fp=fopen(fileName, "r");
    if(fp==NULL)
        return 0;
    *s = 0;
    while(fscanf(fp, "%d", &x) != EOF)
    {
        if(x%2!=0)
        {
            *s += x;
            count++;
        }
    }
    fclose(fp);
    if(count){
        *s /=count;
    }
    return 1;
}