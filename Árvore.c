#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct No
{
    int info;
    struct No *esq;
    struct No *dir;
} arvb;


arvb *Inicializar()
{
    return NULL;
}

arvb *Inserir(arvb *novo,int n)
{
    if(novo==NULL)
    {
        arvb *novo1 = Inicializar();
        novo1=(arvb*)malloc(sizeof(arvb));
        novo1->esq=NULL;
        novo1->dir=NULL;
        novo1->info=n;
        return novo1;
    }
    else
    {
        if(n<novo->info)
        {
            novo->esq=Inserir((novo->esq),n);
        }
        else
        {
            novo->dir=Inserir((novo->dir),n);
        }
    }
    return novo;
}

void ListarERD(arvb *novo)
{
    if(novo!=NULL)
    {
        ListarERD(novo->esq);
        printf("\n%d",novo->info);
        ListarERD(novo->dir);
    }
}

bool Buscar(arvb *novo,int n)
{
    if(novo==NULL)
    {
        return false;
    }
    else
    {
        if(novo->info==n)
        {
            return true;
        }
        else
        {
            if(n<novo->info)
            {
                Buscar((novo->esq),n);
            }
            else
            {
                Buscar((novo->dir),n);
            }
        }
    }

}


int main()
{
    arvb *tree = Inicializar();
    int n=0;

    //inserindo 12 nós
    for(int i=0; i<12; i++)
    {
        printf("Digite um numero inteiro:\n");
        scanf("%d",&n);
        tree=Inserir(tree,n);
    }

    //listando a arvore
    system("pause");
    system("cls");
    ListarERD(tree);
    printf("\n");
    //Encontrando um numero qualquer na árvore
    system("pause");
    system("cls");
    printf("Digite um numero para buscar na arvore:\n");
    scanf("%d",&n);

    system("pause");
    system("cls");

    if(Buscar(tree,n))
    {
        printf("Resultado: Encontrado");
    }
    else
    {
        printf("Resultado: Nao encontrado");
    }
    return 0;
}
