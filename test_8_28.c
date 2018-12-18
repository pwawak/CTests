//
// Created by Piotr on 14-Dec-18.
//

/*
 * Napisz funkcje do wykonywania operacji na wektorach:
 *	•	unique - usuwa wszystkie oprócz pierwszego elementy z każdej kolejnej grupy sąsiadujących ze sobą elementów
 *			o tej samej wartości i zwraca długość nowego wektora, a w przypadku podania błędnych danych zwraca wartość -1,
 *	•	adjacent_find - zwraca indeks pierwszej pary sąsiadujących ze sobą elementów o równej wartości.
 *			W przypadku kiedy takie elementy nie wystąpią we wczytanym ciągu, funkcja powinna zwrócić -2,
 *			a w przypadku podania błędnych danych -1,
 *	•	mismatch - funkcja przyjmuje dwa wektory, i zwraca pierwszy numer indeksu, w którym wartości z tablicy
 *			first i second były różne. Dodatkowo do tablicy out zapisane mają zostać wartości tych dwóch elementów
 *			(w komórce 0 wartość z tablicy first, w komórce 1 z tablicy second).
 *			Jeżeli ciągi są takie same funkcja ma zwrócić liczbę spradzonych elementów, a tablicę out wypełnić zerami,
 *			a w przypadku podania błędnych danych -1.
 *
 * int unique(int first[], int size);
 * int adjacent_find(const int first[], int size);
 * int mismatch(const int first[], int size, const int second[], int size2, int out[2]);
 *
 * Napisz program, który pobierze od użytkownika ciągi liczb (nie więcej niż 150 elementów, zakończony 0) i wyświetli
 * po kolei:
 *	•	wektor v1, będący wynikiem zastosowania funkcji unique na wektorze wejściowym,
 *	•	wynik zastosowania funkcji adjacent_find na wektorze wejściowym,
 *	•	wynik zastosowania funkcji mismatch dla wektora v1 i wektora wejściowego.
 *			W przypadku, kiedy wartość zwrócona przez funkcję będzie różna od -1, program ma wypisać w tej samej linii, oddzielone spacjami wartości na jakich różniły się oba wektory.
 *	w przypadku wprowadzenia przez użytkownika błędnych danych program powinien wyświetlić komunikat
 *	Incorrect input i niezwłocznie zakończyć działanie z kodem błędu 1.
 *	W przypadku podania zbyt małej liczby danych program powinien wyświetlić komunikat not enough data available
 *	i zakończyć działanie z kodem błędu 2
 *
 */

#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

#define MAX_VEC	100

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

	if( inx > 0 && vec[ inx - 1 ] != stop_value ) {
		printf( "incorrect input" );
		return -1;
	}

	return inx;
}

// -------------------------------------------------------------------------------------

void display_vector(const int vec[], int size) {
	for( int i = 0; i < size; i++ )
		printf( "%d%s", vec[ i ], ( i == size - 1 ) ? "\n" : " " );
}

// -------------------------------------------------------------------------------------

int copy(int dest[], int size, const int src[], int size2) {
	int i;

	for( i = 0; i < size; i++ )
		dest[ i ] = src[ i ];

	return i;
}

// -------------------------------------------------------------------------------------

int unique(int first[], int size) {
	int vec2[ MAX_VEC ];
	int inx = 0;

	copy( vec2, size, first, size );

	for (int i = 0; i < size - 1; ++i) {
		if ( vec2[ i ] != vec2[ i + 1 ] )
			first[ inx++ ] = vec2[ i ];
	}

	return inx;
}

// -------------------------------------------------------------------------------------

int adjacent_find(const int first[], int size) {
	for (int i = 0; i < size -1; ++i) {
		if ( first [ i ] == first[ i + 1] )
			return i;
	}
	return -1;
}

// -------------------------------------------------------------------------------------

int mismatch(const int first[], int size, const int second[], int size2, int out[2]) {
	int limit, i;

	limit = __min(size, size2 );

	for ( i = 0; i < limit; ++i ) {
		if ( first [ i ] != second[ i ] ) {
			out[0] = first[i];
			out[1] = second[i];
			return i;
		}
	}

	out[ 0 ] = 0;
	out[ 1 ] = 0;

	return i;
}

// -------------------------------------------------------------------------------------

int main() {
	int vec1[MAX_VEC], vec2[ MAX_VEC ], out[ 2 ], size = 0, size2 = 0, retVal;

	if (-1 == (size = read_vector(vec1, sizeof(vec1) / sizeof(int), 0 )))
		return 1;

	if ( size == 0 ) {
		printf( "not enough data available\n" );
		return 2;
	}

	copy( vec2, size, vec1, size );

	size2 = unique( vec1, size );

	if ( -1 == size2 ) {
		printf( "Incorrect input\n" );
		return 1;
	}

	display_vector( vec1, size2 );

	retVal = adjacent_find( vec2, size );

	printf( "%d\n", retVal );

	retVal = mismatch( vec1, size2, vec2, size, out );

	if ( retVal != -1 ) {
		printf( "%d %d %d\n", retVal, out[ 0 ], out[ 1 ] );
	}

	return 0;
}
