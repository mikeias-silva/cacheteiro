# Engenharia de software
## Disciplina de Análise de Algoritmos
* * *

Trabalho prático: Problema do Caixeiro Viajante
==============================================
Este repositório apresenta as instruções para a relização do trabalho e também um exemplo com o algoritmo Bubblesort

1\. Instruções
--------------
O problema do caixeiro viajante pode ser facilmente enunciado: consiste em determinar o
caminho mais curto em que é possível percorrer uma determinada lista de cidades e retornar à
cidade de, de modo a que cada cidade seja visitada uma só vez.
Embora pareça tão modesto, o problema do Caixeiro Viajante (em inglês TSP, Travelling
Salesman Problem), é um problema muito estudado por cientistas, matemáticos e
pesquisadores de diversas áreas.
Neste trabalho, pede-se implementar a solução para este problema


Observando as seguintes questões:
* Pode ser utilizado soluções da internet
* A entrega será do código fonte
* O código fonte deve estar comentado
* Deve ser utilizado a entrada arquivos da biblioteca de dados TSPLIB
* https://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/tsp/
***
2\. Entrada
--------------
A entrada de dados será no formato das instâncias da TSPLIB (Travelling Saleman Problem
Library). A TSPLIB é um biblioteca com instâncias do TSP e problemas correlatos. Neste
trabalho serão consideradas apenas as instâncias do problema do caixeiro viajante simétrico
(Symmetric Traveling Salesman Problem), onde as distâncias consideradas são simétricas, ou
seja, a distância de ir do nó j ao nó i é sempre igual à de ir do nó i ao nó j. As instâncias podem
ser baixadas em:
 https://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/tsp/

 A entrada consiste de duas partes: a parte de especificação e a parte com os dados
propriamente ditos. Na especificação, as seguintes linhas poderão ser encontradas:

-NAME: indica o nome da instâncias
-TYPE: o tipo da instância. Só trabalharemos com instâncias do tipo TSP.
-COMMENT: comentários sobre a instância.
-DIMENSION: tamanho (número de cidades) da instância.
 -EDGE_WEIGHT_TYPE: a forma de cálculo da distância. Serão aceitas duas opções para este parâmetro: EUC_2D, EUC_3D.
 -EUC_2D – as distâncias são euclidianas, e duas coordenadas são consideradas.
 -EUC_3D – as distâncias são euclidianas, e três coordenadas são consideradas.
 -EXPLICIT – todas as distâncias são dadas no arquivo.


***
2\. Saída

A saída deve seguir o formato a seguir:
```
NAME: entrada
COMMENT: solucao obtida pelo aluno xx-x.xxxx
TYPE: TOUR
DIMENSION: 5
TOTAL_WEIGHT: 100
TOUR_SECTION
1
2
3
4
5
EOF
```
--------------
   
### *   O exemplo acima é apenas um auxílio. Você está livre para implementar os algoritmos como for de sua preferência, lembrando sempre de seguir as instruções contidas no **tópico 1**