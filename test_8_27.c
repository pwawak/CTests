//
// Created by Piotr on 16-Dec-18.
//

/*
 * Napisz funkcje, pozwalające na kopiowanie elementów z jednego wektora do drugiego (copy),
 * odwracanie kolejności elementów w wektorze (reverse) oraz porównywanie dwóch wektorów (equal).
 * Funkcja copy ma przyjmować tablicę, do której ma kopiować elementy, rozmiar tablicy, tablicę z której mają być
 * skopiowane elementy i liczbę elementów do skopiowania, w przypadku kiedy niemożliwe będzie skopiowanie
 * wszystkich elementów, funkcja powinna skopiować tyle, ile jest możliwe. Funkcja zwraca liczbę elementów,
 * które udało się skopiować lub -1 w przypadku podania błędnych danych. Funkcja equal ma zwrócić 1
 * jeżeli ciągi są identyczne lub 0 kiedy nie są, lub -1 w przypadku podania błędnych danych.
 * Funkcje powinny mieć następujące prototypy:
 * 		int equal(const int first[], int size, const int second[], int size2);
 *		int copy(int dest[], int size, const int src[], int size2);
 *		void reverse(int first[], int size);
 * Napisz program, który pobierze od użytkownika ciąg liczb (nie więcej niż 100 elementów) i sprawdzi,
 * wykorzystując powyższe funkcje, czy ciąg ten jest palindromem. Pojawienie się wartości -1 na wejściu
 * będzie oznaczało zakończenie ciągu. Program ma wypisać “TAK”, jeżeli podany ciąg jest palindromem lub “NIE”
 * w przeciwnym przypadku. w przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić
 * komunikat Incorrect input i niezwłocznie zakończyć działanie z kodem błędu 1.
 * W przypadku podania zbyt małej liczby danych program powinien wyświetlić komunikat not enough data available
 * i zakończyć działanie z kodem błędu 2.
 *
 */

#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

int read_vector( int vec[], int size, int stop_value ) {
	char 	str[1001], *sptr, *token;
	char    delim[3] = " \n";
	int 	inx = 0;

	printf( "Podaj wektor: " );

	if( NULL == fgets( str, 1000, stdin ) || strlen( str ) != strspn( str, "0123456789- \n") ) {
		printf( "incorrect input" );
		return -2;
	}

	token = strtok( str, delim );

	while( token != NULL ) {
		if( inx == size )
			return -1;
		vec[inx++] = strtol( token, NULL, 10 );
		token = strtok( NULL, delim );
	}

	if( inx > 0 && vec[ inx - 1 ] != stop_value )
		return -1;

	return inx;
}

// -------------------------------------------------------------------------------------

void display_vector(const int vec[], int size) {
	for( int i = 0; i < size; i++ )
		printf( "%d%s", vec[ i ], ( i == size - 1 ) ? "\n" : " " );
}

// -------------------------------------------------------------------------------------

int equal(const int first[], int size, const int second[], int size2){
	if ( size != size2 )
		return 0;

	for ( int i = 0; i < size; ++i ) {
		if ( first[ i ] != second[ i ] )
			return 0;
	}

	return 1;
}

// -------------------------------------------------------------------------------------

int copy(int dest[], int size, const int src[], int size2) {
	int i;

	for( i = 0; i < size; i++ )
		dest[ i ] = src[ i ];

	return i;
}

// -------------------------------------------------------------------------------------

void reverse(int first[], int size) {
	for (int i = 0; i < size/2; ++i) {
		int tmp = first[ i ];
		first[ i ] = first[ size - i - 1];
		first[ size - i - 1] = tmp;
	}
}

// -------------------------------------------------------------------------------------

int main() {
	int vec1[10], vec2[10], size = 0, retVal;

	if (-1 == (size = read_vector(vec1, sizeof(vec1) / sizeof(int), -1 )))
		return 1;

	if ( size == 0 ) {
		printf( "not enough data available\n" );
		return 2;
	}

	--size;											// usuwamy stop_value.

	copy( vec2, size, vec1, size );
	reverse(vec2, size );

	retVal = equal( vec1, size, vec2, size );

	switch ( retVal ) {
		case -1:
			printf( "Incorrect input\n" );
			break;
		case 0:
			printf( "NIE\n" );
			break;
		case 1:
			printf( "TAK\n" );
			break;
	}

	display_vector( vec1, size );
	display_vector( vec2, size );

	return 0;
}