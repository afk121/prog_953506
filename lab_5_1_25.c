#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif




typedef struct stag
{
	int* mass;
	size_t size;
	size_t top;
} Stag;

void menu()
{
system("cls");
 printf("����: ��� ��������� �������\n1 - ���� ����� � ����\n2 - ����� ����� �� ����� � ���������\n3 - ����� ����� ����� ��� �������� \n");
 printf("4 - ����� ���� ����� �����\n5- ����� ������� �����\n6 - ������ �����\n7 - ����� �� ���������\n(���� �� ������� ���-���� ������, ��������� ����������)\n(�������� ������ ������ ������!!!��� ��������� ������ ���������)\n ");

}


Stag* createSt()
{
  Stag* out=NULL;
   out = malloc(sizeof(Stag));
	if (out == NULL) {
	printf("������ ��� �������� ����� #1");
		exit(0);
	}
	out->size=6;
  out->mass=(int*)malloc(6*sizeof(int));
  if(out->mass==NULL)
  {
	 printf("������ ��� �������� ����� #2");
	 exit(0);
  }
  out->top=0;
  return out;
}

void deleteS(Stag **st)
{
	free((*st)->mass);
	free(*st);
	*st=NULL;
	printf("���� ������");
	getch();
	return;
}
void resize(Stag* st)
{
  st->size+=4;
  st->mass=(int*)realloc(st->mass,st->size*sizeof(int));
  if(st->mass==NULL){
  printf("������ ��� ���������� ������� �����");
	 exit(0);
  }
}

void push(Stag* st)
{
char aa;
system("cls");
printf("������� �����:");
fflush (stdin);
if(scanf("%d",&st->mass[st->top])!=1||((aa=getchar())!='\n'))
{
	if(st->top==st->size)
	resize(st);
	printf("�������� ����");
	fflush (stdin);
	getch();
	return;
}
++st->top;
fflush (stdin);
}

void pop(Stag* st)
{
system("cls");
  if(st->top==0)
  {printf("���� ����");
  getch();
  return;}
  --st->top;
  printf("����� � �����:%d",(int)st->mass[st->top]);
  getch();
}

void peek(Stag* st)
{
  system("cls");
  if(st->top==0)
  {printf("���� ����");
  getch();
  return;}
  printf("����� � �����:%d",(int)st->mass[st->top-1]);
  getch();
}

void cout(Stag* st)
{
system("cls");
if(st->top==0)
  printf("���� ����");
   for(int i=0;i<st->top;++i)
   printf("������� %d ����� %d\n",i,st->mass[i]);
getch();
}
void siz_e(Stag* st)
{
  system("cls");
  printf("������ �����:%d",st->top);
  getch();
  return;
}

void reverse(Stag *st)
{
system("cls");
	int a;
	for(int i=0;i<(st->top/2);++i)
	{
	a=st->mass[i];
	st->mass[i]=st->mass[st->top-1-i];
	st->mass[st->top-i-1]=a;
	}
	printf("������ ����������");
	getch();
	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
	Stag* st=NULL;
	st=createSt();
	int ist=1;
	char ch;
	printf("");
while(ist==1)
{
ist=1;
menu();
fflush (stdin);
gets(&ch);
fflush (stdin);
switch(ch)
{
case '1':{push(st);ist=1;break;}
case '2':{pop(st);ist=1;break;}
case '3':{peek(st);ist=1;break;}
case '4':{cout(st);ist=1;break; }
case '5':{siz_e(st);ist=1;break; }
case '6':{reverse(st);ist=1;break;}
case '7':{ist=0;break;       }
default:{ist=0;break;}
}
}
	deleteS(&st);
	return 0;
}
