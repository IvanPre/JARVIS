#include "levenshtein.h"

//Verifica a distância entre duas strings e mostra quntas operações são necessárias para transforar uma em outra
int difstr(char str1[], char str2[])
{
	//x e y são variáveis auxiliares
	int x, y, s1len, s2len;
    //s1len é o tamanho da string inserida
	s1len = strlen(str1);
	//s2len é o tamanho da string comparada
    s2len = strlen(str2);
    
    int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)           //Zera a coluna 0
        matrix[x][0] = matrix[x-1][0] + 1;
        
    for (y = 1; y <= s1len; y++)           //Zera a linha 0
        matrix[0][y] = matrix[0][y-1] + 1;
        
    //Compara as duas strings e calcula a diferença entre elas
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
        	matrix[x][y] = (matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (str1[y-1] == str2[x-1] ? 0 : 1));
    
    return matrix[s1len][s2len];
}
