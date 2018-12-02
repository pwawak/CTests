/*
 * test_7_8.c
 *
 *  Created on: Dec 2, 2018
 *      Author: Piotr
 *      Napisz program, który wczyta od użytkownika tablicę o wymiarze 15x15, wypełnioną wartościami z zakresu <0, 30),
 *      a następnie utworzy tablicę wynikową, w której wartości z tablicy wejściowej zostaną zastąpione liczbą ich
 *      wystąpień. W przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić
 *      komunikat incorrect input i zakończyć działanie z kodem błędu 1,
 *      a w przypadku wprowadzenia liczby spoza zakresu komunikat value out of range i zwrócić wartość 2.
 */

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

int	fill_table( int** tab, int size );

int	main() {

	int	tab[15][15];
	int	vec[30];
	int	retVal;

	retVal = fill_table( (int**) tab, 15 );

	if( retVal != 0 )
		return retVal;

	// wykonaj algorytm.

	for( int i = 0; i < sizeof( vec ) / sizeof( int ); i++ )
		vec[ i ] = 0;

	for( int i = 0; i < 15; i++ )
		for( int j = 0; j < 15; j++ ) {
		vec[ tab[i][j] ]++;
		}

	for( int i = 0; i < 15; i++ )
			for( int j = 0; j < 15; j++ ) {
			tab[i][j] = vec[ tab[i][j] ];
			}

	return 0;
}

// ---------------------------------------------------------------

int	fill_table( int** tab, int size ) {
	// wczytaj tabele liczb.

	for( int i = 0; i < size; i++ ) {
		char	line[256];
		char*	lptr;
		int		j, val;

		fgets( line, sizeof( line ) / sizeof( char ), stdin );

		lptr = strtok( line, " " );

		for( j = 0; j < size && lptr != NULL; j++ ) {
			if( strlen( lptr ) != strspn( lptr, "0123456789 \n") ) {
		        printf( "Incorrect input" );
		        return 1;
			}

			val = atoi( lptr );

			if( val < 0 || val >= 30 ) {
			    printf( "value out of range" );
			    return 2;
			}

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
