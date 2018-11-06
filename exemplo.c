/*  Arquivo exemplo.c
 *
 *  Le o arquivo de nome "entrada.tsp" 
 *  
 *  Luiz Pedro Petroski
 *  Analise de Algoritmos
 *  06/11/2018
 *  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;		    /* numero de vertices */
int **g;	    /* matriz de distancias */
    
int main()
{
    int i,j;
    FILE *fd;
    char buf[20];

    /* Abrir o arquivo na mesma pasta de nome entrada.tsp.*/
    fd=fopen("./entrada.tsp","r");
    do{
        fscanf(fd,"%s",buf);//Lê uma palavra inteira
        //verificar se a palavra corresponde a "DIMENSION:" ou "DIMENSION"
        if(strcmp(buf,"DIMENSION:")==0)
            fscanf(fd," %d",&N);
        else if(strcmp(buf,"DIMENSION")==0)
            fscanf(fd," : %d",&N);
    //Até encontrar a seção de pesos das arestas
    }while(strcmp(buf,"EDGE_WEIGHT_SECTION")!=0);

    //Alocar a primeira dimensão da matriz de adjacencias do grafo g
    g=(int**)malloc(N*sizeof(int*));
    //Alocar a segunda dimensão
    for(i=0;i<N;i++)
	    g[i]=(int*)malloc(N*sizeof(int));
    
    /* Leitura da matriz g */
    for(i=0;i<N;i++){
        g[i][i]=0;//um nó para ele mesmo tem distância 0
        for(j=i+1;j<N;j++){
            fscanf(fd,"%d",&g[i][j]);//faz a leitura do peso da aresta
            g[j][i]=g[i][j];// como é um grafo simétrico e não orientado
        }
    }
    //apenas para mostrar o exemplo
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d\t", g[i][j]);
        }
        printf("\n");
    }
    // __________________________________
    //|Implementar o algoritmo de busca  |
    //|__________________________________|

    return 0;
}
