#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
	string dado;
	int bloco;
	char endereco[8];
}memPrinc;

typedef struct{
	string celulaA, celulaB, celulaC,celulaD;
	char  rotulo[2];
	int quadro;
}memCach;

typedef struct{
	int nacessos;
	int acertos, faltas;
	int leitura,escrita;
	int acerleitura,acerescrita;
	int faltleitura,faltescrita;
}estatisticas;

void menu2(estatisticas *es){
	printf("\n Numero de Acessos: %d\n Numero de Acertos: %d\n Numero de Faltas: %d\n",es->nacessos,es->acertos,es->faltas);
	printf(" Numero de Leituras: %d\n Numero de Escritas: %d\n Numero de Acertos na Leitura: %d\n",es->leitura,es->escrita,es->acerleitura);
	printf(" Numero de Acertos na Escrita: %d\n Numero de Faltas na Leitura: %d\n Numero de Faltas na Escrita: %d\n",es->acerescrita,es->faltleitura,es->faltescrita);
	system("pause");
}

void iniciaMemCache(memCach *p){
	int i;
	for(i=0;i<16;i++){
		p[i].celulaA=' ';
		p[i].celulaB=' ';
		p[i].celulaC=' ';
		p[i].celulaD=' ';
		for(int a=0;a<2;a++){
			p[i].rotulo[a]='2';
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
void iniciaEstatisticas(estatisticas * es){
	es->nacessos=0;
	es->acertos=0;
	es->faltas=0;
	es->leitura=0;
	es->escrita=0;
	es->acerleitura=0;
	es->acerescrita=0;
	es->faltleitura=0;
	es->faltescrita=0;	
}

void lerMem(memPrinc *p, memCach *c, estatisticas *es){
	char endere[8];
	int blcach=0,blprinc=0;
	int blocoAtual=0, blocoNovo=0;
	bool a=false;
	printf("Entre com o endereco para ser lido:[        ]\b\b\b\b\b\b\b\b\b");
	cin>>endere;
	es->nacessos++;
	es->leitura++;
	for(int i=0;i<6;i++){//calcula endereco lido
		if(i==0&&endere[i]=='1')//qual o num. do rotulo
			blocoNovo=blocoNovo+2;
		if(i==1&&endere[i]=='1')
			blocoNovo=blocoNovo+1;
			
		else if(i==2&&endere[i]=='1')//saber qual quadro da cache
			blcach=blcach+8;
		else if(i==3&&endere[i]=='1')
			blcach=blcach+4;
		else if(i==4&&endere[i]=='1')
			blcach=blcach+2;
		else if(i==5&&endere[i]=='1')
			blcach=blcach+1;
	}
	
	for(int i=0;i<2;i++){
		if(i==0&&c[blcach].rotulo[i]=='1')//qual o num. do rotulo atual
			blocoAtual=blocoAtual+2;
		if(i==0&&c[blcach].rotulo[i]=='2'){
			blocoAtual=blocoAtual+4;
			i++;}
		if(i==1&&c[blcach].rotulo[i]=='1')
			blocoAtual=blocoAtual+1;
	}
	
	if(blocoAtual!=blocoNovo){
		es->faltas++;
		es->faltleitura++;
		for(int i=0;i<256;i++){
			if(strncmp(endere,p[i].endereco,8)==0){//pesquisa qual o bloco na principal
				blprinc=p[i].bloco;
			}
		}
		cout<<blprinc;
		for(int i=0;i<256;i++){//grava informaçoes na cache
			if(blprinc==p[i].bloco){//procura bloco na mem.principal
				c[blcach].celulaA=p[i].dado;
				c[blcach].celulaB=p[i+1].dado;
				c[blcach].celulaC=p[i+2].dado;
				c[blcach].celulaD=p[i+3].dado;
				c[blcach].rotulo[0]=endere[0];
				c[blcach].rotulo[1]=endere[1];
				a=true;
			}
			if(a)
				break;
		}
	}
	else{
		es->acertos++;
		es->acerleitura++;
	}
	system("pause");
}

void escreverMem(memPrinc *p, memCach *c, estatisticas *es){
	char endereco[8];
	string novo;
	int novoRot=0,quadro=0,celula=0;
	int celulaP=0,rotuloAtual=0,blocoP=0;
	bool a=false;
		
	cout<<"Entre com o endereco para ser escrito:[        ]\b\b\b\b\b\b\b\b\b";
	cin>>endereco;
	cout<<"Entre com o dado para ser escrito: ";
	cin>>novo;
	//estatisticas
	es->nacessos++;
	es->escrita++;
	for(int i=0;i<8;i++){
		if(i==0&&endereco[i]=='1'){
			novoRot=novoRot+2;
			celulaP=celulaP+128;}
		else if(i==1&&endereco[i]=='1'){
			novoRot=novoRot+1;
			celulaP=celulaP+64;}
		else if(i==2&&endereco[i]=='1'){
			quadro=quadro+8;
			celulaP=celulaP+32;}
		else if(i==3&&endereco[i]=='1'){
			quadro=quadro+4;
			celulaP=celulaP+16;}
		else if(i==4&&endereco[i]=='1'){
			quadro=quadro+2;
			celulaP=celulaP+8;}
		else if(i==5&&endereco[i]=='1'){
			quadro=quadro+1;
			celulaP=celulaP+4;}
		else if(i==6&&endereco[i]=='1'){
			celula=celula+2;
			celulaP=celulaP+2;}
		else if(i==7&&endereco[i]=='1'){
			celula=celula+1;
			celulaP=celulaP+1;}
	}
	p[celulaP].dado=novo;//muda principal
	for(int i=0;i<2;i++){			
		if(i==0&&c[quadro].rotulo[i]=='1')//qual o num. do rotulo atual
			rotuloAtual=rotuloAtual+2;
		if(i==0&&c[quadro].rotulo[i]=='2'){
			rotuloAtual=rotuloAtual+4;
			i++;}
		if(i==1&&c[quadro].rotulo[i]=='1')
			rotuloAtual=rotuloAtual+1;
	}
	
	if(rotuloAtual!=novoRot){
		for(int i=0;i<256;i++){
			if(strncmp(endereco,p[i].endereco,8)==0){//pesquisa qual o bloco na principal
				blocoP=p[i].bloco;
			}
		}
		cout<<celulaP<<endl;
		for(int i=0;i<256;i++){//grava informaçoes na cache
			if(blocoP==p[i].bloco){//procura bloco na mem.principal
				c[quadro].celulaA=p[i].dado;
				c[quadro].celulaB=p[i+1].dado;
				c[quadro].celulaC=p[i+2].dado;
				c[quadro].celulaD=p[i+3].dado;
				c[quadro].rotulo[0]=endereco[0];
				c[quadro].rotulo[1]=endereco[1];
				a=true;
			}
			if(a)
				break;
		}
		es->faltas++;
		es->faltleitura++;
	}
	else{
		if(celula==0)
			c[quadro].celulaA=novo;
		else if(celula==1)
			c[quadro].celulaB=novo;
		else if(celula==2)
			c[quadro].celulaC=novo;
		else if(celula==3)
			c[quadro].celulaD=novo;
		es->acertos++;
		es->acerleitura++;
	}
	system("pause");	
}

void mostraCache(memCach *c){
	printf(" Rotulo  Quadro Celula0 Celula1 Celula2 Celula3\n");
	for(int i=0;i<16;i++){
		cout<<"  ";
		for(int a=0;a<2;a++){
			if(c[i].rotulo[a]=='2'){
				printf("%c", ' ');}
			else{
				printf("%c", c[i].rotulo[a]);}
		}
		cout<<setw(9)<<c[i].quadro;
		cout<<setw(8)<<c[i].celulaA;
		cout<<setw(8)<<c[i].celulaB;
		cout<<setw(8)<<c[i].celulaC;
		cout<<setw(8)<<c[i].celulaD;
		cout<<endl;
	}
}

void menu(){
	printf(" 1- Ler Memoria\n 2- Escrever Memoria\n 3- Estatisticas\n");
	printf(" 4- Mostrar Memoria Principal\n");
	printf(" Entre com a opcao: ");
}

int main(){
	int n;
	memPrinc memP[256];
	memCach memC[16];
	estatisticas est;
	iniciaMemPrincipal(memP);
	iniciaMemCache(memC);
	iniciaEstatisticas(&est);
	while(1){
		system("cls");
		mostraCache(memC);
		menu();
		
		
		scanf("%d", &n);
		if(n==1){//ler memoria
			lerMem(memP, memC,&est);
		}
		else if(n==2){//escrever memoria
			escreverMem(memP, memC,&est);
		}
		else if(n==3){//statisticas
			menu2(&est);			
		}
		else if(n==4){
			mostraPrincipal(memP);
			system("pause");
		}
	}
   cout<<endl;

   return 0;
}