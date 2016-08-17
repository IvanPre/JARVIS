#include <stdio.h>
#include <levenshtein.h>
#include <string.h>
#include <stdlib.h>

/*********************************************
Testa se uma string se encontra e um arquivo
**********************************************/
char* testacomando(char txt[512], char comando[512])
{
	FILE *file;
	if((file=fopen(txt,"r"))==NULL)
		printf("Arquivo não encontrado");
	else
	{
		char comandos[1024], *cmndteste = (char *) malloc (1024);
		int dif=99;
		int a=0;
		//Transfere um comando para "cmndteste"
		for(int b=0; comandos[a]!='|'; b++, a++)
		{
			cmndteste[b]=comandos[a];
			if((difstr(cmndteste,comando))<dif)
				dif=difstr(cmndteste,comando);
		}
		fclose(file);
		if(dif<2)
			return cmndteste;
		else
		{//pergunta se foi aquilo que quis dizer
			char perg[1024];
			strcpy(perg,cmndteste);
			strcat(perg, "? (s/n)*");
			printf("\n\n                *Você quis dizer ");
			puts(perg);
			char resp;
			scanf("%c",&resp);
			if(resp=='s')//retorna o comando
				return cmndteste;
			else
			{
				printf("*Ok*\n");
				return '\0';
			}
		}
	}
}
