#include <stdio.h>
#include <malloc.h>

struct elemento
{
    struct elemento *proximo;
    int info;
};

struct Lista
{
    struct elemento *dados;
    int tamanho;
};

struct Lista *criarLista()
{
    struct Lista *aLista;
    aLista = malloc(sizeof(struct Lista));
    if (aLista != NULL)
    {
        aLista->tamanho = 0;
        aLista->dados = NULL;
    }
    return aLista;
}

int adicionarnaposicao(struct Lista *aLista, int info, int posicao)
{
    struct elemento *novo, *anterior;
    if (posicao > aLista->tamanho + 1)
    {
        return (printf("Error(Posi)"));
    }
    else
    {
        novo = malloc(sizeof(struct elemento));
        if (posicao == 1)
        {
            aLista->tamanho = aLista->tamanho + 1;
            novo->info = info;
            novo->proximo = aLista->dados;
            aLista->dados = novo;
            return (aLista->tamanho);
        }
        else
        {
            if (novo == NULL)
            {
                return (printf("Error(Full)"));
            }
            else
            {
                anterior = aLista->dados;
                for (int i = 0; (posicao - 2); i++)
                {
                    anterior = anterior->proximo;
                }
                novo->proximo = anterior->proximo;
                novo->info = info;
                anterior->proximo = novo;
                aLista->tamanho = aLista->tamanho + 1;
                return (aLista->tamanho);
            }
        }
    }
}

int retira(struct Lista *aLista, int valor)
{
    struct elemento *anterior, *auxiliar;
    int *volta;
    auxiliar = aLista->dados;
    while (auxiliar != NULL)
    {
        if (auxiliar->info == valor)
        {
            if (anterior == NULL)
            {
                aLista->dados = auxiliar->proximo;
            }
            else
            {
                anterior->proximo = auxiliar->proximo;
            }
            aLista->tamanho = aLista->tamanho - 1;
            return 1;
        }
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }
}

int exibe(struct Lista *aLista){
    struct elemento *aux;
    aux = aLista->dados;
    printf("%d",aux->info);
    while(aux != NULL)
    {
        printf("%d",aux->info);
        aux = aux->proximo;
    }
    return 0;
}

int main()  
{
    int pinline;
    int poutline;
    int temp1;
    int temp2;
    struct Lista *aLista;

    scanf("%d", &pinline);
    aLista = criarLista();
    for (int i = 1; i == pinline; i++)
    {
        scanf("%d", &temp1);
        adicionarnaposicao(aLista, temp1, i);
        
    }
    scanf("%d", &poutline);
    for (int a = 0; a == poutline; a++)
    {
        scanf("%d", &temp2);
        retira(aLista, temp2);
    }
    exibe(aLista);
}
