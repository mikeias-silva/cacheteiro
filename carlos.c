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
int calc=0;
int **combinacao;


void troca(int vetor[], int i, int j)
{
	int aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup)
{
	int i;
	if(inf == sup)
	{
		for(i = 0; i <= sup; i++)
			combinacao[calc][i]=vetor[i];
			//printf("%d ", vetor[i]);
		//printf("\n");
		calc++;
		
	}
	else
	{
		
		for(i = inf; i <= sup; i++)
		{
			troca(vetor, inf, i);
			permuta(vetor, inf + 1, sup);
			troca(vetor, inf, i); // backtracking
		}
	}
}

int achaIndex(int valor, int vetor[])
{
	int h, j;
	for (h=0; h<N-1; h++){
    		if(vetor[h]==valor){
    		return h+1;
    		//auxUm=h+1;
    		//printf("%d\t", auxUm);
    		//printf("\n");
		}
	}
	
}  
  
   
int main()
{
    int i,j,fat;
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
    int n = N-1;
    int vetor[n];
    int auxTres=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d\t", g[i][j]);
        }
        printf("\n");
    }
    
    for(i=1,  j=0;i<N;i++, j++){
		vetor[j] = g[0][i];
	}
	
    //Calcula numero de combina��es possiveis 
    
    for(fat = 1; n > 1;  n = n - 1)
		fat = fat * n;
		
    //Aloca espa�o para matriz das combina��es
    combinacao=(int**)malloc(fat*sizeof(int*));
    //Alocar a segunda dimensão
    for(i=0;i<fat;i++)
	    combinacao[i]=(int*)malloc(n*sizeof(int));
    
    
    int tam_v = sizeof(vetor) / sizeof(int);
    permuta(vetor, 0, tam_v - 1);
    
    
    printf("\n");
    for(i=0;i<calc;i++){
        for(j=0;j<N-1;j++){
            printf("%d\t", combinacao[i][j]);
        }
        printf("\n");
    }
    
    
    //calcula custo
    int vetorDois[N-1];
    for(i=1,  j=0;i<N;i++, j++){
		vetorDois[j] = g[0][i];
	}
    
    int h, auxUm, auxDois, custo[fat];
    for(i=0;i<calc;i++){
    	custo[i]=0;
        for(j=0;j<N-2;j++){
        	auxUm = achaIndex(combinacao[i][j], vetorDois);
        	auxDois = achaIndex(combinacao[i][j+1], vetorDois);
        	printf("%d\t", auxUm);
        	custo[i]= custo[i] + g[auxUm][auxDois];
        }
        printf("\n");
        printf("Custo: %d\t", custo[i]);
        printf("\n");
    }
    
    
    
    // __________________________________
    //|Implementar o algoritmo           |
    //|__________________________________|

    return 0;
}
