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
printf("������� ����� �� ����������, � � ������ �����, ����� ������� ����� � ���������� �������\n");
char t[40];
char tt='1';
char tr=0;
int i=0;
_Bool bol=1;

while((tt=getchar())!='\n')
{
//�������� �� ��������� �����
  if(tt>='A'&&tt<='Z')
  tt+=32;

//�������� �� ���������� �������
  if(tt>='a'&&tt<='z'&&tt>=tr&&i<40)
  {
	  tr=tt;
	  t[i]=tr;
	  ++i;

  }
//������� �� ����� ����������
  else if((tt>=' '&&tt<=47)||(tt>=91&&tt<96))
  {
	if(i!=0)
	{tr=0;
	t[i]=0;
	puts(t);
	i=0;
	bol=0;
	}
  }
//�������� �� ������������ �������
   else if(tr>tt) {
		tr=0;
		i=0;
		t[0]=0;
		//���������� �� �������� ��� � �������� ����
		for(;;)
		if((tt=getchar())<'a')
		{
			if(tt=='\n')
			{
				getch();
				return 0;
			}
			break;
		}
		}
		//�������� �� ��� ���������
  else
  {
	tr=0;
	t[0]=0;
	i=0;
    		for(;;)
		if((tt=getchar())<'a')
		{
			if(tt=='\n')
			{
				getch();
				return 0;
			}
			break;
		}
  }
}
if(bol==1)
printf("��� ����, ������ �� ��������");
	getch();
	return 0;
}
