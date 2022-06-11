#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define PC 0.6
#define PM 0.001
#define Np 20
#define Nb 25
#define Ne 0.3

void gera_populacao(int populacao_inicial[][Np],int n){
	int i,j;
	srand((unsigned)time(NULL));
	for(i=0;i<Np;i++){
		for(j=0;j<n;j++){
			populacao_inicial[j][i]=rand()%2;
		}
	}
}
void decodifica(int populacao[][Np], double pop_decodificada[][Np]){
	int a=(Nb+1),b=(Nb-1),i,j,posicao=1,somatorio=0;
    double min_1=3.15;
    double max_1=9.2;
    double min_2=1.5;
    double max_2=2.0;
    double min_3=1.3;
    double max_3=1.6;
    double min_4=1.4438;
    double max_4=1.44726;
    double min_5=1.465;
    double max_5=1.46817;
    
	for(i=0;i<Np;i++){
        for(j=0;j<Nb;j++){
            somatorio=somatorio+populacao[j][i]*pow(2,Nb-posicao);
            posicao=posicao+1;
        }
        pop_decodificada[0][i]=min_1+(((max_1-min_1)/(pow(2,Nb)-1))*somatorio);
        
		somatorio=0;
        posicao=1;
        for(j=Nb;j<(a+b);j++){
            somatorio=somatorio+populacao[j][i]*pow(2,Nb-posicao);
            posicao=posicao+1;
        }
        pop_decodificada[1][i]=min_2+(((max_2-min_2)/(pow(2,Nb)-1))*somatorio);
        
		somatorio=0;
        posicao=1;
        for (j=(a+b);j<(a+(2*b)+1);j++){
            somatorio=somatorio+populacao[j][i]*pow(2,Nb-posicao);
            posicao=posicao+1;
    	}
        pop_decodificada[2][i]=min_3+(((max_3-min_3)/(pow(2,Nb)-1))*somatorio);
        
		somatorio=0;
        posicao=1;
        for (j=(a+(2*b)+1);j<(a+(3*b)+2);j++){
            somatorio=somatorio+(populacao[j][i]*pow(2,Nb-posicao));
            posicao=posicao+1;
        }
        pop_decodificada[3][i]=min_4+(((max_4-min_4)/(pow(2,Nb)-1))*somatorio);
        
		somatorio=0;
        posicao=1;
       for (j=(a+(3*b)+2);j<(a+(4*b)+3);j++){
            somatorio=somatorio+populacao[j][i]*pow(2,Nb-posicao);
            posicao=posicao+1;
    	}
        pop_decodificada[4][i]=min_5+(((max_5-min_5)/(pow(2,Nb)-1))*somatorio);

		somatorio=0;
        posicao=1;
	}
}
void fitness(double pop_decodificada[][Np],double a2[][Np]){
	FILE *p;
	int count,count2,sinal,div,x[15],QteNeuronio=10,i,resultado,j,k,neo23=9;
	char c;
	double IW[10][5],LW[1][10],b1[10][1],b2,a1[10][1],num,ax[50],prod[10][1],entrada[5][1];
	p=fopen("IW_fibra_lc.txt","r");
       if(!p)
       {
          printf("\nErro de abertura!\n\n");
          system("PAUSE");
          exit(1);
       }
       count=0;
       count2=0;
       sinal=1;
       div=1;
       while (!feof(p))
       {
          c=getc(p);
          if (c=='-')
          {
             sinal=-1;
          }
          if (c=='.')
          {
             div=count;
          }          
          if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
          {
             x[count]=c;
             x[count]=x[count]-48;
             count++;
          }
          if (c=='0'&&count!=0)
          {   
             x[count]=c;
             x[count]=x[count]-48;
             count++;
          }
          if (div<=0&&count==0&&c=='0')
          {
             div=div-1;
          }
          if (count==15)
          {
             num=0.0;           
             for (count=0;count<15;count++)
             {
                num=num+x[count]*pow(10,div-count-1);
             }
             ax[count2]=sinal*num;
             count2++;
             count=0;
             div=1;
             sinal=1;
          }   
       }
       fclose(p);
       count2=0;
       for (i=0; i<neo23; ++i)
       {  
          for (j=0; j<5; ++j)  
          {       
             IW[i][j]=ax[count2];
             count2++;
          }
       }
       p=fopen("LW_fibra_lc.txt","r");
       if(!p)
       {
          printf("\nErro de abertura!\n\n");
          system("PAUSE");
          exit(1);
       }
       count=0;
       count2=0;
       sinal=1;
       div=1;
       while (!feof(p))
       {
          c=getc(p);
          if (c=='-')
          {
             sinal=-1;
          }
          if (c=='.')
          {
             div=count;
          }          
          if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
          {
             x[count]=c;
             x[count]=x[count]-48;
             count++;
          }
          if (c=='0'&&count!=0)
          {   
             x[count]=c;
             x[count]=x[count]-48;
             count++;
          }
          if (div<=0&&count==0&&c=='0')
          {
             div=div-1;
          }
          if (count==15)
          {
             num=0.0;           
             for (count=0;count<15;count=count+1)
             {
                num=num+x[count]*pow(10,div-count-1);
             }
             ax[count2]=sinal*num;
             count2++;
             count=0;
             div=1;
             sinal=1;
          }   
       }
       fclose(p);
       count2=0;
       for (i=0; i<1; ++i)
       {  
          for (j=0; j<neo23; ++j)  
          {       
             LW[i][j]=ax[count2];
             count2++;
          }
       }
       p=fopen("b1_fibra_lc.txt","r");
       if(!p)
       {
          printf("\nErro de abertura!\n\n");
          system("PAUSE");
          exit(1);
       }
       count=0;
       count2=0;
       sinal=1;
       div=1;
       while (!feof(p))
       {
          c=getc(p);
          if (c=='-')
          {
             sinal=-1;
          }
          if (c=='.')
          {
             div=count;
          }          
          if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
          {
             x[count]=c;
             x[count]=x[count]-48;
             count++;
          }
          if (c=='0'&&count!=0)
          {   
             x[count]=c;
             x[count]=x[count]-48;
             count++;
          }
          if (div<=0&&count==0&&c=='0')
          {
             div=div-1;
          }
          if (count==15)
          {
             num=0.0;           
             for (count=0;count<15;count=count+1)
             {
                num=num+x[count]*pow(10,div-count-1);
             }
             ax[count2]=sinal*num;
             count2++;
             count=0;
             div=1;
             sinal=1;
          }   
       }
       fclose(p);
       count2=0;
       for (i=0; i<neo23; ++i)
       {  
          for (j=0; j<1; ++j)  
          {       
             b1[i][j]=ax[count2];
             count2++;
          }
       }
       b2=4.68064731404687;
       for(k=0;k<Np;++k){
       	for(i=0;i<5;++i){
       		entrada[i][0]=pop_decodificada[i][k];
       	}
       	entrada[0][0]=entrada[0][0]/5;
	   	for (i=0; i<neo23; ++i)
       	{
        	  num=0.0;
          	for (j=0; j<5; ++j)
          	{
           	  num=num+IW[i][j]*entrada[j][0];
          	}
          	prod[i][0]=num;
       	}
       	for (i=0; i<neo23; ++i)
       	{
       	   for (j=0; j<1; ++j)
       	   {
       	      a1[i][j]=tanh(prod[i][j]+b1[i][j]);
       	   }
       	}
       	num=0.0;
       	for (i=0; i<1; ++i)
       	{
       	   num=0.0;
       	   for (j=0; j<neo23; ++j)
       	   {
       	      num=num+LW[i][j]*a1[j][0];
       	   }
       	}
       	a2[0][k]=num+b2;       
       	a2[0][k]=10*pow(10,a2[0][k]);
       }
}

void precisao(float distancia_acoplamento,double precisao_calc[][Np],double a2[][Np],double diferenca[][Np]){
	int i;
	double a[1][Np],s[1][Np],somatorio=0.0;
	for(i=0;i<Np;i++){ //aptidão padronizada
		diferenca[0][i]=distancia_acoplamento-a2[0][i];
	}
	for(i=0;i<Np;i++){ //squared error
		s[0][i]=pow(diferenca[0][i],2);
	}
	for(i=0;i<Np;i++){ //modulo do valor da diferença
		if(diferenca[0][i]<0){
			diferenca[0][i]=diferenca[0][i]*-1;
		}
	}
	for(i=0;i<Np;i++){ //aptidão ajustada
		a[0][i]=1/(1+s[0][i]);
	}
	for(i=0;i<Np;i++){
		somatorio=somatorio+a[0][i];
	}
	for(i=0;i<Np;i++){ //aptidão normalizada
		precisao_calc[0][i]=a[0][i]/somatorio;
	}
}
void quickSort(int populacao[][Np],double precisao_calc[][Np],double a2[][Np],double pop_decodificada[][Np],int n, double diferenca[][Np],int esquerda,int direita)
{
    int i, j,k, aux,aux_1,aux_2,aux_3,aux_4;
    double x;
    i = esquerda;
    j = direita;
    x = precisao_calc[0][(esquerda + direita) / 2];
 
    while(i <= j)
    {
        while(precisao_calc[0][i] < x && i < direita)
        {
            i++;
        }
        while(precisao_calc[0][j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            aux = precisao_calc[0][i];
            precisao_calc[0][i] = precisao_calc[0][j];
            precisao_calc[0][j] = aux;
            i++;
            j--;
            
            aux_1=a2[0][j];
			a2[0][j]=a2[0][i];
			a2[0][i]=aux_1;
			for(k=0;k<5;k++){
				aux_2=pop_decodificada[k][j];
				pop_decodificada[k][j]=pop_decodificada[k][i];
				pop_decodificada[k][i]=aux_2;
			}
			for(k=0;k<n;k++){
				aux_3=populacao[k][j];
				populacao[k][j]=populacao[k][i];
				populacao[k][i]=aux_3;
			}	
			aux_4=diferenca[0][j];
			diferenca[0][j]=diferenca[0][i];
			diferenca[0][i]=aux_4;
        }
    }
    if(j > esquerda)
    {
        quickSort(populacao,precisao_calc,a2,pop_decodificada,n,diferenca, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(populacao,precisao_calc,a2,pop_decodificada,n,diferenca,  i, direita);
    }
}
void ordena(int populacao[][Np],double precisao_calc[][Np],double a2[][Np],double pop_decodificada[][Np],int n, double diferenca[][Np]){
	int i,j,k,aux_3;
	double aux,aux_2,aux_1,aux_4;
	for(i=0;i<Np;i++){
		for(j=i;j<Np;j++){
			if(precisao_calc[0][i]>precisao_calc[0][j]){
				aux=precisao_calc[0][j];
				precisao_calc[0][j]=precisao_calc[0][i];
				precisao_calc[0][i]=aux;
				
				aux_1=a2[0][j];
				a2[0][j]=a2[0][i];
				a2[0][i]=aux_1;
				for(k=0;k<5;k++){
					aux_2=pop_decodificada[k][j];
					pop_decodificada[k][j]=pop_decodificada[k][i];
					pop_decodificada[k][i]=aux_2;
				}
				for(k=0;k<n;k++){
					aux_3=populacao[k][j];
					populacao[k][j]=populacao[k][i];
					populacao[k][i]=aux_3;
				}	
				aux_4=diferenca[0][j];
				diferenca[0][j]=diferenca[0][i];
				diferenca[0][i]=aux_4;
			}
		}
	}
}
void selecao(double precisao_calc[][Np],int nova_populacao[][Np],int populacao[][Np],int n){
	int i,j,k;
	double r,Soma;
	srand((unsigned)time(NULL));
	for(i=0;i<Np;i++){
		r=(double)(rand()%10001)/10000;
		j=-1;
		Soma=0.0;
		while(Soma<r){
			j++;
			Soma=Soma+precisao_calc[0][j];
		}
		for(k=0;k<n;k++){
			nova_populacao[k][i]=populacao[k][j];
		}
	}
}
void cruzamento(int nova_populacao[][Np]){
	int i,j,aux,ponto_de_corte,a=(Nb+1),b=(Nb-1);
	double r;
	srand((unsigned)time(NULL));
	i=0;
	while(i<Np){
		r=(double)(rand()%101)/100;
		if(r<=PC){
			ponto_de_corte=rand()%Nb;
			for(j=0;j<=ponto_de_corte;j++){
				aux=nova_populacao[j][i];
				nova_populacao[j][i]=nova_populacao[j][i+1];
				nova_populacao[j][i+1]=aux;
			}
			ponto_de_corte=(rand()%Nb)+Nb;
			for(j=Nb;j<=ponto_de_corte;j++){
				aux=nova_populacao[j][i];
				nova_populacao[j][i]=nova_populacao[j][i+1];
				nova_populacao[j][i+1]=aux;
			}
			ponto_de_corte=(rand()%Nb)+(2*Nb);
			for(j=(a+b);j<=ponto_de_corte;j++){
				aux=nova_populacao[j][i];
				nova_populacao[j][i]=nova_populacao[j][i+1];
				nova_populacao[j][i+1]=aux;
			}
			ponto_de_corte=(rand()%Nb)+(3*Nb);
			for(j=(a+(2*b)+1);j<=ponto_de_corte;j++){
				aux=nova_populacao[j][i];
				nova_populacao[j][i]=nova_populacao[j][i+1];
				nova_populacao[j][i+1]=aux;
			}
			ponto_de_corte=(rand()%Nb)+(4*Nb);
			for(j=(a+(3*b)+2);j<=ponto_de_corte;j++){
				aux=nova_populacao[j][i];
				nova_populacao[j][i]=nova_populacao[j][i+1];
				nova_populacao[j][i+1]=aux;
			}
		}
		i=i+2;
	}
}
void mutacao(int nova_populacao[][Np]){
	int i,j,aux,ponto_de_mutacao;
	double r;
	srand((unsigned)time(NULL));
	for(i=0;i<Np;i++){
		r=(double)(rand()%101)/100;
		if(r<=PM){
			ponto_de_mutacao=rand()%Nb;
			if(nova_populacao[ponto_de_mutacao][i]==0)
				nova_populacao[ponto_de_mutacao][i]=1;
			if(nova_populacao[ponto_de_mutacao][i]==1)
				nova_populacao[ponto_de_mutacao][i]=0;
				
			ponto_de_mutacao=(rand()%Nb)+Nb;
			if(nova_populacao[ponto_de_mutacao][i]==0)
				nova_populacao[ponto_de_mutacao][i]=1;
			if(nova_populacao[ponto_de_mutacao][i]==1)
				nova_populacao[ponto_de_mutacao][i]=0;
				
			ponto_de_mutacao=(rand()%Nb)+(2*Nb);
			if(nova_populacao[ponto_de_mutacao][i]==0)
				nova_populacao[ponto_de_mutacao][i]=1;
			if(nova_populacao[ponto_de_mutacao][i]==1)
				nova_populacao[ponto_de_mutacao][i]=0;
				
			ponto_de_mutacao=(rand()%Nb)+(3*Nb);
			if(nova_populacao[ponto_de_mutacao][i]==0)
				nova_populacao[ponto_de_mutacao][i]=1;
			if(nova_populacao[ponto_de_mutacao][i]==1)
				nova_populacao[ponto_de_mutacao][i]=0;
				
			ponto_de_mutacao=(rand()%Nb)+(4*Nb);
			if(nova_populacao[ponto_de_mutacao][i]==0)
				nova_populacao[ponto_de_mutacao][i]=1;
			if(nova_populacao[ponto_de_mutacao][i]==1)
				nova_populacao[ponto_de_mutacao][i]=0;
		}
	}
}
void elitismo(int n,int populacao_inicial[][Np],int nova_populacao[][Np],double populacao_decodificada[][Np],double nova_populacao_decodificada[][Np],double a2[][Np], double nova_a2[][Np],double precisao_calculada[][Np],double nova_precisao_calculada[][Np],double diferenca[][Np],double nova_diferenca[][Np]){
	int i,e=(Np*Ne),j,k;
	j=0;
	for(i=e;i<Np;i++){
		for(k=0;k<n;k++){
			populacao_inicial[k][j]=nova_populacao[k][i];
		}
		populacao_decodificada[0][j]=nova_populacao_decodificada[0][i];
		precisao_calculada[0][j]=nova_precisao_calculada[0][i];
		a2[0][j]=nova_a2[0][i];
		diferenca[0][j]=nova_diferenca[0][i];
		j++;
	}
}
int main(){
	int n=(Nb*5),i,j,populacao_inicial[n][Np],nova_populacao[n][Np],contador;
	float distancia_acoplamento;
	double a2[1][Np],populacao_decodificada[5][Np],precisao_calculada[1][Np],diferenca[1][Np];
	double nova_a2[1][Np],nova_diferenca[1][Np],nova_populacao_decodificada[5][Np],nova_precisao_calculada[1][Np];
	FILE *Acoplamento;
	FILE *raio;
	FILE *Distancia;
	FILE *n1;
	FILE *n2;
	FILE *lambda;
	FILE *populacao;
	Acoplamento=fopen("Distância de Acoplamento 20.txt","w+");
	if(Acoplamento==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	raio=fopen("Raio do núcleo 20.txt","w+");
	if(raio==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	Distancia=fopen("Distância entre os guias 20.txt","w+");
	if(Distancia==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	n1=fopen("n1 20.txt","w+");
	if(n1==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	n2=fopen("n2 20.txt","w+");
	if(n2==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	lambda=fopen("Lambda 20.txt","w+");
	if(lambda==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	populacao=fopen("Populacao 20.txt","w+");
	if(populacao==NULL){
		printf("Houve um erro ao abrir o arquivo\n");
	}
	printf("Digite a Distancia de acoplamento para o acoplador baseado em fibra optica a ser otimizado\n");
	scanf("%f",&distancia_acoplamento);
	//inicializando as funções
	gera_populacao(populacao_inicial,n);
	decodifica(populacao_inicial,populacao_decodificada);
	fitness(populacao_decodificada,a2);
	precisao(distancia_acoplamento,precisao_calculada,a2,diferenca);
	ordena(populacao_inicial,precisao_calculada,a2,populacao_decodificada,n,diferenca);
	contador=1;
	do{
		printf("GERACAO - %i\n",contador);
		selecao(precisao_calculada,nova_populacao,populacao_inicial,n);
		cruzamento(nova_populacao);
		mutacao(nova_populacao);
		decodifica(nova_populacao,nova_populacao_decodificada);
		fitness(nova_populacao_decodificada,nova_a2);
		precisao(distancia_acoplamento,nova_precisao_calculada,nova_a2,nova_diferenca);
		ordena(nova_populacao,nova_precisao_calculada,nova_a2,nova_populacao_decodificada,n,nova_diferenca);
		elitismo(n,populacao_inicial,nova_populacao,populacao_decodificada,nova_populacao_decodificada,a2,nova_a2,precisao_calculada,nova_precisao_calculada,diferenca,nova_diferenca);
		decodifica(populacao_inicial,populacao_decodificada);
		fitness(populacao_decodificada,a2);
		precisao(distancia_acoplamento,precisao_calculada,a2,diferenca);
		ordena(populacao_inicial,precisao_calculada,a2,populacao_decodificada,n,diferenca);
		contador++;
    	fprintf(Acoplamento,"%.16f\n",a2[0][(Np-1)]);//Lc
    	fprintf(Distancia,"%.16f\n",populacao_decodificada[0][(Np-1)]);//d
    	fprintf(raio,"%.16f\n",populacao_decodificada[1][(Np-1)]);//a
    	fprintf(lambda,"%.16f\n",populacao_decodificada[2][(Np-1)]);//lambda
    	fprintf(n1,"%.16f\n",populacao_decodificada[3][(Np-1)]);//n1
    	fprintf(n2,"%.16f\n",populacao_decodificada[4][(Np-1)]);//n2
    	for(i=0;i<Np;i++){
    		fprintf(populacao,"%.16f\n",a2[0][i]);
    	}
    	fprintf(populacao,"\n\n");
	}while(contador<=200);
	system("pause");
}