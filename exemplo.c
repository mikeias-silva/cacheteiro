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

int ary[10][10],completed[10],cost=0;
 
int i,j;




int least(int c)
{
    int i,j,nc=999;
    int min=999,kmin;
 
    for(i=0;i < N;i++)
    {
        if((g[i][c]!=0)&&(completed[i]==0))

       
        
            if(g[c][i]+g[i][c] < min)
            {
                min=g[i][0]+g[c][i];
                kmin=g[c][i];
                nc=i;
            }
    }
 
    if(min!=999)
        cost+=kmin;
 
    return nc;
}

void mincost(int cidade)
{
    int i,nCidade;
 
    completed[cidade]=1;

    
    // for(i = 0; i<=cidade; i++ )
    // {
    //     printf("\n ||ce ta doido %d||", completed[i]);
    // }
    
 
    printf(" cidade %d--->",cidade+1);
  
    
    nCidade=least(cidade);

    if(nCidade==999)
    {
        nCidade=0;
        printf("%d",nCidade+1 );
        cost+=g[cidade][nCidade];
 
        return;
    }
 
    mincost(nCidade);
}
 
    
int main()
{
    
    FILE *fd;
    char buf[20];

    /* Abrir o arquivo na mesma pasta de nome entrada.tsp.*/
    fd=fopen("./brazil58.tsp","r");
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
    printf("Impressao matriz\n");
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf(" %d\t", g[i][j]);
        }
        printf("\n");
    }


    
    // __________________________________
    //|Implementar o algoritmo           |
    //|__________________________________|
    
    mincost(0);
    printf("\n");
    return 0;
}
