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
printf("введите текст на английском, а € выведу слова, буквы которых сто€т в алфавитном пор€дке\n");
char t[40];
char tt='1';
char tr=0;
int i=0;
_Bool bol=1;

while((tt=getchar())!='\n')
{
//проверка на заглавные буквы
  if(tt>='A'&&tt<='Z')
  tt+=32;

//проверка на алфавитный пор€док
  if(tt>='a'&&tt<='z'&&tt>=tr&&i<40)
  {
	  tr=tt;
	  t[i]=tr;
	  ++i;

  }
//провека на знаки препинани€
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
//проверка на неалфавитный пор€док
   else if(tr>tt) {
		tr=0;
		i=0;
		t[0]=0;
		//избавление от ненужных уже в проверке слов
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
		//проверка на все остальное
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
printf("Ќет слов, идуших по алфавиту");
	getch();
	return 0;
}
