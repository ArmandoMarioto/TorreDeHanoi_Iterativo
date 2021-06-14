#include<stdio.h>
#include<conio.h>
#define maxpilha 100
struct TppilhaM2
{
	int bases[maxpilha], topos[maxpilha];
	int pilhas[maxpilha];
};
void inicializa(TppilhaM2 &p, int q)
{
    int tam = maxpilha/q;
    for(int i = 0; i <= q; i++)
    {
        p.bases[i] = i*tam;
        p.topos[i] = p.bases[i]-1;
    }
}
bool cheia(TppilhaM2 p, int np)
{
    return p.topos[np]+1 == p.bases[np+1];
}
bool vazia(TppilhaM2 p, int np)
{
    return p.topos[np] < p.bases[np];
}
void insere(TppilhaM2 &p, int np, int elem)
{
    p.pilhas[++p.topos[np]] = elem;
}
int retira(TppilhaM2 &p, int np)
{
    return p.pilhas[p.topos[np]--];
}
int acessaElemTopo(TppilhaM2 p,int np)
{
    return p.pilhas[p.topos[np]];
}
void exibe(TppilhaM2 p, int np)
{
	if(vazia(p, np))
		printf("nada");
	else
    	while(!vazia(p, np))
        	printf("%5d", retira(p, np));
}
