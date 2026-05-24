#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct {
    int exits;
    int belongs;
} Coordenada;


int encontrarIlhas( int linhas, int colunas, int regiao_oceano[linhas][colunas], int i, int j)
{
    if (i < 0 || i >= linhas || j < 0 || j >= colunas) 
    {
        return 0;
    }
    if (regiao_oceano[i][j] == 0) 
    {
        return 0;
    }
    int altura_atual = regiao_oceano[i][j];
    regiao_oceano[i][j] = 0;
    int soma = altura_atual;

    soma += encontrarIlhas(linhas, colunas,regiao_oceano, i + 1, j);
    soma += encontrarIlhas(linhas, colunas,regiao_oceano, i - 1, j);
    soma += encontrarIlhas( linhas, colunas,regiao_oceano, i, j + 1);
    soma += encontrarIlhas(linhas, colunas,regiao_oceano, i, j - 1);

    return soma;
}

void problemaMochila (int profundidades[], int total_ilhas, int profundidade, Coordenada P[total_ilhas + 1][profundidade + 1] ) 
{
   P[0][0].exits = true;

    for (int c = 1; c <= profundidade; c++) 
    {
        P[0][c].exits = false;
    }
   
   for (int i = 1; i <= total_ilhas; i++) 
   {
    for (int j = 0; j <= profundidade; j++)
    {
        P[i][j].exits = false;

        if (P[i -1][j].exits == true) 
        {
            P[i][j].exits = true;
            P[i][j].belongs = false;
        }
        else
        {
            int resto = j - profundidades[i-1];
            if (resto >= 0 && P[i-1][resto].exits == true) 
            {
                P[i][j].exits = true;
                P[i][j].belongs = true;
            }

        }
    }   
   }

}

void encontrarCombinacao( int profundidades[], int total_ilhas, int profundidade, Coordenada P[total_ilhas + 1][profundidade + 1]) 
{
   if (!P[total_ilhas][profundidade].exits) 
   {
    printf("\nNao ha resposta valida!");
    return;
   }

   int contador = 0;  
   int resto = profundidade;
   
   for (int i = total_ilhas; i > 0 && resto; i--) 
   {
    if (P[i][resto].belongs) 
    {
        if (contador == 0) 
        {
            printf("\n");
        }
        contador++;
        printf("%d ", profundidades[i-1]);
        resto -= profundidades[i-1];
    }

   }
   
}


int main(int argc, char *argv[])
{
    int profundidade = atoi(argv[1]);
    int linhas = atoi(argv[2]);
    int colunas = atoi(argv[3]);
    char *nome_arquivo = argv[4];

    int regiao_oceano [linhas][colunas];

    if (nome_arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            fscanf(arquivo,"%d", &regiao_oceano[i][j]);
        }     
    }

    fclose(arquivo);

    int *somas_ilhas;
    int total_ilhas = 0;

    somas_ilhas = (int *) malloc((linhas * colunas) * sizeof(int));;
    int contador = 0;

    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            if (regiao_oceano[i][j] != 0) 
            {
                total_ilhas++;
                somas_ilhas[contador] = encontrarIlhas(linhas, colunas,regiao_oceano, i, j);
                contador++;

            }
        }     
    }

    printf("%d\n", total_ilhas);

    int *profundidades;
    profundidades = (int *) malloc((linhas * colunas) * sizeof(int));

    for (int i = 0; i < contador; i++) 
    {
        double calculo = somas_ilhas[i] / 6.0;

        if (calculo < 1 && calculo > 0) 
        {
            calculo = 1;
        }
        profundidades[i] = (int) calculo;
        printf("%d ", profundidades[i]);

    }

    Coordenada P[total_ilhas + 1][profundidade + 1];
    problemaMochila(profundidades,total_ilhas, profundidade, P);
    encontrarCombinacao(profundidades, total_ilhas,profundidade, P);

    free(somas_ilhas);
    free(profundidades);

    return 0; 
}