#include <stdio.h>
#include <malloc.h>

struct elemento
{
    struct elemento *proximo;
    int info;
};

struct Lista
{
    struct elemento *inicio;
    struct elemento *final;
    int tamanho;
};

struct Lista *criarLista()
{
    struct Lista *aLista;
    aLista = malloc(sizeof(struct Lista));
    if (aLista != NULL)
    {
        aLista->tamanho = 0;
        aLista->inicio = NULL;
    }
    return aLista;
}

int adicionar(struct Lista *aLista, int info)
{
    struct elemento *novo, *anterior;
        novo = (struct elemento *) malloc(sizeof(struct elemento));

        if (aLista->inicio == NULL)
        {
            aLista->tamanho = aLista->tamanho + 1;
            novo->info = info;
            novo->proximo = NULL;
            aLista->inicio = novo;
            aLista->final = novo;
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
                anterior = aLista->final;
                novo->info = info;
                novo->proximo = NULL;
                anterior->proximo = novo;
                aLista->final = novo;
                aLista->tamanho = aLista->tamanho +1;
                // anterior = aLista->inicio;
                // for (int i = 0; i < (posicao - 2); i++)
                // {
                //     anterior = anterior->proximo;
                // }
                // novo->proximo = anterior->proximo;
                // novo->info = info;
                // anterior->proximo = novo;
                // aLista->tamanho = aLista->tamanho + 1;
                return (aLista->tamanho);
            }
        }
}

int retira(struct Lista *aLista, int valor)
{
    struct elemento *anterior = NULL, *auxiliar;
    int *volta;
    auxiliar = aLista->inicio;
    while (auxiliar != NULL)
    {
        if (auxiliar->info == valor)
        {
            if (anterior == NULL)
            {
                aLista->inicio = auxiliar->proximo;
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
    aux = aLista->inicio;
    while(aux != NULL)
    {
        printf("%d ",aux->info);
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
    int j = 0;
    struct Lista *aLista;
    scanf("%d", &pinline);
    aLista = criarLista();
    for (j=1; j <= pinline;j++)
    {
        scanf("%d", &temp1);
        adicionar(aLista, temp1);
        
    }
    scanf("%d", &poutline);
    for (int a = 1; a <= poutline; a++)
    {
        scanf("%d", &temp2);
        retira(aLista, temp2);
    }
    exibe(aLista);
    printf("\n");
    free(aLista);
    return 0;
}
