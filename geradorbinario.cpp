#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

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
	char  rotulo[8];
	int quadro;
}memCach;



void convertebinario(memPrinc *p){
   int i=0, aux, num, k=-1;
   
   char bin[8]; // <---------------
   p[i].bloco=0;

   for(i=0;i<256;i++){
         if(i%4==0){
            k++;
            
         }
         num=i;
            for (aux = 7; aux >= 0; aux--)
            {
               if (num % 2 == 0)
                  p[i].endereco[aux] = '0';
               else
                  p[i].endereco[aux] = '1';
               num = num / 2;
            }

            for (aux = 0; aux < 8; aux++){
                cout<<p[i].endereco[aux];
            }
             cout<<" - Bloco: "<<k;

            printf("\n");
}

}


int main()
{

   memPrinc mem[256];

   convertebinario(mem);
   cout<<endl;
   
   

   return 0;
}