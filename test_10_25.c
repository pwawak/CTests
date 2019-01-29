//
// Created by Piotr on 20-Jan-19.
//

/*
 * Napisz funkcję, która w sposób rekurencyjny, wypisze wszystkie N - elementowe kombinacje bez powtórzeń
 * z liczb z zakresu <start, end>. Funkcja powinna przyjąć tablicę tymczasową do przechowywania aktualnych
 * elementów z kombinacji oraz indeks, pod który nowy element powinien zostać dodany.
 * Dodatkowo funkcja powinna zwrócić liczbę wygenerowanych kombinacji. W przypadku podania błędnych danych
 * funkcja powinna zwrócić -1.
 * Prototyp funkcji powinien wyglądać następująco:
 *		int print_combination(int arr[], int start, int N, int start_number, int end_number);
 * Napisz program, który pobierze od użytkownika początek i koniec przedziału oraz liczbę elementów kombinacji,
 * a następnie wyświetli wszystkie N - elementowe kombinacje liczb z zadanego zakresu.
 * Na koniec program ma wyświetlić liczbę wygenerowanych kombinacji, maksymalnie dziesięcioelementowych.
 * W przypadku podania przez użytkownika liczby spoza wymaganego zakresu, program powinien wyświetlić
 * komunikat Incorrect input data i zwrócić wartość 2, a w przypadku wprowadzenia błędnych danych
 * wyświetlić komunikat Incorrect input i niezwłocznie zakończyć działanie z kodem błędu 1.
 * Uwaga W programie nie wolno używać zmiennych globalnych.
 * Uwaga W programie nie wolno używać słowa kluczowego static.
 * Uwaga W programie wolno użyć tylko jednej pętli, oprócz funkcji display_vector.
 */

#include <stdio.h>
#include <mem.h>

void display_vector(const int vec[], int size) {
	for( int i = 0; i < size; i++ )
		printf( "%d%s", vec[ i ], ( i == size - 1 ) ? "\n" : " " );
}

// -------------------------------------------------------------------------------------
// Algorytm rekurencyjny.
// Przy zadanych ograniczeniach problem z przekazaniem rozmiaru kombinacji. Rozwiązanie przez przekazanie w parametrze
// start - niezgodnie z intencjami zadania.

int print_combination(int arr[], int start, int N, int start_number, int end_number) {
	int cnt = 0;

	//printf( "    Called with N = %d, start = %d, start_num = %d, end_num = %d\n", N, start, start_number, end_number );

	if( start_number > end_number )
		return 0;

	if( N == 0 ) {
		display_vector( arr, start );
		return 1;
	}
	if( N == ( end_number - start_number + 1 ) ) {
		for (int i = 0, j = start_number; i < N; i++, j++ ) {
			arr[ i ] = j;
		}
		display_vector( arr, start );
		return 1;
	}
	cnt =  print_combination( arr, start, N,     start_number, end_number - 1);
	arr[ N - 1 ] = end_number;
	cnt += print_combination( arr, start, N - 1, start_number, end_number - 1);

	return cnt;
}

// -------------------------------------------------------------------------------------
// Algorytm bez rekurencji

int print_combination2(int arr[], int start, int N, int start_number, int end_number) {
	int	cnt = 0;

	for (int i = 0, j = start_number; i < N; ++i, ++j ) {
		arr[ i ] = j;
	}

	int p = N;

	while ( p >= 0 ) {
		display_vector( arr, N );
		++cnt;
		if ( arr[ N - 1 ] == end_number )
			p--;
		else
			p = N - 1;

		if ( p >= 0 )
			for ( int i = N - 1; i >= p ; --i ) {
				arr[ i ] = arr[ p ] + i - p + 1;
			}
	}

	return cnt;
}

// -------------------------------------------------------------------------------------
// Algorytm taki jak nr 2, ale z rekurencją.
// Przy zadanych ograniczeniach problem z ilością pętli (nie więcej niż jedna).
// Nieeleganckie wyjście z parametrem start == -2 żeby wychwycić pierwszy przebieg algorytmu.

int print_combination3(int arr[], int start, int N, int start_number, int end_number) {
	int	cnt = 0;

	if ( start == -2 ) {	// pierwsze wywołanie, ale nadmiarowa pętla
		for (int i = 0, j = start_number; i < N; ++i, ++j)
			arr[i] = j;

		start = 0;
	}

	if( start >= 0 ) {
		display_vector(arr, N);

		if( arr[ N - 1 ] == end_number )
			start--;
		else
			start = N - 1;

		if( start >= 0 )
			for( int i = N - 1; i >= start; --i ) {
				arr[ i ] = arr[ start ] + i - start + 1;
			}
		cnt = 1 + print_combination3(arr, start, N, start_number, end_number);
	}

	return cnt;
}

// -------------------------------------------------------------------------------------
// Algorytm taki jak nr 3, czyli z rekurencją i z eliminacją nadmiarowej pętli.

int print_combination4(int arr[], int start, int N, int start_number, int end_number) {
	int first_run = ( arr[ 0 ] == arr[ N - 1 ] ) ? 1 : 0;        // pierwsze wywołanie
	int cnt = first_run ? -1 : 1;

	if( start >= 0 ) {
		if( !first_run ) {
			display_vector(arr, N);

			if( arr[ N - 1 ] == end_number )
				start--;
			else
				start = N - 1;
		}

		if( start >= 0 )
			for( int i = N - 1, j = start_number + N - 1; i >= start; --i, --j ) {
				arr[ i ] = first_run ? j : ( arr[ start ] + i - start + 1 );
			}
		cnt += print_combination4(arr, start, N, start_number, end_number);
	}

	return cnt;
}

// -------------------------------------------------------------------------------------

int main() {
	int x[100];
	int start_num = 1, end_num = 6, start_inx = 0, k = 4;

	memset( x, 0, sizeof( x ) / sizeof( int ) );

	int cnt = print_combination4( x, start_inx, k, start_num, end_num );

	printf( "%d\n", cnt );

	return 0;
}