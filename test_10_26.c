//
// Created by Piotr on 08-Jan-19.
//

/*
 * Napisz funkcję, która w sposób rekurencyjny, wypisze wszystkie N - cyfrowe liczby binarne,
 * których suma wartości cyfr w pierwszej połowie jest równa sumie wartości cyfr w drugiej połowie.
 * Funkcja powinna przyjąć tablicę tymczasową do przechowywania aktualnych wartości bitów w liczbie,
 * różnicę w sumie wartości cyfr w obu połówkach oraz indeks pierwszego niezapisanego bitu, długość liczby.
 * Dodatkowo funkcja powinna zwrócić liczbę wygenerowanych liczb. W przypadku podania błędnych danych
 * funkcja powinna zwrócić -1.
 * Prototyp funkcji powinien wyglądać następująco:
 * 		- int print_binary_number(char arr[], int diff, int start, int N)
 * Napisz program, który pobierze od użytkownika liczbę cyfr, z których ma się składać liczba binarna.
 * Na koniec program ma wyświetlić liczbę wygenerowanych liczb binarnych oraz liczbę wypisanych liczb.
 * W przypadku podania przez użytkownika niepoprawnej liczby cyfr, program powinien wyświetlić
 * komunikat Incorrect input data i zwrócić wartość 2, a w przypadku wprowadzenia błędnych danych
 * wyświetlić komunikat Incorrect input i niezwłocznie zakończyć działanie z kodem błędu 1.
 * Uwaga W programie nie wolno używać zmiennych globalnych.
 * Uwaga W programie nie wolno używać słowa kluczowego static.
 * Uwaga W programie nie wolno używać pętli.
 */

#include <stdio.h>
#include <ctype.h>
#include <mem.h>

int print_binary_number(char arr[], int diff, int start, int N) {
	int	retVal = 0;

	if( start >= N )
		if( diff == 0 ) {
			printf( "%s\n", arr );
			return 1;
		}
		else
			return 0;

	arr[ start ] = '0';
	retVal += print_binary_number( arr, diff, start+1, N );
	arr[ start ] = '1';
	if( start >= N/2 )
		++diff;
	else
		--diff;
	retVal += print_binary_number( arr, diff, start+1, N );

	return retVal;
}

// -------------------------------------------------------------------------------------

int main() {
	char 	x[100];
	int 	n = 0;
	int		retVal;

	printf( "Podaj liczbe cyfr: " );
	if( 0 == scanf( "%d", &n ) ) {
		printf( "Incorrect input\n" );
		return 1;
	}

	if( 0 != n%2 || n >= 100 ) {
		printf( "Incorrect input data\n" );
		return 2;
	}

	memset( x, '0', sizeof( x ) / sizeof( char ) );

	x[ n ] = '\0';

	retVal = print_binary_number( x, 0, 0, n);

	printf( "%d\n", retVal );
}