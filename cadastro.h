#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMLT 51
#define LGLT 17
#define PWLT 17
typedef struct comp{
	int cod;
	char tit[20];
	char data[10];
	char hi[10];
	char hf[10];
	char local[30];
	char lembr[30];
	char dtlembr[10];
	char cmt[50];
}COMP;

typedef struct bday{
	int cod;
	char nome[30];
	char dt[10];
}BDAY;

typedef struct lembr{
	int cod;
	char tit[20];
	char dt[10];
	char hr[10];
}LEMBR;

void cadusr(){	
	int len;
	FILE *arq;
	arq=fopen("usr.dat","a");
	char name[NMLT], login[LGLT], pass[PWLT];
	printf("Nome: ");
	fgets(name,NMLT,stdin);
	len=strlen(name);
	if (name[len - 1] == '\n') name[--len] = 0;
	fflush(stdin);
	printf("\nLogin: ");
	fgets(login,LGLT,stdin);
	len=strlen(login);
	if (login[len - 1] == '\n') login[--len] = 0;
	fflush(stdin);
	//if(usrext(name,login,arq)==1) return;
	//usrext(name,login,arq);
	printf("\nSenha: ");
	fgets(pass,PWLT,stdin);
	fflush(stdin);
	fprintf(arq,"%s;%s;%s",name,login,pass);
	fclose(arq);
}

void cadcomp(char lgnusr[]){
	FILE *arq;
	arq=fopen("cmp.dat","a");
	COMP comp;
	int len;
	printf("Codigo: ");
	scanf("%d",&comp.cod);
	fflush(stdin);
	
	printf("Titulo: ");
	gets(comp.tit);
	len=strlen(comp.tit);
	if (comp.tit[len - 1] == '\n') comp.tit[--len] = 0;
	fflush(stdin);
	
	printf("Data: ");
	gets(comp.data);
	len=strlen(comp.data);
	if(comp.data[len - 1] == '\n') comp.data[--len] = 0;
	fflush(stdin);
	
	printf("Hora Inicio: ");
	gets(comp.hi);
	len=strlen(comp.hi);
	if(comp.hi[len - 1] == '\n') comp.hi[--len] = 0;
	fflush(stdin);
	
	printf("Hora Fim: ");
	gets(comp.hf);
	len=strlen(comp.hf);
	if(comp.hf[len - 1] == '\n') comp.hf[--len] = 0;
	fflush(stdin);
	
	printf("Local: ");
	gets(comp.local);
	len=strlen(comp.local);
	if(comp.local[len - 1] == '\n') comp.local[--len] = 0;
	fflush(stdin);
	
	printf("Lembrete: ");
	gets(comp.lembr);
	len=strlen(comp.lembr);
	if(comp.lembr[len - 1] == '\n') comp.lembr[--len] = 0;
	fflush(stdin);
	
	printf("Data lembrete: ");
	gets(comp.lembr);
	len=strlen(comp.dtlembr);
	if(comp.dtlembr[len - 1] == '\n') comp.dtlembr[--len] = 0;
	fflush(stdin);
	
	printf("Comentarios: ");
	gets(comp.cmt);
	len=strlen(comp.cmt);
	if(comp.cmt[len - 1] == '\n') comp.cmt[--len] = 0;
	fflush(stdin);
	fprintf(arq,"%d;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",comp.cod,comp.tit,comp.data,comp.hi,comp.hf,comp.local,comp.lembr,comp.dtlembr,comp.cmt,lgnusr);
	fclose(arq);
}

void cadbday(char lgnusr[]){
	BDAY bd;
	int len;
	FILE *arq;
	arq=fopen("bday.dat","a");
	printf("Codigo: ");
	scanf("%d",&bd.cod);
	fflush(stdin);
	
	printf("Nome: ");
	gets(bd.nome);
	len=strlen(bd.nome);
	if (bd.nome[len - 1] == '\n') bd.nome[--len] = 0;
	fflush(stdin);
	
	printf("Data: ");
	gets(bd.dt);
	len=strlen(bd.dt);
	if (bd.dt[len-1] == '\n') bd.dt[--len] = 0;
	fflush(stdin);
	
	fprintf(arq,"%d;%s;%s;%s",bd.cod,bd.nome,bd.dt,lgnusr);
	
	fclose(arq);
}

void cadlmbr(char lgnusr[]){
	LEMBR lb;
	int len;
	FILE *arq;
	arq=fopen("lmb.dat","a");
	printf("Codigo: ");
	scanf("%d",&lb.cod);
	fflush(stdin);
	
	printf("Titulo: ");
	gets(lb.tit);
	len=strlen(lb.tit);
	if (lb.tit[len - 1] == '\n') lb.tit[--len] = 0;
	fflush(stdin);
	
	printf("Data: ");
	gets(lb.dt);
	len=strlen(lb.dt);
	if (lb.dt[len - 1] == '\n') lb.dt[--len] = 0;
	fflush(stdin);
	
	printf("Hora: ");
	gets(lb.hr);
	len=strlen(lb.hr);
	if (lb.hr[len - 1] == '\n') lb.hr[--len] = 0;
	fflush(stdin);
	
	fprintf(arq,"%d;%s;%s;%s;%s\n",lb.cod,lb.tit,lb.dt,lb.hr,lgnusr);
	
	fclose(arq);
}
