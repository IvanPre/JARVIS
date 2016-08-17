#include <stdio.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(char *str1, char *str2, int len1, int len2) 
{
	int min = len1 > len2 ? len2 : len1 ;
	int max = len1 > len2 ? len1 : len2 ;

	if (min == 0) {
		return max ;
	} else {
		int val[3] ;
		val[0] = levenshtein(str1, str2, len1-1, len2) + 1 ;
		val[1] = levenshtein(str1, str2, len1, len2-1) + 1 ;
		int indcatorFunc = str1[len1-1] == str2[len2-1] ? 0 : 1 ;
		val[2] = levenshtein(str1, str2, len1-1, len2-1) + indcatorFunc ;
		return MIN3(val[0], val[1], val[2]) ;
	}
}		
