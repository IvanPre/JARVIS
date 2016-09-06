#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.h"

#define command_file_name "Comandos.txt"
#define buffer_size 1024

//Estrutura para armazenar os comandos carregados do arquivo
typedef struct Command_node {
	char *command ;
	struct Command_node *next ;
} command_node ;

//Define uma lista para armazenar todos os comandos do arquivo
typedef struct Command_list {
	command_node *first ;
	int count ;
} command_list ;

//Utilizado para verificar qual é o comando mais próximo
//da entrada
typedef struct Dist_node {
	int distance ;
	char *command ;
} dist_node ; 

//Vetor com todos os comandos
dist_node *dist_vector = NULL ;

//Inicializa a lista de comandos
void init_command_list(command_list *l) {
	l->first = NULL ;
	l->count = 0 ;
}

void chop(char *str) {
	while (*str) {
		if (*str == '\n') {
			*str = '\0' ;
			return ;
		}
		str++ ;
	}
}

//Adiciona um comando na lista
void add_command(command_list *l, char *command) {

	chop(command) ;
	if (command[0] == '\0') {
		return ;
	}

	command_node *new_node = (command_node *) malloc(sizeof(command_node)) ;
	new_node->command = (char *) malloc(sizeof(char)*(strlen(command) + 1)) ;
	strcpy(new_node->command, command) ;
	new_node->next = l->first ;
	l->first = new_node ;
	l->count++ ;
}

/*
	Nome: load_commands
	Função: Carrega todos os comandos do arquivo de comando na
			lista que é passada por parâmetro

	Parâmetros: Lista de comandos (inicializada ou não)
	Retorno: 0 - Sucesso
			 -1 - Não foi possível ler o arquivo
*/
int load_commands(command_list *l) {

	//Tenta abrir o arquivo de comandos em modo de leitura
	FILE * command_file = fopen(command_file_name, "r") ;
	if (!command_file) {
		//Se não conseguir, retorna -1
		return -1 ;
	}

	//Se conseguiu abrir o arquivo, inicializa a lista de comandos
	init_command_list(l) ;


	 
	char brokeCommand = 0 ; //Broke command é 1 se na leitura ao arquivo o comando veio quebrado (só uma parte dele)
	char delim[2] = "|" ; //Define o caracter que delimita os comandos no arquivo
	char buffer[buffer_size] ; //String em que será armazenado os dados lidos do arquivo


	while (!feof(command_file)) {
		//Garante que há um \0 no final do buffer
		buffer[buffer_size - 1] = '\0' ;

		//Se ainda há dados não lidos no arquivo, lê
		if (fgets(buffer, buffer_size - 1, command_file) == NULL) {
			//Se a leitura não retornou nada, volta no começo do while
			//para verificar se o arquivo já acabou
			continue ;
		}


		//Se a leitura foi feita com sucesso, recupera cada substring
		//delmitada com "delim" no buffer
		char *token = strtok(buffer, delim) ;
		while (token != NULL) {
			//Enquanto há delimitadores no buffer
			if (brokeCommand == 1) {
				//Se o ultimo comando veio quebrado, concatena a primeira string do novo buffer nele
				l->first->command = (char *) realloc(l->first->command, sizeof(char) * (strlen(l->first->command)+strlen(token)+1)) ;
				strcat(l->first->command, token) ;
				brokeCommand = 0 ;
			} else {
				//Se não, adiciona mais um comando normalmente à lista
				add_command(l, token) ;
			}

			//Vai para o próximo comando no buffer
			token = strtok(NULL, delim) ;
		}

		//Se a última posição do buffer não é um delimitador,
		//quer dizer que o último comando veio quebrado
		if (buffer[buffer_size - 1] != '|') {
			brokeCommand = 1 ;
		} else {
			brokeCommand = 0 ;
		}
	}

	fclose(command_file) ;
}


//Função que imprime todos os comandos lidos
void print_cmd_list(command_list *l) {
	command_node *node = l->first ;

	while (node) {
		printf("->%s\n", node->command) ;
		node = node->next ;
	}
}


//Carrega o vetor "dist_vector" com todos os comandos da lista
dist_node *init_dist_vector(command_list *l) {

	if (load_commands(l) != 0) {
		return NULL ;
	}
	
	dist_node *dist_vector = (dist_node *) malloc(sizeof(dist_node)*l->count) ;
	command_node *node = l->first ;

	int i ; 
	for (i = 0; i < l->count; i++) {
		dist_vector[i].distance = 0 ;
		int length = strlen(node->command) ;
		dist_vector[i].command = (char *) malloc(sizeof(char) * (length + 1)) ;
		strcpy(dist_vector[i].command, node->command) ;
		node = node->next ;
	}

	return dist_vector ;
}

//Faz a comparação de uma string com cada comando
//do vetor "dist_vector", salvando a distancia no vetor e
//retornando o index do comando mais proximo
int compare(char *str, dist_node *dist_vector, int count) {
	int length = strlen(str) ;

	int i , index = 0, min_dist;
	for (i = 0; i < count; i++) {
		dist_vector[i].distance = levenshtein(str, dist_vector[i].command, length, strlen(dist_vector[i].command)) ;
		if (i == 0) {
			min_dist = dist_vector[i].distance ;
		} else if (min_dist > dist_vector[i].distance) {
			min_dist = dist_vector[i].distance ;
			index = i ;
		}

		if (min_dist == 0) {
			break ;
		}
	}

	return index;
}

void print_dist_vector(int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("-%s\n", dist_vector[i].command) ;
	}
}

//Retorna o comando mais próximo da entrada
char *nearest_command(char *input) {
	command_list *l = (command_list *) malloc(sizeof(command_list)) ;

	if (dist_vector == NULL) {
		dist_vector = init_dist_vector(l) ;
	}

	int nearest_index = compare(input, dist_vector, l->count) ;

	return dist_vector[nearest_index].command ;

}


int main(void) {


	char input[100] ;
	scanf("%s", input) ;


	printf("%s\n", nearest_command(input)) ;

	return 0 ;
}

