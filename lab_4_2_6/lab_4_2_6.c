#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//����������� ����� ������ �� ����� �� � ����
void smen(int j,char fail[j])
{
	char smen=fail[0];
	char smen2;
	for(int i=0;i<j;++i)
	{
    if(i==j-1)
	{fail[0]=smen;return;}
	smen2=fail[i+1];
	fail[i+1]=smen;
	smen=smen2;
	}
}


int _tmain(int argc, _TCHAR* argv[]) 
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
FILE *fp;

if((fp=fopen("E:\\text.txt","r"))==NULL)
{
	printf("������ ��� �������� ����� ��� ������");
	getch();
	exit(EXIT_FAILURE);
}
// ����� ���-�� ���� � �����
 char ch=getc(fp);
 int j=0;
 char aa;
 while(ch!=EOF)
 {
++j;
ch=getc(fp);
 }
fseek(fp,0L,SEEK_SET);
int n;

char fail[j];
for(int i=0;i<j;++i)
fail[i]=getc(fp);

printf("��������� ����:");
puts(fail);

printf("�� ������� �� ������ �������� ���� ������
? ��  ");
if((scanf("%d",&n)!=1&&j>n)||(aa=getchar())!='\n')
{
	printf("������ ��� �����");
	getch();
	return 0;
}


fseek(fp,0L,SEEK_SET);

for(int i=0;i<n;++i)
smen(j,fail);
if(fclose(fp)!=0)
printf("������ ��� �������� ����� ��� ������");

if((fp=fopen("E:\\text.txt","w"))==NULL)
{
	printf("������ ��� �������� ����� ��� ������");
	getch();
	exit(EXIT_FAILURE);
}

fprintf(fp,"%s",fail);
printf("������������ ����:");
puts(fail);

if(fclose(fp)!=0)
printf("������ ��� �������� ����� ��� ������");



	getch();
	return 0;
}
