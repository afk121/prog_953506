#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void menu()
{
 printf("����: ��� ��������� �������\n1 - ����� ��������� \n2 - ����� ������� \n3 - ����� ������\n");
 printf("4 - ����� ������� ���������� ������\n5- ����� ����� ��������� \n6 - ���������� � �������� \n7 - ����� �� ���������\n(���� �� ������� ���-���� ������, ��������� ����������)\n(�������� ������ ������ ������!!!��� ��������� ������ ���������)\n ");
}
//��������� ������ ��� �����, ������ - ���������, ������ -  �����������
void vvodPotato(float* potato)
{
char c;
system("cls");
	  printf("������� ����� ������������� ���������\t");
	  if(scanf("%f",potato)!=1||(c=getchar())!='\n'||*potato<0)
	  {
		  printf("�������� ����");
		  fflush (stdin);
          getch();
		  return;
	  }
}

void vvodMorkov(float* morkov)
{
char c;
system("cls");
	  printf("������� ����� ������������ �������\t");
	  if(scanf("%f",morkov)!=1||(c=getchar())!='\n'||*morkov<0)
	  {
		  printf("�������� ����");
		  fflush (stdin);
          getch();
		  return;
	  }
}

void vvodSvekla(float* svekla)
{
char c;
system("cls");
	  printf("������� ����� ������������ �������\t");
	  if(scanf("%f",svekla)!=1||(c=getchar())!='\n'||*svekla<0)
	  {
		  printf("�������� ����");
		  fflush (stdin);
          getch();
		  return;
	  }
}

void vyvodRazmer(float* potato,float* morkov,float* svekla)
{
system("cls");
printf("����� ��������� = %f ��,��� ��������� ����� %d �.\n ����� ������� = %f ��,�� ��������� ����� %d �.\n ����� ������ ����� %f ��,�� ��������� ����� %d �.\n",*potato,(int)(500*(*potato)),*morkov,(int)(1000*(*morkov)),*svekla,(int)((*svekla)*700));
getch();
}


void vyvodDengi(float* potato,float* morkov,float* svekla)
{
system("cls");
printf("����� ��������� = %f ��,��� ��������� ����� %d �.\n ����� ������� = %f ��,�� ��������� ����� %d �.\n ����� ������ ����� %f ��,�� ��������� ����� %d �.\n",*potato,(int)(500*(*potato)),*morkov,(int)(1000*(*morkov)),*svekla,(int)((*svekla)*700));
printf("�������� ����� 15.000 ������\n");
float sum=*potato+*morkov+*svekla;
float skidka=1;
if(sum>10&&sum<25)
skidka=0.9;
else if(sum>=25&&sum<50)
skidka=0.79;
else if(sum>=50)
skidka=0.7;
printf("������ ����� %d\n",(int)(100-100*skidka));
printf("��������� ������ ����� %d\n",(int)((500*(*potato)+1000*(*morkov)+700*(*svekla)+15000)*(skidka+0.01)));
getch();
}


void vers()
{
system("cls");
	printf("��� ����, ������ 10 ���");
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 int a=1;
 char r;
 float potato=0;
 float morkov=0;
 float svekla=0;

 while(a==1)
 {
 system("cls");
 menu();
 fflush (stdin);
 r=getchar();
 fflush (stdin);
 switch(r)
 {
 case '1': vvodPotato(&potato);break;
 case '2': vvodMorkov(&morkov);break;
 case '3': vvodSvekla(&svekla); break;
 case '4': vyvodRazmer(&potato,&morkov,&svekla); break;
 case '5': vyvodDengi(&potato,&morkov,&svekla); break;
 case '6': vers();break;
 case '7':a=0;break;
 default: printf("�������� ����,������ ��������� ������");
 getch();
 a=0;
 }
 }


	return 0;
}
