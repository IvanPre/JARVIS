#include <string.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

//Verifica a dist�ncia entre duas strings e mostra quntas opera��es s�o necess�rias para transforar uma em outra
int difstr(char str1[], char str2[]) ;
