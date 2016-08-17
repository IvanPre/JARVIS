#include <TestaStr.c>

char* teste(char entrada[512])
{
	char comando[512];
	//Procura até onde o comando vai
	int x=0;
	for(x; entrada[x]!=' '; x++)
		comando[x]=entrada[x];
	comando[x]='\0';
	
	//Testa se existe um arquivo com esse nome e procura ua string igual neste arquivo, caso exista
	return testacomando("Comandos.txt", comando);
}
