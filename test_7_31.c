/*
 * test_7_31.c
 *
 *  Created on: Dec 4, 2018
 *      Author: Piotr
 *
 *      Napisz program, który wczyta od użytkownika macierz o wymiarze 10x10. Program ma odnaleźć we wczytanej macierzy
 *      3 elementowy wektor, o największej sumie jego elementów. Wektor może być pionowy lub poziomy. Na wyjściu ma się
 *      pojawić maksymalna suma 3 elementowego wektora, liczba odnalezionych wektorów o takiej sumie, a następnie mają się
 *      pojawić dla każdego wektora w osobnej linii: oznaczenie położenia wektora (1 - pionowo, 2 - poziomo)
 *      oraz po spacji indeksy pierwszej komórki (y x).
 *      W przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić komunikat incorrect input
 *      i zakończyć działanie z kodem błędu 1.
 *
 */

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

int	fill_table( int tab[][10], int size );

int	main() {

	int	tab[10][10];
	int	maxX= 0, maxY = 0, maxSum = 0, maxSumCnt = 0, maxVecDir = 0;
	int	retVal;

	retVal = fill_table( tab, 10 );

	if( retVal != 0 )
		return retVal;

	// wykonaj algorytm.

	for( int i = 1; i < 9; i++ )
		for( int j = 1; j < 9; j++ ) {
			int	sum = tab[i-1][j] + tab[i][j] + tab[i+1][j];
			if(  sum > maxSum ) {
				maxSum = sum;
				maxY = i-1;
				maxX = j;
				maxVecDir = 1;
				maxSumCnt = 1;
			}
			else if( sum == maxSum )
				++maxSumCnt;

			sum = tab[i][j-1] + tab[i][j] + tab[i][j+1];
			if(  sum > maxSum ) {
				maxSum = sum;
				maxY = i;
				maxX = j-1;
				maxVecDir = 2;
				maxSumCnt = 1;
			}
			else if( sum == maxSum )
				++maxSumCnt;
		}

	printf( "%d\n%d\n%d %d %d\n", maxSum, maxSumCnt, maxVecDir, maxY, maxX );
}

// ---------------------------------------------------------------

int	fill_table( int tab[][10], int size ) {
	// wczytaj tabele liczb.

	for( int i = 0; i < size; i++ ) {
		char	line[1024];
		char*	lptr;
		int		j, val;

		if( NULL == fgets( line, sizeof( line ) / sizeof( char ), stdin ) ) {
			printf( "Unexpected eof" );
			return 3;
		}

		lptr = strtok( line, " " );

		for( j = 0; j < size && lptr != NULL; j++ ) {
			if( strlen( lptr ) != strspn( lptr, "0123456789- \n") ) {
		        printf( "Incorrect input" );
		        return 1;
			}

			val = atoi( lptr );

			tab[ i ][ j ] = val;
			lptr = strtok( NULL, " " );
		}

		if( j != size ) {
	        printf( "Incorrect input" );
	        return 1;
		}

	}

	return 0;
}

