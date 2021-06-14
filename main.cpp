#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include "Pilhas_Multiplas.h"
#include "telaP.h"
#include<math.h>
#include<string.h>
int get_qtelem(TppilhaM2 p, int np)
{
    return p.topos[np]-p.bases[np]+1;
}
void insere_elementos(TppilhaM2 &p, int np, int nElem)
{
    for(int i = nElem; i > 0; i--)
        insere(p, np, i);
}
void get_dest_orig(int &origem, int &desti);
int getauxiliar(int o, int d)
{
    int aux;
    if(o == 0 && d == 2 || d == 0 && o == 2)
        aux = 1;
    else if(o == 1 && d == 2 || d == 1 && o == 2)
        aux = 0;
    else
        aux = 2;
    return aux;
}
void movimento(TppilhaM2 &p, int origem, int aux)
{
    if(vazia(p, origem))
        insere(p, origem, retira(p, aux));
    else
    if(vazia(p, aux))
        insere(p, aux, retira(p, origem));
    else
    if(acessaElemTopo(p, origem) < acessaElemTopo(p, aux))
        insere(p, aux, retira(p, origem));
    else
        insere(p, origem, retira(p, aux));
}
float por(int tot, int cont)
{
    return (float)((cont*100)/tot);
}
void Torre_de_Hanoi(TppilhaM2 &p, int origem, int destino, int &con)
{
    int q = get_qtelem(p, origem);
    con = 0;
    int tot = pow(2, q)-1;
    int aux = getauxiliar(origem, destino);
    while(get_qtelem(p, destino) < q)
    {
        con++;
        if(q%2==0)
        {
            movimento(p, origem, aux);
            exibe_3pilhasc2(p, 32, 8, 15, 0, q);
            gotoxy(10, 11);printf("Mov: %d", con);
            gotoxy(10, 12);printf("Total: %d", tot);
            gotoxy(80, 6);printf("%0.1f%%", por(tot, con));
            if(get_qtelem(p, destino) != q)
            {
                movimento(p, origem, destino);
                exibe_3pilhasc2(p, 32, 8, 15, 0, q);
                con++;
                gotoxy(10, 11);printf("Mov: %d", con);
                gotoxy(80, 6);printf("%0.1f%%", por(tot, con));
                if(get_qtelem(p, destino) != q)
                {
                    movimento(p, destino, aux);
                    exibe_3pilhasc2(p, 32, 8, 15, 0, q);
                    con++;
                    gotoxy(10, 11);printf("Mov: %d", con);
                    gotoxy(80, 6);printf("%0.1f%%", por(tot, con));
                }
            }
        }
        else
        {
            movimento(p, origem, destino);
            exibe_3pilhasc2(p, 32, 8, 15, 0, q);
            if(get_qtelem(p, destino) != q)
            {
                movimento(p, origem, aux);
                exibe_3pilhasc2(p, 32, 8, 15, 0, q);
                con++;
                gotoxy(10, 11);printf("Mov: %d", con);
                gotoxy(10, 12);printf("Total: %d", tot);
                gotoxy(80, 6);printf("%.1f%%", por(tot, con));
                if(get_qtelem(p, destino) != q)
                {
                    movimento(p, destino, aux);
                    exibe_3pilhasc2(p, 32, 8, 15, 0, q);
                    con++;
                    gotoxy(10, 11);printf("Mov: %d", con);
                    gotoxy(10, 12);printf("Total: %d", tot);
                    gotoxy(80, 6);printf("%0.1f%%", por(tot, con));
                }
            }
        }
    }
}
void dest_orige(TppilhaM2 &p, int orig, int des)
{
    apaga_caixa(6, 7, 10, 20);
    if(!vazia(p, orig) && acessaElemTopo(p, orig) < acessaElemTopo(p, des))
        insere(p, des, retira(p, orig));
    else
        if(vazia(p, des) && !vazia(p, orig))
            insere(p, des, retira(p, orig));
    else
    {
        gotoxy(10, 10);printf("Operacao Invalida");
        getch();
        apaga_caixa(6, 7, 10, 20);
    }
}
void opchar(int &num, char o)
{
    if(o == 65)
        num = 0;
    else if(o == 'B')
        num = 1;
    else if(o == 'C')
        num = 2;
    else
        num = -1;
}
void manual(TppilhaM2 &p, int quandisc, int destino)
{
    mt();
    char selec, pilha;
    selec = 'a';
    int ori, des;
    while(selec != 27 && get_qtelem(p, destino) <  quandisc)
    {
        exibe_3pilhasc2(p, 32, 8, 15, 0, quandisc);
        gotoxy(10, 10);printf("De: ");fflush(stdin);
        pilha = toupper(getche());
        opchar(ori, pilha);
        gotoxy(10, 10);printf("Para: ");fflush(stdin);
        pilha = toupper(getche());
        opchar(des, pilha);
        gotoxy(10, 10);
        dest_orige(p, ori, des);
        selec = getch();
    }
    if(get_qtelem(p, destino) == quandisc)
        Ganhou();
}
int get_quantDiscos(int &origem, int &destino)
{
    bool flag = false;
    int q;
    do
    {
        do
        {
            te(38, 7 ,15, 0, "Insira Quantidade de Discos: " , 33, 7);gotoxy(68, 8);
            scanf("%d", &q);
            system("cls");
            if(q <= 0 || q >= 21)
            {
                system("cls");
                te(38, 7 ,15, 0, "Numero de Discos Invalido!!!" , 33, 7);
                getch();
                flag = true;
                system("cls");
            }
            else
                flag = false;
        }while(flag);

        te(38, 7 ,15, 0, "Insira a Origem de 1 a 3: " , 33, 7);gotoxy(68, 8);
        scanf("%d", &origem);
        origem--;
        system("cls");
        te(38, 7 ,15, 0, "Insira a Destino de 1 a 3: " , 33, 7);gotoxy(68, 8);
        scanf("%d", &destino);
        destino--;
        system("cls");
        if(origem < 0 || origem > 2 || destino < 0 || destino > 2 || destino == origem)
        {
            system("cls");
            te(38, 7 ,15, 0, "Invalido!!!" , 33, 7);
            getch();
            flag = true;
        }
        else
            flag = false;
        fflush(stdin);
    }while(q <= 0 || q >= 21 || flag);
    return q;
}
void automatico(TppilhaM2 p, int contador, int ndiscos, int origem, int destino)
{
    mt();
    Torre_de_Hanoi(p, origem, destino, contador);
    //gotoxy(10, 20);printf("%d repeticoes", contador);
    getch();
}
int main(int argc, char *argv[])
{
    system("mode con:cols=110 lines=30");
    TppilhaM2 p;
    int origem, destino;
    int contador, ndiscos;
    inicializa(p, 3);
    int op;
    //insere_elementos(p, origem, ndiscos);
    do
    {
        op = menuP();
        if(op != 3)
            ndiscos = get_quantDiscos(origem, destino);
        inicializa(p, 3);
        insere_elementos(p, origem, ndiscos);
        switch(op)
        {
            case 1:
                automatico(p, contador, ndiscos, origem, destino);
            break;
            case 2:
                manual(p, ndiscos, destino);
            break;
            case 3:
                sair();
            break;
        }
        system("cls");
    }while(op != 3);
    return 0;
}
