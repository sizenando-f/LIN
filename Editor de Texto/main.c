#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pegaTexto(char frase[], char texto[][82]){
  int fraseTam = strlen(frase)/75;
  for (int i = 0; i < fraseTam; i++){
    strcpy(texto[i], "");
  }

  char * palavra = strtok(frase, " ");
  strcpy(texto[0], palavra);
  strcat(texto[0], " ");

  palavra = strtok(NULL, " ");

  for (int i = 0; i < fraseTam+2; i++){
    int check = 0;
    while(check == 0 && palavra != NULL){
      strcat(texto[i], palavra);
      
      if(strlen(texto[i]) > 80){
        check = 1;
        char * ponteiro = strrchr(texto[i], ' ');
        *ponteiro = '\0';
        strcpy(texto[i + 1], palavra);
      }

      if(check){
        strcat(texto[i+1], " ");
      } else {
        strcat(texto[i], " ");
      }

      palavra = strtok(NULL, " ");
    }
  }
}

void imprimeTexto(char texto[][82], int fraseTam){
    for (int i = 0; i < fraseTam; i++)
    {
      printf("%s\n", texto[i]);
    }
}

void encontraPalavra(char texto[][82], char palavra[], int fraseTam){
  char temp[50][82];
  int cont = 0;
  for(int i = 0; i < fraseTam; i++){
    strcpy(temp[i], texto[i]);
  }

  for (int i = 0; i < fraseTam; i++) {
    char *linha = strdup(temp[i]); // Copia a linha para uma variável temporária
    char *palavraAtual = strtok(linha, " ,().-");
    int coluna = 0;

    while (palavraAtual != NULL) {
        if (strcmp(palavraAtual, palavra) == 0) {
            printf("Palavra encontrada na linha %d\n", i + 1);
            printf("Na coluna %d\n", coluna);
            cont++;
        }
        coluna += strlen(palavraAtual) + 1; // Avança a coluna para o início da próxima palavra
        palavraAtual = strtok(NULL, " ,().-");
    }

    free(linha); // Libera a memória alocada pela strdup
  }
  if(!cont){
    printf("PALAVRA NAO EXISTE!\n");
  }
}

void transformaEmFrase(char texto[][82], char frase[], int fraseTam){
  strcpy(frase, "");

  for (int i = 0; i < fraseTam; i++){
    strcat(frase, texto[i]);
  }
}

void trocaPalavra(char texto[][82], char palavraAntiga[], char palavraNova[], int fraseTam, int codigo){
  char frase[3000] = "";
  transformaEmFrase(texto, frase, fraseTam);
  
}

void menuSubstituir(char texto[][82], int fraseTam){
  int esc;
  char palavraAntiga[30], palavraNova[30];
  while((esc < 1 || esc > 3) || (esc != 3)){
    printf("------------ # SUBSTITUIR PALAVRA # ------------\n");
    printf("1) SUBSTITUIR PRIMEIRA OCORRENCIA \n");
    printf("2) SUBSTITUIR TODAS OCORRENCIAS \n");
    printf("3) VOLTAR \n");
    printf("---------------------------------------------\n");
    printf("SUA ESCOLHA: ");
    scanf("%d", &esc);
    switch (esc){
      case 1:
        printf("PALAVRA QUE DESEJA SUBSTITUIR: ");
        scanf("%s", palavraAntiga);
        printf("PALAVRA NOVA: ");
        scanf("%s", palavraNova);
        trocaPalavra(texto, palavraAntiga, palavraNova, fraseTam, 0);
      break;
      case 2:

      break;
      default:
      
      break;
    }
  }

}

void menuPrincipal(char texto[][82], int fraseTam){
  int esc;
  char palavra[20];
  while((esc < 1 || esc > 6) || (esc != 6)){
    printf("-------- # EDITOR DE TEXTO # --------\n");
    printf("1) IMPRIMIR TEXTO FORMATADO \n");
    printf("2) ENCONTRAR PALAVRA \n");
    printf("3) OPCOES DE SUBSTITUICAO \n");
    printf("4) OPCOES DE CAIXA \n");
    printf("5) OPCOES DE ALINHAMENTO \n");
    printf("6) ENCERRAR PROGRAMA\n");
    printf("-------------------------------------\n");
    printf("SUA ESCOLHA: ");
    scanf("%d", &esc);
    switch(esc){
      case 1:
        imprimeTexto(texto, fraseTam);
        break;
      case 2:
        printf("QUAL PALAVRA DESEJA ENCONTRAR? -> ");
        scanf("%s", palavra);
        encontraPalavra(texto, palavra, fraseTam);
        break;
      case 3:
        menuSubstituir(texto, fraseTam);
        break;
      case 4:
        break;

      case 5:
        break;

      case 6:
        break;

      default:
        break;
    }

    
  }
}

int main(){
  char frase[] = "William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates, e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na comercializa��o deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. Fonte:";
  char texto[50][82];
  int fraseTam = strlen(frase)/75;
  pegaTexto(frase, texto);

  menuPrincipal(texto, fraseTam);
  return 0;
}