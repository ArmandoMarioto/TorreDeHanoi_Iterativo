#define SE 15
#define NS 4
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128
#include <time.h>
#define temp 100
//simula o textcolor+textbackground
void TextColor(int fontcolor,int backgroundcolor)
{
   HANDLE screen;
      //int textcolor = LIGHTGREEN;
      //int backgroundcolor = BLACK;
   screen = GetStdHandle(STD_OUTPUT_HANDLE);
  int color_attribute;
  color_attribute = backgroundcolor;
  color_attribute = _rotl(color_attribute,4) | fontcolor;
  SetConsoleTextAttribute(screen,color_attribute);
}

// simula o clrscr()
void clrscr()
{
   system("cls");
}

// simula o gotoxy
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void apaga_mensagem(int x, int y, int q)
{
	gotoxy(x, y);
	for(int i = 0; i < q; i++)
		printf(" ");
}
void apaga_caixa(int x, int y, int alt, int larg)
{
	for(int i = 1; i < alt+7; i++)
	{
		apaga_mensagem(x+1, y+i, larg);
	}
}
void te(int x, int y, int ctxt, int cfd,const char texto[], int larg, int alt)//ctxt = cor do texto, cfd = cor do fundo
{
	int i=x, k=y;
	TextColor(ctxt, cfd);
	for(int i = x; i < x+larg; i++)
	{
		gotoxy(i, k);printf("%c", 196);
		gotoxy(i, k+alt);printf("%c", 196);
	}
	for(i = 0; i < alt; i++)
	{
		gotoxy(x, y+i);printf("%c", 179);
		gotoxy(x+larg, y+i);printf("%c", 179);
	}
	gotoxy( x, y);printf("%c", 218);
	gotoxy( x+larg, y);printf("%c", 191);
	gotoxy( x, y+alt);printf("%c", 192);
	gotoxy( x+larg, y+alt);printf("%c", 217);
	gotoxy(x+1, y+1);printf("%s", texto);
	gotoxy(0, 25);
}
void mt(void)
{
	te(5, 7, 2, 0, " ", 23, 22);
	te(30, 7, 2, 0, " ", 61, 22);
	te(5, 2, 4, 0, " ", 86, 3);
	gotoxy(41, 3);printf("Torre de Hanoi");
	//exibeop();
	gotoxy(0, 25);
}
void mudacor(int &f1, int &f2, int &f3, int dir)
{
	switch(dir)
	{
		case 72:
			if(f1 == SE)
			{
				f3=SE;
				f1=NS;
			}
			else if(f2 == SE)
			{
				f1=SE;
				f2=NS;
			}
			else
			{
				f3=NS;
				f2=SE;
			}
		break;
		case 80:
			if(f1 == SE)
			{
				f1=NS;
				f2=SE;
			}
			else if(f2 == SE)
			{
				f2=NS;
				f3=SE;
			}
			else
			{
				f1=SE;
				f3=NS;
			}
		break;
	}
}
int menuP(void)
{
	char op = 0;
	int flag1 = SE, flag2 = NS,flag3 = NS, aux;
	while(op != 13)
	{
		if(op == 0)
		{
			TextColor(15, 0);
			system("cls");
			te(30, 5, 9, 0, " ", 50, 20);
			te(47, 8, flag1, 0, "Automatico", 15, 2);
			te(47, 11, flag2, 0, "Manual", 15, 2);
			te(47, 14, flag3, 0, "Sair", 15, 2);
		}
		else
		{
			mudacor(flag1, flag2, flag3, op);
			te(47, 8, flag1, 0, "Automatico", 15, 2);
			te(47, 11, flag2, 0, "Manual", 15, 2);
			te(47, 14, flag3, 0, "Sair", 15, 2);
		}
		op = getch();
	}
	system("cls");
	if(flag1 == 15)
		return 1;
	else if(flag2 == 15)
		return 2;
	else
		return 3;
}
void exibe_p(TppilhaM2 p, int np, int x, int y, int ctxt, int cfd, int ndisc)
{
    te(x, y, ctxt, cfd, " ", 10, ndisc);
    int cx = x+5, cy = y+1;
    while(!vazia(p, np))
    {
        gotoxy(cx, cy++);printf("%d", retira(p, np));
    }
}
void exibe_3pilhasc2(TppilhaM2 p, int x, int y, int ctxt, int cfd, int ndisc)
{
    apaga_caixa(30, 7, 15, 60);
    exibe_p(p, 0, x, y, ctxt, cfd, ndisc+1);
    exibe_p(p, 1, x+15, y, ctxt, cfd, ndisc+1);
    exibe_p(p, 2, x+30, y, ctxt, cfd, ndisc+1);
    gotoxy(x+5, y + ndisc+2);printf("A");
    gotoxy(x+20, y + ndisc+2);printf("B");
    gotoxy(x+35, y + ndisc+2);printf("C");
    _sleep(temp);
}
void sair(void)
{
	te(1, 1, 9, 0, " ", 107, 25);
	te(45, 10, 4, 0, "Fim de Jogo!!!", 16, 2);
	gotoxy(0, 26);
	getch();
}
void Ganhou(void)
{
    system("cls");
	te(1, 1, 9, 0, " ", 107, 25);
	te(40, 10, 4, 0, "Parabens Voce Ganhou!!!", 25, 2);
	gotoxy(0, 26);
	getch();
}
