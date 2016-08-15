#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <conio.c>
#include <locale.h>
#include <math.h>
#include <iostream>
#include <levenshtein.h>

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
    			else
    				if ('^' == op)
    				{
    					float potencia=1;
    					for(vlr2;vlr2>0;vlr2--)
    						potencia*=vlr;
    					return potencia;
					}
					else
						if ('r' == op)
						{
							for(vlr;vlr>0;vlr--)
								vlr2 = sqrt(vlr2);
							return vlr2;
						}
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
















bool vqd(char comando[])
{
	char resp, perg[52];
	strcpy(perg, comando);
	strcat(perg, "? (s/n)*");
	printf("\n\n                *Você quis dizer ");
	puts(perg);
	do
	{
		resp=getch();
		if(resp=='s')
			return true;
		else
			if(resp=='n')
			{
				printf("*Ok*\n");
				return false;
			}
	}while(resp!='s' && resp!='n');
}

struct test
{
	int babra=0, babortar=0, bcalcule=0, bcrie=0, bdesligar=0, bdesligaras=0, bdesligarem=0, bencerrar=0, bhelp=0, blimpar=0, bpesquise=0, bprocure=0, breiniciar=0, breiniciaras=0, breiniciarem=0;
};

void testereal(test dados)
{
	int spc;
	for(int x=0;entrada[x]!=' ';x++)
		spc=x;
	bool comandar;
	if(dados.babortar>=(per*6))
	{
		if(dados.babortar==7 || dados.babortar==6)
			system("shutdown -a");
		else
		{
			comandar=vqd("abortar");
			if(comandar == true)
				system("shutdown -a");
			else
				return;
		}
	}
	else
	{
		if(dados.babra>=(per*4))
		{
			if(dados.babra==5 || dados.babra==4)
				abrir(spc);
			else
			{
				comandar=vqd("abrir");
				if(comandar == true)
					abrir(spc);
				else
					return;
			}
		}
		else
		{
			if(dados.bcalcule>=(per*7))
			{
				if(dados.bcalcule==8 || dados.bcalcule==7)
					calcule(spc);
				else
				{
					comandar=vqd("calcular");
					if(comandar == true)
						calcule(spc);
					else
						return;
				}
			}
			else
			{
				if(dados.bcrie>=(per*4))
				{
					if(dados.bcrie==5 || dados.bcrie==4)
						crie(spc);
					else
					{
						comandar=vqd("crie");
						if(comandar == true)
						crie(spc);
						else
							return;
					}
				}
				else
				{
					if(dados.bhelp>=(per*4))
					{
						if(dados.bhelp==4)
								help();
						else
						{
							comandar=vqd("help");
							if(comandar == true)
								help();
							else
								return;
						}
					}
					else
					{
						if(dados.bdesligaras<dados.bdesligarem)
						{
							if(dados.bdesligaras==11)
									desligarem(spc);
							else
							{
								comandar=vqd("desligar em");
								if(comandar == true)
									desligarem(spc);
								else
									return;
							}
						}
						else
						{
							if(dados.bdesligar>=(per*8))
							{
								if(dados.bdesligar==8)
										system("shutdown -s -t 0");
								else
								{
									comandar=vqd("desligar");
									if(comandar == true)
										system("shutdown -s -t 0");
									else
										return;
								}
							}
							else
							{
								if(dados.bencerrar>=(per*7))
								{
									if(dados.bencerrar==7 || dados.bencerrar==8)
											exit(0);
									else
									{
										comandar=vqd("encerrar");
										if(comandar == true)
											exit(0);
										else
											return;
									}
								}
								else
								{
									if(dados.bdesligaras>dados.bdesligarem)
									{
										if(dados.bdesligarem==11)
												desligar(spc);
										else
										{
											comandar=vqd("desligar às");
											if(comandar == true)
												desligar(spc);
											else
												return;
										}
									}
									else
									{
										if(dados.blimpar>=(per*5))
										{
											if(dados.blimpar==5 || dados.blimpar==5)
													system("cls");
											else
											{
												comandar=vqd("limpe");
												if(comandar == true)
													system("cls");
												else
													return;
											}
										}
										else
										{
											if(dados.bpesquise>=(per*8))
											{
												if(dados.bpesquise==8 || dados.bpesquise==9)
														pesquise(spc);
												else
												{
													comandar=vqd("pesquisar");
													if(comandar == true)
														pesquise(spc);
													else
														return;
												}
											}
											else
											{
												if(dados.bprocure>=(per*7))
												{
													if(dados.bprocure==7 || dados.bprocure==8)
															pesquise(spc);
													else
													{
														comandar=vqd("procurar");
													if(comandar == true)
															pesquise(spc);
														else
															return;
													}
												}
												else
												{
													if(dados.breiniciaras>dados.breiniciarem)
													{
														if(dados.breiniciaras==11 || dados.breiniciaras==12)
															reiniciar(spc);
														else
														{
															comandar=vqd("reiniciar às");
															if(comandar == true)
																reiniciar(spc);
															else
																return;
														}
													}
													else
													{
														if(dados.breiniciaras<dados.breiniciarem)
														{
															if(dados.breiniciarem==11 || dados.breiniciarem==12)
																reiniciarem(spc);
															else
															{
																comandar=vqd("reiniciar em");
																if(comandar == true)
																	reiniciar(spc);
															else
																	return;
															}
														}
														else
														{
															if(dados.breiniciar>=(per*8))
															{
																if(dados.breiniciar==7 || dados.breiniciar==8)
																	system("shutdown -r -t 0");
																else
																{
																	comandar=vqd("reiniciar");
																	if(comandar == true)
																		system("shutdown -r -t 0");
																	else
																		return;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void teste()
{
	test corretor;
		if(entrada[0]=='a')
			corretor.babortar++; corretor.babra++;
		if(entrada[1]=='b')
			corretor.babortar++; corretor.babra++;
		if(entrada[2]=='r')
			corretor.babra++;
		if(entrada[3]=='a')
			corretor.babra++;
		if(entrada[3]=='i')
			corretor.babra++;
		if(entrada[4]=='r')
			corretor.babra++;
		if(entrada[2]=='o')
			corretor.babortar++;
		if(entrada[3]=='r')
			corretor.babortar++;
		if(entrada[4]=='t')
			corretor.babortar++;
		if(entrada[5]=='a')
			corretor.babortar++;
		if(entrada[6]=='r')
			corretor.babortar++;
		if(entrada[5]=='e')
			corretor.babortar++;
			
		if(entrada[0]=='c')
			corretor.bcalcule++; corretor.bcrie++;
		if(entrada[1]=='a')
			corretor.bcalcule++;
		if(entrada[2]=='l')
			corretor.bcalcule++;
		if(entrada[3]=='c')
			corretor.bcalcule++;
		if(entrada[4]=='u')
			corretor.bcalcule++;
		if(entrada[5]=='l')
			corretor.bcalcule++;
		if(entrada[6]=='e')
			corretor.bcalcule++;
		if(entrada[6]=='a')
			corretor.bcalcule++;
		if(entrada[7]=='r')
			corretor.bcalcule++;
		if(entrada[1]=='r')
			corretor.bcrie++;
		if(entrada[2]=='i')
			corretor.bcrie++;
		if(entrada[3]=='e')
			corretor.bcrie++;
		if(entrada[3]=='a')
			corretor.bcrie++;
		if(entrada[4]=='r')
			corretor.bcrie++;
			
		if(entrada[0]=='d')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[1]=='e')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[2]=='s')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[3]=='l')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[4]=='i')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[5]=='g')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[6]=='u')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[7]=='e')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[8]==' ')
			corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[9]=='a' || entrada[9]=='à')
			corretor.bdesligaras++;
		if(entrada[10]=='s')
			corretor.bdesligaras++;
		if(entrada[9]=='e')
			corretor.bdesligarem++;
		if(entrada[10]=='m')
			corretor.bdesligarem++;
		if(entrada[6]=='a')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		if(entrada[7]=='r')
			corretor.bdesligar++; corretor.bdesligaras++; corretor.bdesligarem++;
		
		if(entrada[0]=='e')
			corretor.bencerrar++;
		if(entrada[1]=='n')
			corretor.bencerrar++;
		if(entrada[2]=='c')
			corretor.bencerrar++;
		if(entrada[3]=='e')
			corretor.bencerrar++;
		if(entrada[4]=='r')
			corretor.bencerrar++;
		if(entrada[5]=='r')
			corretor.bencerrar++;
		if(entrada[6]=='a')
			corretor.bencerrar++;
		if(entrada[7]=='r')
			corretor.bencerrar++;
		if(entrada[6]=='e')
			corretor.bencerrar++;
		
		if(entrada[0]=='h')
			corretor.bhelp++;
		if(entrada[1]=='e')
			corretor.bhelp++;
		if(entrada[2]=='l')
			corretor.bhelp++;
		if(entrada[3]=='p')
			corretor.bhelp++;
		
		if(entrada[0]=='l')
			corretor.blimpar++;
		if(entrada[1]=='i')
			corretor.blimpar++;
		if(entrada[2]=='m')
			corretor.blimpar++;
		if(entrada[3]=='p')
			corretor.blimpar++;
		if(entrada[4]=='e')
			corretor.blimpar++;
		if(entrada[4]=='a')
			corretor.blimpar++;
		if(entrada[5]=='r')
			corretor.blimpar++;
		
		if(entrada[0]=='p')
			corretor.bpesquise++; corretor.bprocure++;
		if(entrada[1]=='e')
			corretor.bpesquise++;
		if(entrada[2]=='s')
			corretor.bpesquise++;
		if(entrada[3]=='q')
			corretor.bpesquise++;
		if(entrada[4]=='u')
			corretor.bpesquise++;
		if(entrada[5]=='i')
			corretor.bpesquise++;
		if(entrada[6]=='s')
			corretor.bpesquise++;
		if(entrada[7]=='e')
			corretor.bpesquise++;
		if(entrada[8]=='a')
			corretor.bpesquise++;
		if(entrada[9]=='r')
			corretor.bpesquise++;
		if(entrada[1]=='r')
			corretor.bprocure++;
		if(entrada[2]=='o')
			corretor.bprocure++;
		if(entrada[3]=='c')
			corretor.bprocure++;
		if(entrada[4]=='u')
			corretor.bprocure++;
		if(entrada[5]=='r')
			corretor.bprocure++;
		if(entrada[6]=='e')
			corretor.bprocure++;
		if(entrada[6]=='a')
			corretor.bprocure++;
		if(entrada[7]=='r')
			corretor.bprocure++;
		
		if(entrada[0]=='r')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[1]=='e')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[2]=='i')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[3]=='n')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada [4]=='i')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[5]=='c')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[6]=='i')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[7]=='a')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[8]=='r')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[9]==' ')
			corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[10]=='e')
			corretor.breiniciarem++;
		if(entrada[11]=='m')
			corretor.breiniciarem++;
		if(entrada[10]=='a')
			corretor.breiniciaras++;
		if(entrada[11]=='s')
			corretor.breiniciaras++;
		if(entrada[7]=='e')
			corretor.breiniciar++; corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[8]==' ')
			corretor.breiniciaras++; corretor.breiniciarem++;
		if(entrada[9]=='e')
			corretor.breiniciarem++;
		if(entrada[10]=='m')
			corretor.breiniciarem++;
		if(entrada[9]=='a')
			corretor.breiniciaras++;
		if(entrada[10]=='s')
			corretor.breiniciaras++;
			
	
	testereal(corretor);
}

int main(void)
{
	textcolor(LIGHTCYAN);
	setlocale(LC_ALL,"Portuguese");
	int x=0;
	
	system("title J.A.R.V.I.S.");
	while(x>-9999999999999)
	{
		gets(entrada);
		strlwr(entrada);
		if(strcmp(entrada,"jarvis"))
			printf("");
		else
		{
			system("cls");
			printf("*Olá, usuário*\n\n");
			do
			{
				gets(entrada);
				printf("*Em execução...*");
				strlwr(entrada);
				teste();
				printf("\r                      \n");
			}while(strcmp(entrada,"pare") && strcmp(entrada,"parar"));
			system("cls");
			printf("*J.A.R.V.I.S Encerrado*\n\n");
		}
	}
	return 0;
}
