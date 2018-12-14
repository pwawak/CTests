/*
 * Napisz program sprawdzający tzw. hipotezę Goldbacha: każda liczba parzysta może zostać przedstawiona
 * jako suma dwóch liczb pierwszych. Hipotezę należy sprawdzić dla liczb z przedziału <x1, x2>.
 * Wyniki wyświetlaj w postaci analizowanej liczby oraz serii par liczb pierwszych w nawiasach
 *
 */

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include 	<math.h>

int is_prime( int n, int pMax ) {
	static	int *primes = NULL, arrMax = 0;

	if( n < 2 )
		return 0;

	if( arrMax != pMax ) {
		// Zmiana zakresu liczb pierwszych - inicjalizacja struktur
		if( primes != NULL )
			free( primes );

		arrMax = pMax;

		primes = malloc( arrMax * sizeof(int) );

		primes[ 0 ] = 0;		// To nie jest liczba pierwsza
		primes[ 1 ] = 0;
		for( int i = 2; i < arrMax; i++ ) {
			primes[ i ] = 1;
		}

		// Znajdz wszystkie liczby pierwsze w zakresie od 2 do arrMax
		// Sito Eratostenesa

		int lim = (int) ceil( sqrt( arrMax ) );

		for( int i = 2; i < lim; i++ ) {

			if( primes[ i ] == 0 )
				continue;

			for( int j = i * i; j < arrMax; j += i )
				primes[ j ] = 0;
		}
	}

	return ( primes[ n ] == 1 );
}

// -------------------------------------------------------------------------------------------------

int main() {
	int x1, x2;
	int retFlag = 0;

	printf( "Podaj x1: " );
	scanf( "%d", &x1 );
	printf( "\nPodaj x2: " );
	scanf( "%d", &x2 );

	if( x1 >= x2 ) {
		printf( "incorrect data\n" );
		return retFlag;
	}

	for( int i = x1; i < x2; i++ ) {
		if( ( i % 2 ) != 0 )
			continue;									// tylko dla liczb parzystych
		printf( "%d:", i );
		for( int j = 2; j < i; j++ ) {
			if( ! is_prime( j, x2 ) )
				continue;
			for (int k = 2; k < i; k++) {
				if (! is_prime( k, x2 ) )
					continue;
				if( i == (k + j ) ) {
					printf("( %d %d ) ", j, k );
					retFlag = 1;						// znaleziono co najmniej jedna pare
				}
			}
		}
		printf( "\n" );
	}

	return retFlag;
}

// -------------------------------------------------------------------------------------------------

void	test() {
	int x;

	x = 14;
	printf( "Liczba %d %s jest liczba pierwsza\n", x, ( 0 != is_prime( x, 20 ) ) ? "nie" : " " );

	x = 3;
	printf( "Liczba %d %s jest liczba pierwsza\n", x, ( 0 != is_prime( x, 20 ) ) ? "nie" : " " );

	x = 7;
	printf( "Liczba %d %s jest liczba pierwsza\n", x, ( 0 != is_prime( x, 20 ) ) ? "nie" : " " );

	x = 9;
	printf( "Liczba %d %s jest liczba pierwsza\n", x, ( 0 != is_prime( x, 20 ) ) ? "nie" : " " );
}