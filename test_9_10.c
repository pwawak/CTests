//
// Created by Piotr on 26-Dec-18.
//
/*
 *
 * Napisz następujące funkcje do wykonywania operacji na tekstach:
 * •	find_longest_word - funkcja ma zwracać indeks początkowy najdłuższego wyrazu, znajdującego się w tablicy
 * 		tab. W przypadku, kiedy w tablicy nie będzie liter, funkcja ma zwrócić wartość -1.
 * •	get_word_length - funkcja licząca długość słowa, zaczynającego się od indeksu start.
 * 		int find_longest_word(const char tab[]);
 *		int get_word_length(const char tab[], int start);
 * Napisz program, który pobierze od użytkownika tekst, a następnie wykorzystując powyższe funkcje
 * oraz funkcje napisane w poprzednich zadaniach, wypisze wszystkie wyrazy, od najdłuższego do najkrótszego,
 * bez używania algorytmu sortowania. W komentarzu do zadania wyjaśnij swój wybór wykorzystanych funkcji.
 * W przypadku, kiedy nie będzie nic do wyświetlenie program powinien wyświetlić komunikat Nothing to show.
 * Uwaga: W programie nie można korzystać z bibliotek stdlib i string oraz z funkcji z rodziny scanf
 * (oprócz funkcji scanf).
 * Uwaga Wykorzystaj funkcję replace_string z zadania 9.9 Czas na zmiany (*zamiany).
*/

#include <stdio.h>
#include <ctype.h>


int get_word_length(const char tab[], int start) {
	int len = 0, inx = start;

	while ( tab[ inx ] && !isspace( tab[ inx ] ) ) {
		++inx;
		++len;
	}

	return len;
}

// -------------------------------------------------------------------------------------

int find_longest_word(const char tab[]) {
	int maxLen = 0, inxMax = -1, tabInx = 0;

	while ( tab[ tabInx ] ) {
		int len;

		while ( tab[ tabInx ] && isspace( tab[ tabInx ] ) )
			++tabInx;							// szukaj poczaątku słowa

		len = get_word_length( tab, tabInx );
		if ( len > maxLen ) {
			maxLen = len;
			inxMax = tabInx;
		}
		tabInx += len;
	}

	return inxMax;
}

// -------------------------------------------------------------------------------------

int main() {
	char	tab[1000];
	int		inx = 0;
	int 	emptyInput = 1;

	printf( "Podaj tekst: " );

	if( NULL == fgets( tab, sizeof( tab ) / sizeof( char ), stdin ) ) {
		printf( "incorrect input" );
		return -1;
	}

	while ( -1 != ( inx = find_longest_word( tab ) ) ) {
		int lx = get_word_length( tab, inx );

		emptyInput = 0;

		printf( "%.*s\n", lx, tab + inx );

		for ( int i = 0; i < lx; ++i ) {
			tab[ inx + i ] = ' ';
		}
	}

	if ( emptyInput )
		printf( "Nothing to show\n" );

	return 0;
}