//
// Created by Piotr on 15-Dec-18.
//

/*
 * Napisz 3 funkcje do scalania dwóch wektorów liczb:
 * 	•	dołączającą pierwszy wektor na początku drugiego (concat_begin),
 * 	•	dołączającej pierwszy wektor na koniec drugiego (concat_end),
 * 	•	łączącej na zmianę elementy obu wektorów, rozpoczynając od pierwszego elementu pierwszego wektora
 * 		(concat_zip) zasadą "na zamek"
 * Wszystkie funkcje mają przyjmować następujące parametry: pierwszy wektor, rozmiar pierwszego wektora,
 * drugi wektor, rozmiar drugiego wektora, wektor wyjściowy, maksymalny rozmiar (pojemność) wektora wyjściowego.
 * Wszystkie funkcje mają zwrócić liczbę elementów w wektorze wyjściowym, a w przypadku kiedy nie będzie wystarczająco
 * dużo miejsca w wektorze wyjściowym, funkcje mają zwrócić wartość -2, a w przypadku podania błędnych danych
 * wartość -1. Dodatkowo przygotuj dwie funkcje pozwalające wczytać (read_vector) i wyświetlić (display_vector)
 * na konsoli poszczególne elementy wektorów. Funkcja wczytująca wektor od użytkownika, oprócz wektora i jego rozmiaru,
 * ma przyjąć wartość elementu, po którym powinno zakończyć się wczytywanie (stop_value).
 * Wartością zwracaną przez funkcję ma być liczba wczytanych elementów, w przypadku przekazania do funkcji
 * błędnych danych, funkcja powinna zwrócić wartość -1, a w przypadku wprowadzenia przez użytkownika
 * wartości innych niż liczbowe, funkcja powinna zwrócić wartość -2.
 *
 * Prototypy funkcji powinny wyglądać następująco:
 * 	int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3);
 * 	int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3);
 * 	int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3);
 * 	int read_vector(int vec[], int size, int stop_value);
 * 	void display_vector(const int vec[], int size);
 *
 * Napisz program, który pobierze od użytkownika dwa ciągi liczbowe (nie więcej niż 50 elementów w każdym) i wyświetli
 * po kolei:
 * 	•	pierwszy pobrany wektor,
 * 	•	drugi pobrany wektor,
 * 	•	wektor, będący wynikiem zastosowania funkcji begin,
 * 	•	wektor, będący wynikiem zastosowania funkcji end,
 * 	•	wektor, będący wynikiem zastosowania funkcji zip.
 * Przyjmij rozmiar maksymalny wszystkich wektorów równy 50 elementów oraz 0 za wartość mającą zakończyć wczytywanie
 * liczb danego wektora (stop_value). W przypadku, kiedy niemożliwe będzie scalenie wektorów program powinien wyświetlić
 * oba wczytane wektory oraz komunikat Output buffer is too small.
 * w przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić komunikat Incorrect input
 * i niezwłocznie zakończyć działanie z kodem błędu 1. W przypadku podania zbyt małej liczby danych program powinien
 * wyświetlić komunikat not enough data available i zakończyć działanie z kodem błędu 2.
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

	if( vec[ inx - 1 ] != stop_value )
		return -1;

	return inx;
}

// -------------------------------------------------------------------------------------

void display_vector(const int vec[], int size) {
	for( int i = 0; i < size; i++ )
		printf( "%d%s", vec[ i ], ( i == size - 1 ) ? "\n" : " " );
}

// -------------------------------------------------------------------------------------

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3) {
	int inx = 0, j = 0;

	if( size3 < ( size + size2 - 2 ) ) {				// odejmuje 2 z uwagi na dwa znaki stop_value
		return -1;
	}

	for( inx = 0; inx < size - 1; inx++ )			// pomijam stop_value
		dest[ inx ] = first[ inx ];

	for( j = 0; j < size2 - 1; j++ )
		dest[ j + inx ] = second[ j ];

	return j + inx;
}

// -------------------------------------------------------------------------------------

int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3) {
	int inx = 0, j = 0;

	if( size3 < ( size + size2 - 2 ) ) {				// odejmuje 1 z uwagi na dwa znaki stop_value
		return -1;
	}

	for( inx = 0; inx < size2 - 1; inx++ )			// pomijam stop_value
		dest[ inx ] = second[ inx ];

	for( j = 0; j < size - 1; j++ )
		dest[ j + inx ] = first[ j ];

	return j + inx;
}

// -------------------------------------------------------------------------------------

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
	int stop_cnt = 0, inx0 = 0, inx1 = 0, inx2 = 0;

	if( size3 < ( size + size2 - 2 ) ) {				// odejmuje 1 z uwagi na dwa znaki stop_value
		return -1;
	}

	while( inx1 < size - 1 || inx2 < size2 - 1 ) {
		if ( inx1 < size - 1 )
			dest[ inx0++ ] = first[ inx1++ ];
		if ( inx2 < size2 - 1 )
			dest[ inx0++ ] = second[ inx2++ ];
	}

	return inx0;
}

// -------------------------------------------------------------------------------------

int main() {
	int vec1[4], vec2[ 4 ], vec_dest[ 8 ], size = 0, size2 = 0, size3 = 0;

	if( -1 == ( size  = read_vector( vec1, sizeof( vec1 ) / sizeof( int ), 0 ) ) )
		return 1;
	if( -1 == ( size2 = read_vector( vec2, sizeof( vec2 ) / sizeof( int ), 0 ) ) )
		return 1;

	size3 = concat_begin( vec1, size, vec2, size2, vec_dest, sizeof( vec_dest ) / sizeof( int ) );

	if( -1 == size3 ) {
		printf( "output buffer too small\n" );
		display_vector( vec1, size );
		display_vector( vec2, size2 );

		return 1;
	}

	display_vector( vec_dest, size3 );

	size3 = concat_end( vec1, size, vec2, size2, vec_dest, sizeof( vec_dest ) / sizeof( int ) );

	display_vector( vec_dest, size3 );

	size3 = concat_zip( vec1, size, vec2, size2, vec_dest, sizeof( vec_dest ) / sizeof( int ) );

	display_vector( vec_dest, size3 );

	return 0;
}