#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

void menu2(){
	printf("\n 1- Numero de Acessos\n 2- Numero de Acertos\n 3- Numero de Faltas\n");
	printf(" 4- Numero de Leituras\n 5- Numero de Escritas\n 6- Numero de Acertos na Leitura\n");
	printf(" 7- Numero de Acertos na Escrita\n 8- Numero de Faltas na Leitura\n 9- Numero de Faltas na Escrita\n");
	printf(" Entre com a opcao: ");
}

typedef struct{
	string dado;
	int bloco;
	char endereco[8];
}memPrinc;

typedef struct{
	string celulaA, celulaB, celulaC,celulaD;
	char  rotulo[8];
	int quadro;
}memCach;


void iniciaMemCache(memCach *p){
	int i;
	for(i=0;i<16;i++){
		p[i].celulaA=' ';
		p[i].celulaB=' ';
		p[i].celulaC=' ';
		p[i].celulaD=' ';
		for(int a=0;a<8;a++){
			p[i].rotulo[a]=' ';
		}
		p[i].quadro=i;
	}
}

void iniciaMemPrincipal(memPrinc *p){
   int i=0, aux, num, k=-1,x;
   string letras[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q",
   "r","s","t","u","v","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N"
   ,"O","P","Q","R","S","T","U","V","X","Y","Z","1","2","3","4","5","6","7","8","9"};
   p[i].bloco=0;
   for(i=0;i<256;i++){
		if(i%4==0){
            k++;
		}
         num=i;
		for (aux = 7; aux >= 0; aux--){
			if (num % 2 == 0)
				p[i].endereco[aux] = '0';
			else
                p[i].endereco[aux] = '1';
            
			num = num / 2;
		}

		p[i].bloco=k;
		
		x = rand() % 59;
		p[i].dado=letras[x];
		
   }
}

void mostraPrincipal(memPrinc *p){
	printf("\nEndereco Bloco Dado\n");
	for(int i=0;i<256;i++){
		for(int a=0;a<8;a++){
			cout<<p[i].endereco[a];
		}
		cout<<setw(4)<<p[i].bloco;
		cout<<setw(6)<<p[i].dado;
		
		cout<<endl;
	}
}

void lerMem(memPrinc *p, memCach *c){
	

}
void mostraCache(memCach *c){
	printf(" Rotulo  Quadro Celula0 Celula1 Celula2 Celula3\n");
	for(int i=0;i<16;i++){
		for(int a=0;a<8;a++){
			printf("%c", c[i].rotulo[a]);
		}
		
		cout<<setw(4)<<c[i].quadro;
		cout<<setw(8)<<c[i].celulaA;
		cout<<setw(8)<<c[i].celulaB;
		cout<<setw(8)<<c[i].celulaC;
		cout<<setw(8)<<c[i].celulaD;
		
		cout<<endl;
	}
}

void menu(){
	printf(" 1- Ler Memoria\n 2- Escrever Memoria\n 3- Estatisticas\n");
	printf(" 4-Mostrar Memoria Principal\n");
	printf(" Entre com a opcao: ");
}

int main(){
	int n;
	memPrinc memP[256];
	memCach memC[16];
	iniciaMemPrincipal(memP);
	iniciaMemCache(memC);
	while(1){
		system("cls");
		mostraCache(memC);
		menu();
		scanf("%d", &n);
		if(n==1){//ler memoria
			
		}
		else if(n==2){//escrever memoria
			
		}
		else if(n==3){//statisticas
			menu2();
			scanf("%d",&n);
		}
	}
   cout<<endl;

   return 0;
}