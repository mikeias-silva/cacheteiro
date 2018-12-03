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

//Efetua a permuta��o das poss�veis combina��es das cidades
void permuta(int vetor[], int inf, int sup)
{
	int i;
	if(inf == sup)
	{
		for(i = 0; i <= sup; i++)
			combinacao[calc][i]=vetor[i];
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

//Calcula o indice da cidade na matriz de pesos
int achaIndex(int valor, int vetor[])
{
	int h, j;
	for (h=0; h<N-1; h++){
    		if(vetor[h]==valor){
    		return h+1;
		}
	}
	
}  
  
   
int main()
{
    int i,j,fat;
    FILE *fd;
    char buf[20], name[100], type[100];

    /* Abrir o arquivo na mesma pasta de nome entrada.tsp.*/
    fd=fopen("./brazil58.tsp","r");
    do{
        fscanf(fd,"%s",buf);//Lê uma palavra inteira
        //verificar se a palavra corresponde a "DIMENSION:" ou "DIMENSION"
        if(strcmp(buf,"DIMENSION:")==0)
            fscanf(fd," %d",&N);
        else if(strcmp(buf,"DIMENSION")==0)
            fscanf(fd," : %d",&N);
		//Pega o valor de nome
        if(strcmp(buf,"NAME:")==0)
            fscanf(fd," %s",&name[100]);
        //Pega o valor de type
    	if(strcmp(buf,"TYPE:")==0)
            fscanf(fd," %s",&type[100]);
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
    // printf("Impressao matriz\n");
    //  for(i=0;i<N;i++){
    //     for(j=0;j<N;j++){
    //         printf(" %d\t", g[i][j]);
    //     }
    //     printf("\n");
    // }

    int n = N-1;
    int vetor[n];
	//Forma um vetor com todas as cidades
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
    
    //Verifica o tamanho do vetor 
    int tam_v = sizeof(vetor) / sizeof(int);
    
    //Efetua a permuta��o das cidades
    permuta(vetor, 0, tam_v - 1);
    
    //Calcula custo
    int vetorAux[N-1];
    //Forma o novo vetor
    for(i=1,  j=0;i<N;i++, j++){
		vetorAux[j] = g[0][i];
	}
    //Variaveis usadas no calculo dos custos
    int h, auxUm, auxDois, custo[fat];
    //Calcula o custo de todas as combina��es
    for(i=0;i<calc;i++){
    	custo[i]=0;
        for(j=0;j<N-2;j++){
        	//Verifica o indice da linha na matriz de pesos 
        	auxUm = achaIndex(combinacao[i][j], vetorAux);
        	//Verifica o indice da coluna na matriz de pesos 
        	auxDois = achaIndex(combinacao[i][j+1], vetorAux);
        	//Soma o peso atual j� somado com o peso encontrado na matriz
        	custo[i]= custo[i] + g[auxUm][auxDois];
        }
    }
    
    //Seleciona melhor caminho
    int menorIndex, menorCusto;
    for(i=0;i<calc;i++){
    	if(i==0){
    		menorIndex = i;
    		menorCusto = custo[i];
		} else {
			if(menorCusto>custo[i]){
				menorIndex = i;
    			menorCusto = custo[i];
			}
		}
	}
	//Saida
    printf("NAME: %s", name);
    printf("\nCOMMENT: Solucao obtida pelo aluno Carlos Alexandre Vitorino Alves");
    printf("\nTYPE: %s", type);
    printf("\nDIMENSION: %d", N);
    printf("\nTOTAL_WEIGHT: %d", menorCusto);
    printf("\nTOUR_SECTION:");
    for(i=0;i<N-1;i++){
		printf("\n%d", combinacao[menorIndex][i]);
	}
	printf("\nEOF");

    return 0;
}
