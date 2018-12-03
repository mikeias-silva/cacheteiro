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

#include <time.h>

FILE *saida;

int N;		    /* numero de vertices */
int **g;	    /* matriz de distancias */


    
int main()
{
    int i,j,y=0, soma = 0, menor=0, caminho[N], arestasvisitadas = 0, z=0, c=0, visitou=0;
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
        printf("i:%d ", i);
    }
    //***bloco TSP***
    //define o primeira aresta que é armazenada em y.
    for(i=0;i<N;i++){
        soma = 0;
        for(j=0;j<N;j++){
            soma = soma + g[i][j];
        }
        if(i == 0){
            menor = soma;
        }else if(soma < menor){
            menor = soma;
            y = i;
        }
    }
    caminho[arestasvisitadas] = y + 1;
    arestasvisitadas = arestasvisitadas + 1;
    while(arestasvisitadas < N){
        menor =  g[y][N-1];
        z = N-1;
        for(j=0;j<N;j++){
            c = 0;
            visitou = 0;
            if((j != y) && (menor > g[y][j])){
                while(c < arestasvisitadas){
                    if(j+1 == caminho[c]){
                        visitou++;
                    }
                    c++;
                }
                if(visitou == 0){
                    menor = g[y][j];
                    z = j;
                }
            }
        }
        printf("%d /t", z);
        y = z;
        caminho[arestasvisitadas] = y + 1;
        arestasvisitadas = arestasvisitadas + 1;
    }
        printf("arestasvisitadas: %d \n", arestasvisitadas);
    

    //******FIMDOBLOCO******* 
    
    //apenas para mostrar o exemplo
    /* printf("\n");
     printf("\n");
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d\t", g[i][j]);
        }
        printf("\n");
    }*/
    
    // __________________________________
    //|Implementar o algoritmo           |
    //|__________________________________|
    


    //Saída para o arquivo de texto com o formato solicitado no trabalho.
    saida = fopen("saida.txt", "w");
    fprintf(saida, "NAME:\nCOMMENT: solucao obtida pelo aluno xx-x.xxxx\nTYPE: TOUR\nDIMENSION: n\nTOTAL_WEIGHT: xxx\nTOUR_SECTION\n");
    for(j=0;j<N;j++){
            fprintf(saida, "%d\n", caminho[j]);

    }
    fprintf(saida, "EOF");
    fclose(saida);
    return 0;
}