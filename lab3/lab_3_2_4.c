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

int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
int str,stlb;
char aa;
//������������� ������ �������
printf("������� ���������� �����:");
if(scanf("%d",&str)!=1||(aa=getchar())!='\n')
{printf("������ ��� ����� �����");getch();return 0;}
printf("������� ���������� ��������:");
if(scanf("%d",&stlb)!=1||(aa=getchar())!='\n')
{printf("������ ��� ����� ��������");getch();return 0;}

//������� �������
int **mat;
mat=(int**)malloc(str*sizeof(int*));
if (mat == NULL)
{
puts("He ������� �������� ������. ��������� ���������.");
exit(EXIT_FAILURE);
}
for(int i=0;i<str;++i)
{
mat[i]=(int*)malloc(stlb*sizeof(int));
if (mat[i] == NULL)
{
puts("He ������� �������� ������. ��������� ���������.");
exit(EXIT_FAILURE);
}
}

 //��������� �������
 for(int i=0;i<str;++i)
 for(int j=0;j<stlb;++j)
 {
 printf("mat[%d][%d]=",i,j);
 if(scanf("%d",&mat[i][j])!=1||(aa=getchar())!='\n')
 {printf("(lol) ");
 fflush (stdin);
 mat[i][j]=0;
 printf("%d\n",mat[i][j]);}
 }


 int a[str];
 _Bool bb;
 _Bool bob=1;

//�������� �� ��������� ��������
for(int i=0;i<stlb;++i)
{
	  for(int j=0;j<stlb;++j)
	  {
if(i==j||i>j)
	continue;
bb=1;

for(int q=0;q<str;++q)
	a[q]=-1;

for(int g=0;g<str;++g)
	for(int u=0;u<str;++u)
		if(mat[g][i]==mat[u][j]&&a[u]!=1)
			{
			a[u]=1;
			break;
			}

for(int q=0;q<str;++q)
   if(a[q]==-1)
		{bb=0;break;}

if(bb==1)
   {
   printf("������� %d � %d ������\n",i+1,j+1);
   bob=0;
   }
	  }
}
if(bob==1)
printf("������� �������� ���");
	 for(int i=0;i<str;++i)
 free(mat[i]);
 free(mat);


	getch();
	return 0;
}
