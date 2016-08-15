#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "levenshtein.h"
#include <string.h>

#define MAX 100
#define per 0.70

time_t Segundos;
FILE *file;
char entrada[512];
int comeco;

void help()
{
	system("cls");
	printf("Escritas entre asteriscos são falas do Jarvis\n\nComandos do J.A.R.V.I.S.:\nABRIR\nCALCULAR\nCRIAR\nDESLIGAR\nENCERRAR\nLIMPAR\nPESQUISAR\nREINICIAR\n");
}


struct pilhaFloat
{
    int topo;
    float v[MAX];
} pf;

struct pilhaChar
{
    int topo;
    char v[MAX];
} pc;

float fazConta(float vlr, char op, float vlr2)
{
    if ('+' == op)
        return vlr + vlr2;
    else
   		if ( '-' == op)
       		return vlr - vlr2;
  		else
    		if ( '*' == op)
   			    return  vlr * vlr2;
   		    else
    			if ('/' == op)
    			    return vlr / vlr2;
}

void calcula(char str[])
{
    int i;
    float vlr;
    float vlr2;
    char op;

    /* para cada caracter */
    for ( i= 0; str[i] != '\0'; i++)
    {
        /* se for um operador, empilha em pc*/
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 'r')
        {
            pc.v[pc.topo++] = str[i];
        }
		else 
			if (str[i] >= '0' && str[i] <= '9')
			{ /* se for um número */
       	     sscanf(str+i, "%f", &vlr); /* le o valor */
       	     pf.v[pf.topo++] = vlr; /* empilha o valor */	

            	 while (str[i+1] == '.' || (str[i+1] >= '0' && str[i+1] <= '9')) /* passa pelo float */
            	    i++;

        	}
		else 
		if (str[i] == ')')
		{ /* se for um fecha parênteses */
            vlr2 = pf.v[--(pf.topo)];                    /* desempilha o primeiro valor */
            vlr = pf.v[--(pf.topo)];                     /* desempilha o segundo valor */
            op = pc.v[--(pc.topo)];                      /* desempilha a operação */
            pf.v[pf.topo++] = fazConta (vlr, op, vlr2); /* calcula */
        }
        /* else --> se for um abre parenteses, simplesmente ignora */
    }
    printf("\r");
    printf("* =%g *",pf.v[pf.topo - 1]);
    printf("                    \n");
}



void abrir(int x)
{
	x+=2;
	int y=0;
	char arquivo[100], local[256] = "start ";
	for(x;entrada[x]!='\0';x++,y++)
	{
		if(entrada[x]!=' ')
			arquivo[y] = entrada[x];
	}
	arquivo[y] = '\0';
	strcpy(local,arquivo);
	strcat(local,".txt");
	if((file = fopen(local,"r"))==NULL)
	{
		fclose(file);
		strcpy(local,arquivo);
		strcat(local,".pdf");
		if((file = fopen(local,"r"))==NULL)
		{
			fclose(file);
			strcpy(local,arquivo);
			strcat(local,".lnk");
			if((file = fopen(local,"r"))==NULL)
			{
				fclose(file);
				strcpy(local,arquivo);
				strcat(local,".mp4");
				if((file = fopen(local,"r"))==NULL)
				{
					fclose(file);
					strcpy(local,arquivo);
					strcat(local,".mp3");
					if((file = fopen(local,"r"))==NULL)
					{
						fclose(file);
						strcpy(local,arquivo);
						strcat(local,".jpeg");
						if((file = fopen(local,"r"))==NULL)
						{
							fclose(file);
							strcpy(local,arquivo);
							strcat(local,".jpg");
							if((file = fopen(local,"r"))==NULL)
							{
								fclose(file);
								strcpy(local,arquivo);
								strcat(local,".gif");
								if((file = fopen(local,"r"))==NULL)
								{
									fclose(file);
									strcpy(local,arquivo);
									strcat(local,".png");
									if((file = fopen(local,"r"))==NULL)
									{
										fclose(file);
										strcpy(local,arquivo);
										strcat(local,".wav");
										if((file = fopen(local,"r"))==NULL)
										{
											fclose(file);
											strcpy(local,arquivo);
											strcat(local,".exe");
											if((file = fopen(local,"r"))==NULL)
											{
												fclose(file);
												strcpy(local,arquivo);
												strcat(local,".pptx");
												if((file = fopen(local,"r"))==NULL)
												{
													fclose(file);
													strcpy(local,arquivo);
													strcat(local,".docx");
													if((file = fopen(local,"r"))==NULL)
													{
														fclose(file);
														strcpy(local,arquivo);
														strcat(local,".cpp");
														if((file = fopen(local,"r"))==NULL)
														{
															char local1[256]="start chrome.exe ";
															fclose(file);
															strcpy(local,arquivo);
															strcat(local,".com");
															strcat(local1,local);
															system(local1);	
														}
														else
														{
															file = NULL;
															fclose(file);
															system(local);
														}
													}
													else
													{
														file = NULL;
														fclose(file);
														system(local);
													}	
												}
												else
												{
													file = NULL;
													fclose(file);
													system(local);
												}
											}
											else
											{
												system("cls");
												file = NULL;
												fclose(file);
												system(local);
											}	
										}
										else
										{
											file = NULL;
											fclose(file);
											system(local);
										}	
									}
									else
									{
										file = NULL;
										fclose(file);
										system(local);
									}	
								}
								else
								{
									file = NULL;
									fclose(file);
									system(local);
								}	
							}
							else
							{
								file = NULL;
								fclose(file);
								system(local);
							}	
						}
						else
						{
							file = NULL;
							fclose(file);
							system(local);
						}	
					}
					else
					{
						file = NULL;
						fclose(file);
						system(local);
					}
				}
				else
				{	
					file = NULL;
					fclose(file);
					system(local);
				}
			}
			else
			{	
				file = NULL;
				fclose(file);
				system(local);
			}
		}
		else
		{	
			file = NULL;
			fclose(file);
			system(local);
		}
	}
	else
	{
		file = NULL;
		fclose(file);
		system(local);
	}
}

void calcule(int x)
{
	if(entrada[x]==' ')
		x++;
	int y=0;
	char conta[50];
	for(x;entrada[x]!='\0';x++,y++)
		conta[y] = entrada[x];
	conta[y]='\0';
    calcula (conta);
}

void pesquise(int x)
{
	if(entrada[x]==' ')
		x++;
	int y=0;
	char pesquisa[100], executar[256]="start chrome.exe http://www.google.com.br/search?q=";
	for(x;entrada[x]!='\0';x++,y++)
	{
		if(entrada[x]!=' ')
			pesquisa[y] = entrada[x];
		else
		{
			pesquisa[y]='%';
			pesquisa[++y]='2';
			pesquisa[++y]='0';
		}
	}
	pesquisa[y] = '\0';
	strcat(executar,pesquisa);
	system(executar);
}

void crie(int x)
{
	x+=2;
	int y=0;
	bool j=false;
	char nome[100];
	for(x;entrada[x]!='\0';x++,y++)
	{
		if(entrada[x]!=' ')
			nome[y] = entrada[x];
		else
			nome[y]='_';
		if(entrada[x]=='.')
			j=true;
	}
	nome[y]='\0';
	if((file=fopen(nome,"r"))==NULL)
	{
		fclose(file);
		if(j==false)
		{
			char comando[256]="mkdir ";
			strcat(comando,nome);
			system(comando);
		}
		else
		{
			file=fopen(nome,"w");
			fclose(file);
			system(nome);
		}
	}
	else
	{
		fclose(file);
		printf("\rJá existe um arquivo com esse nome\n");
		system(nome);
	}
}


int charint(char a[],int y)
{
	int x;
	switch (a[y])
	{
		case '0':
			x=0;
		break;
		
		case '1':
			x=1;
		break;
		
		case '2':
			x=2;
		break;
		
		case '3':
			x=3;
		break;
		
		case '4':
			x=4;
		break;
		
		case '5':
			x=5;
		break;
		
		case '6':
			x=6;
		break;
		
		case '7':
			x=7;
		break;
		
		case '8':
			x=8;
		break;
		
		case '9':
			x=9;
		break;
	}
	return x;
}



int strint(char a[],int x,int y)
{
	int r=0;
	do
	{
		r*=10;
		r+=charint(a,x);
		x++;
	}while(x<=y);
	return r;
}



int ObtemHora()
{
	struct tm *DataAtual;
    time(&Segundos); //obtém a hora em segundos.
    DataAtual = localtime(&Segundos); //converte horas em segundos.
    return(DataAtual->tm_hour); //retorna as horas de 0 a 24.
}



int ObtemMinuto(void)
{
	struct tm *DataAtual;
    time(&Segundos); //obtém a hora em segundos.
    DataAtual = localtime(&Segundos); //converte horas em segundos.
    return(DataAtual->tm_min); //retorna os minutos de 0 a 59.
}



char intchar(int x)
{
	char a;
	switch (x)
	{
		case 0:
			a='0';
		break;
		
		case 1:
			a='1';
		break;
		
		case 2:
			a='2';
		break;
		
		case 3:
			a='3';
		break;
		
		case 4:
			a='4';
		break;
		
		case 5:
			a='5';
		break;
		
		case 6:
			a='6';
		break;
		
		case 7:
			a='7';
		break;
		
		case 8:
			a='8';
		break;
		
		case 9:
			a='9';
		break;
	}
	return a;
}



void desligar(int x)
{
	while(entrada[x]<'0' || entrada[x]>'9')
		x++;
	int y=-1;
	char horas[7],tempoh[3],tempom[3];
	for((x-=1);entrada[x]!='\0';x++,y++)
		if(entrada[x]>='0' && entrada[x]<='9')
			horas[y] = entrada[x];
	horas[(y)]='\0';
	tempoh[0]=horas[0];
	tempoh[1]=horas[1];
	tempoh[2]='\0';
	tempom[0]=horas[3];
	tempom[1]=horas[4];
	tempom[2]='\0';
	int m = ((strint(tempom,0,1))*60),h = ((strint(tempoh,0,1))*3600),oh = ((ObtemHora())*3600),om = ((ObtemMinuto())*60);
	int t = (m+h)-(oh+om);
	if(t<0)
	{
		t*=-1;
		t+=86400;
	}
	char shut[256]="shutdown -s -t ", str[64];
	sprintf(str, "%i", t);
	strcat(shut,str);
	system(shut);
}


void desligarem(int x)
{
	bool min=false, hor=false;
	while(entrada[x]<'0' || entrada[x]>'9')
		x++;
	int y=-1;
	char horas[10];
	for((x-=1);entrada[x]!='\0';x++,y++)
	{
		if(entrada[x]>='0' && entrada[x]<='9')
				horas[y] = entrada[x];
		else
			if(entrada[x]=='m' || entrada[x]=='h')
				if(entrada[x]=='m')
					min=true;
				else
					hor=true;
	}
	horas[y]='\0';
	if(min==true || hor==true)
	{
		int temp = strint(horas,0,(y-1));
		if(min==true)
			temp*=6;
		else
			temp*=360;
		char shut[256]="shutdown -s -t ", str[64];
		sprintf(str, "%i", temp);
		strcat(shut,str);
		system(shut);
		return;
	}
	horas[y]='\0';
	char shut[256]="shutdown -s -t ";
	strcat(shut,horas);
	system(shut);
}


void reiniciar(int x)
{
	while(entrada[x]<'0' || entrada[x]>'9')
		x++;
	int y=-1;
	char horas[7],tempoh[3],tempom[3];
	for((x-=1);entrada[x]!='\0';x++,y++)
		if(entrada[x]>='0' && entrada[x]<='9')
			horas[y] = entrada[x];
	horas[y]='\0';
	tempoh[0]=horas[0];
	tempoh[1]=horas[1];
	tempoh[2]='\0';
	tempom[0]=horas[3];
	tempom[1]=horas[4];
	tempom[2]='\0';
	int m = ((strint(tempom,0,1))*60),h = ((strint(tempoh,0,1))*3600),oh = ((ObtemHora())*3600),om = ((ObtemMinuto())*60);
	int t = (m+h)-(oh+om);
	if(t<0)
	{
		t*=-1;
		t+=86400;
	}
	char shut[256]="shutdown -r -t ", str[64];
	sprintf(str, "%i", t);
	strcat(shut,str);
	system(shut);
}


void reiniciarem(int x)
{
	bool min=false, hor=false;
	while(entrada[x]<'0' || entrada[x]>'9')
		x++;
	int y=-1;
	char horas[10];
	for((x-=1);entrada[x]!='\0';x++,y++)
	{
		if(entrada[x]>='0' && entrada[x]<='9')
				horas[y] = entrada[x];
		else
			if(entrada[x]=='m' || entrada[x]=='h')
				if(entrada[x]=='m')
					min=true;
				else
					hor=true;
	}
	horas[y]='\0';
	if(min==true || hor==true)
	{
		int temp = strint(horas,0,(y-1));
		if(min==true)
			temp*=6;
		else
			temp*=360;
		char shut[256]="shutdown -s -r ", str[64];
		sprintf(str, "%i", temp);
		strcat(shut,str);
		system(shut);
		return;
	}
	horas[y]='\0';
	char shut[256]="shutdown -s -r ";
	strcat(shut,horas);
	system(shut);
}

void strlwr(char *str) {
	while (*str != '\0') {
		if (65 <= *str && *str <= 90) {
			*str += 32 ;
		} 

		str++ ;
	}

}

void chopper(char *str) {
	while (*str !='\0') {
		if (*str == ' ' || *str == '\n') 
		{
			*str = '\0' ;
			break ;
		}
		str++ ;
	}
}


int main(void)
{


	while(1)
	{
		fgets(entrada, 500, stdin);
		strlwr(entrada);
		chopper(entrada) ;
		printf("%s\n", entrada) ;
		if(strcmp(entrada,"jarvis"))
			printf("");
		else
		{
			printf("*Olá, usuário*\n\n");
			do
			{
				gets(entrada);
				printf("*Em execução...*");
				strlwr(entrada);
				printf("\r                      \n");
			}while(strcmp(entrada,"pare") && strcmp(entrada,"parar"));
			printf("*J.A.R.V.I.S Encerrado*\n\n");
		}
	}
	return 0;
}
