/*
 * test_7_28.c
 *
 *  Created on: Dec 4, 2018
 *      Author: Piotr
 *      Napisz program, który wczyta od użytkownika macierz o wymiarze 10x10 i zastosuje na niej filtr uśredniający o rozmiarze 3x3.
 *      Oznacza to, że macierz wyjściowa będzie miała rozmiar 8x8. Wartość każdej komórki macierzy wyjściowej ma być wartością średnią
 *      z 9 elementów macierzy wejściowej.
 *      W przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić komunikat incorrect input
 *      i zakończyć działanie z kodem błędu 1.
 */

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

int	fill_table( int tab[][10], int size );

int	main() {

	int		tab[10][10];
	float	avg[8][8];
	int		retVal;

	retVal = fill_table( tab, 10 );

	if( retVal != 0 )
		return retVal;

	// wykonaj algorytm.

	for( int i = 1; i < 9; i++ )
		for( int j = 1; j < 9; j++ ) {
			avg[i-1][j-1] = ( tab[i-1][j-1] + tab[i-1][j] + tab[i-1][j+1] +
							  tab[i][j-1]   + tab[i][j]   + tab[i][j+1] +
							  tab[i+1][j-1] + tab[i+1][j] + tab[i+1][j+1] ) / 9.0;
		}

	for( int i = 0; i < 8; i++ )
			for( int j = 0; j < 8; j++ ) {
				printf( "%.2f%c", avg[i][j], ( j == 7 ) ? '\n' : ' ' );
			}
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



