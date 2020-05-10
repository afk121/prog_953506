#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include "Avto.h"
#include "Person.h"
#include "Request.h"

#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void element(Avto* a)
{
if(a==NULL)
return;
printf("   %d - %s\n",a->index,a->model);
element(a->next);
}

void pelement(Person* a)
{
if(a==NULL)
return;
printf("   %d - %s\n",a->index,a->FIO);
pelement(a->next);
}

void avtoMenu()
{
printf("����������:\n 1 - ������� ����\n 2 - ������� ���� ���������� ����������\n");
printf(" 3 - �������� ���������\n 4 - �������� ���������� ���������\n 5 - ����� ����������\n");
printf(" 6 - ����� ������ ����\n 7 - ������� ������ ����\n 8 - �������� ����\n 9 - ����������\n q - ������������ ��������� ����");
}

void personMenu()
{
printf("����������:\n 1 - ������� ����\n 2 - ������� ���� ���������� ��������\n");
printf(" 3 - �������� ���������\n 4 - �������� ���������� ���������\n 5 - ����� ����������\n");
printf(" 6 - ����� ������ ����\n 7 - ������� ������ ����\n 8 - �������� ����\n 9 - ������������ ��������� ����\n");
}

void requestMenu()
{
printf(" 1 - ������ ��������� ��� ����������\n 2 - ������������ ������\n");
}

void Menu()
{
printf(" �������:\n 0 - �����\n 1 - ������ � ����� ������ �����������\n 2 - ������ � ����� ������ �����������\n 3 - ������ � ��������\n ");
}

void sokr(Avto* a,int z)
{
system("cls");
Avto* per = a;
_Bool b = 1;
int number = 0;

printf(" ������� ����� ������� ����\n(��� ������ ������� -1\n");
element(a);
if(scanf(" %d",&number)!=1 || getchar()!='\n')
  {
	fflush(stdin);
	printf("�������� ��� ������");
	return;
  }
if(number<0)
return;

while(per!=NULL)
  {
	if(number==per->index)
	{
		switch(z)
		{
			case '2':fawrite(per);break;
			case '3':awchoice(per);break;
			case '4':awrite(per);printf("���� �������. ������� ����� �������, ����� ����������... ");break;
			case '5':afind(per);break;
			case '6':aread(per);break;
			case '7':faremove(per);printf("���� ������. ������� ����� �������, ����� ����������... ");break;
			case '8':aremove(per);printf("���� ������. ������� ����� �������, ����� ����������... ");break;
			case   9:break;
		}
		b = 0;
		break;
	}
	else per=per->next;
  }

if(b == 1)
printf("���������� ������ �� ����������. ������� ����� �������, ����� ����������...");
b=1;
getch();
}

void personSokr(Person* a,int z)
{
system("cls");
Person* per = a;
_Bool b=1;
int number=0;

printf(" ������� ����� ������� ����\n(��� ������ ������� -1\n");
pelement(a);
if(scanf(" %d",&number)!=1 || getchar()!='\n')
  {
	fflush(stdin);
	printf("�������� ��� ������");
	return;
  }
if(number<0)
return;

while(per!=NULL)
  {
	if(number==per->index)
	{
		switch(z)
		{
			case '2':fpwrite(per);break;
			case '3':pwchoice(per);break;
			case '4':pwrite(per);printf("���� �������. ������� ����� �������, ����� ����������... ");break;
			case '5':pfind(per);break;
			case '6':pread(per);break;
			case '7':fpremove(per);printf("���� ������. ������� ����� �������, ����� ����������... ");break;
			case '8':premove(per);printf("���� ������. ������� ����� �������, ����� ����������... ");break;
		}
		b=0;
		break;
	}
	else per=per->next;
  }

if(b==1)
printf("���������� ������ �� ����������. ������� ����� �������, ����� ����������...");
b=1;
getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

Person* persona;
persona = pcreate();
Avto* tt;
tt = acreate();

dataBase(tt,persona);

_Bool b=1;
char ind=0;
int number=0;
while(b==1)
{
system("cls");
Menu();
switch(ind = getch())
 {
	case '0':b=0;
				 afullremove(tt);
				 pfullremove(persona);
				 break;
	case '1':
	system("cls");
	personMenu();
	switch(ind=getch())
	{
		case '1':system("cls");
				 pcr(persona);
				 printf("���� ������. ������� ����� �������, ����� ����������...");
				 getch();
				 break;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
				personSokr(persona, ind);
				break;
		case '9':system("cls");
				 precover(persona);
				 printf("������� ����� �������, ����� ����������...");
				 getch();
				 break;
		case 9: break;
	}
	break;

	case '2':
		system("cls");
		avtoMenu();
		switch(ind=getch())
		{
			case '1':system("cls");
					 acr(tt);
					 printf("���� ������. ������� ����� �������, ����� ����������...");
					getch();
					break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
					 sokr(tt,ind);
					 break;
			case 9: break;
			case '9':
					 system("cls");
					 char symbol;
					 printf("�������� ��� ���������� ����\n0 - ���������� �� ����\n1 - ���������� �� ���� �������\n");
					switch(symbol=getch())
					{
					case '0':system("cls");sort(tt,&symbol);break;
					case '1':system("cls");sort(tt,&symbol);break;
					case   9:break;
					}
					printf("  ���������� �����������. ������� ����� �������, ����� ����������...");
					getch();
					break;
			case 'q':system("cls");
				 arecover(tt);
				 printf("������� ����� �������, ����� ����������...");
				 getch();
				 break;
		default:{printf("%d",ind);break;}
		}
	break;


	case '3':
	system("cls");
	requestMenu();
	switch(ind=getch())
	{
		case '1':
				system("cls");
				apchoice(tt);
				printf("������� ����� ������, ����� ����������");
				getch();
			break;
		case '2':
			query(tt, persona);
			break;
		case   9:break;
	}
	break;
 }
}
return 0;
}
