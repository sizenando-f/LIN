#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Exibe a matriz.
 * Será exibido a matriz no console
 * @param matriz Matriz de no máximo 10x10
 * @param ordem Dimensão da matriz
 */
void exibeMatriz(int matriz[10][10], unsigned ordem){
  for(unsigned i = 0; i < ordem; i++){
    printf("| ");
    for(unsigned j = 0; j < ordem; j++){
    printf("%4d", matriz[i][j]);
    }
    printf("|\n");
  }
}

/**
 * @brief Deixa o pivô da coluna com o maior número.
 * Compara um valor de cada linha da coluna escolhida e compara qual é o maior em módulo. Após isso, realiza a troca de linhas caso necessário
 * para deixar o pivô da coluna sendo maior entre eles. Exibindo passo a passo.
 * @param matriz Matriz onde estará os valores
 * @param ordem Dimensão da matriz
 * @param linhaPivo Linha onde o número pivô está
 * @param colunaPivo Coluna onde o númeor pivô está
 */
void fixColunaPivo(int matriz[10][10], unsigned ordem, unsigned linhaPivo, unsigned colunaPivo){
  int maior = matriz[linhaPivo][colunaPivo];
  unsigned temp1, temp2, linha = 0;

  for(unsigned i = 0; i < ordem; i++){
    temp1 = matriz[i][colunaPivo];
    temp2 = maior;
    if(matriz[i][colunaPivo] < 0){
      temp1 *= -1;
    }
    if(maior < 0){
      temp2 *= -1;
    }
    if(temp1 > temp2){
      maior = matriz[i][colunaPivo];
      linha = i;
    }
  }

  int temp;
  if(maior != matriz[linhaPivo][colunaPivo]){
    printf("[ -> ] Trocando linha [%d] com linha [%d]\n", linha+1, linhaPivo+1);
    for(unsigned i = 0; i < ordem; i++){
      temp = matriz[linhaPivo][i];
      matriz[linhaPivo][i] = matriz[linha][i];
      matriz[linha][i] = temp;
    }
    exibeMatriz(matriz, ordem);
  }
}

/**
 * @brief Cria a matriz.
 * Usuário inicializa os valores da matriz seguido de uma confirmação onde será repetido indefinidas vezes até que o usuário aceite a matriz.
 * @param matriz Matriz de no máximo 10x10
 * @param ordem Ponteiro para armazenar a dimensão da matriz
 */
void defineMatriz(int matriz[10][10], unsigned *ordem){
  char esc;
  printf("[ -> ] Inicialzando matriz...\n");
  do{
    printf("[ <- ] Insira a ordem da matriz > ");
    scanf("%d", &(*ordem));
    for(unsigned i = 0; i < *ordem; i++){
      printf("------- Linha %d --------\n", i+1);
      for(unsigned j = 0; j < *ordem; j++){
        printf("Coluna %d >", j+1);
        scanf("%d", &matriz[i][j]);
      }
    }
    system("cls");
    printf("[ -> ] A matriz criada foi: \n");
    exibeMatriz(matriz, *ordem);
    printf("[ <- ] Deseja continuar? (S/n) > ");
    scanf(" %c", &esc);
  } while(esc == 'N' || esc == 'n');
}

int main(){
  int matriz[10][10];
  char esc;
  unsigned ordem;
  do{
    defineMatriz(matriz, &ordem);
    printf("[ <- ] Deseja testar outra matriz? (S/n) > ");
    scanf(" %c", &esc);
  }while(esc == 'S' || esc == 's');
  return 0;
}