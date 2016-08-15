#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <conio.c>
#include <locale.h>
#include <math.h>
#include <iostream>
#include <levenshtein.h>

void teste(char entrada[30])
{
	char comando[30];
	int spc=0;
	int x=0;
	//Procura até onde o comando vai
	for(x=0; entrada[x]!=' '; x++);
	//Coloca a posição da string em spc
	spc=x;
	//Isola o comando da string
	for(x=0; x<spc; x++)
		comando[x]=entrada[x];
	comando[x]='\0';
	
	
}
