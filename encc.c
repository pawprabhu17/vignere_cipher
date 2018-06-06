#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[20],b[20];
int enc(char text[],char v[])
{
	char c,r[26][26],d,e;
	int n=65;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(n<=90)
			{
				r[i][j]=(char)n;
				n++;
			}
			else
			{
				int m=65;
				r[i][j]=(char)m;
				n=m+1;
			}
		}
		n=(int)r[i][0];
		n+=1;
	}
	for(int x=0;x<strlen(text);x++)
	{
		c=text[x];
		if(c==' ')
        {
            a[x]=c;
        }
        else
        {
            int p=(int)c-65;
            d=v[x];
            int q=(int)d-65;
            e=r[p][q];
            a[x]=e;
        }
	}
	return 1;
}
int dec(char v[])
{
	char c,r[26][26],d,e;
	int n=65;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(n<=90)
			{
				r[i][j]=(char)n;
				n++;
			}
			else
			{
				int m=65;
				r[i][j]=(char)m;
				n=m+1;
			}
		}
		n=(int)r[i][25];
	}
	for(int x=0;x<strlen(a);x++)
	{
		c=a[x];
		if(c==' ')
            b[x]=c;
        else
        {
            int p=(int)c-65;
            d=v[x];
            int q=(int)d-65;
            e=r[q][p];
            b[x]=e;
        }
	}
	return 1;
}
void main()
{
	int ch;
	char text[20],k[20];
	printf("enter the text\n");
	gets(text);
    printf("\n");
	printf("enter the key\n");
    int i=0;
    while(i<strlen(text))
    {   if(text[i]==' ')
           i++;
        scanf(" %c",&k[i]);
        i++;
    }
	while(1)
	{
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enc(text,k);
				break;
			case 2:dec(k);
				break;
            case 3:printf("enc code:\t");
                    for(int i=0;i<strlen(a);i++)
                        printf("%c",a[i]);
                        printf("\n");
                    break;
            case 4:printf("dec code:\t");
                    for(int i=0;i<strlen(b);i++)
                        printf("%c",b[i]);
                        printf("\n");
                break;
			default:exit(0);
		}
	}
}
