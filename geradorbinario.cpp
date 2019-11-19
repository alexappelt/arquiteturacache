#include <stdio.h>
#include <stdlib.h>

void menu(){
	printf(" 1- Ler Memoria\n 2- Escrever memoria\n 3- Estatisticas\n");
	printf(" Entre com a opcao: ");
}

void menu2(){
	printf("\n 1- Numero de Acessos\n 2- Numero de Acertos\n 3- Numero de Faltas\n");
	printf(" 4- Numero de Leituras\n 5- Numero de Escritas\n 6- Numero de Acertos na Leitura\n");
	printf(" 7- Numero de Acertos na Escrita\n 8- Numero de Faltas na Leitura\n 9- Numero de Faltas na Escrita\n");
	printf(" Entre com a opcao: ");
}

typedef struct{
	char dado;
	int bloco;
	char endereco[8];
}memPrinc;

typedef struct{
	char celulaA, celulaB, celulaC,CelulaD;
	char  rotulo;
	int quadro;
}memCach;

int main()
{
   int num;
   int bin[8]; // <---------------
   int aux;

   printf("Digite o número (base decimal) para ser convertido: ");
   scanf("%d", &num);

   for (aux = 7; aux >= 0; aux--)
   {
      if (num % 2 == 0)
         bin[aux] = 0;
      else
         bin[aux] = 1;
      num = num / 2;
   }

   for (aux = 0; aux < 8; aux++)
       printf("%d", bin[aux]);

   printf("\n");

   return 0;
}