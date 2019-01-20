//
// Created by Piotr on 18-Jan-19.
//

/*
 * Napisz funkcję, która w sposób rekurencyjny, sprawdzi czy jest możliwe dotarcie z punktu o współrzędnych (sx, sy)
 * do punktu o współrzędnych (dx, dy). Funkcja powinna zwrócić 1 w przypadku sukcesu lub 0 w przeciwnym przypadku.
 * W każdym kroku są dozwolone tylko dwa rodzaje ruchu, z punktu (x1, x2) można przejść do punktu:
 *		•	(x1 + x2, x2)
 *		•	(x1, x1 + x2).
 *
 * Prototyp funkcji powinien wyglądać następująco:
 *		int is_destination_reachable(int sx, int sy, int dx, int dy);
 *
 * Napisz program, który pobierze od użytkownika współrzędne punktu startowego (x, y - oddzielone spacjami)
 * oraz współrzędne punktu końcowego i sprawdzi czy możliwe jest dotarcie z punktu startu do punktu końcowego.
 * Program powinien wypisać YES jeżeli jest to możliwe, NO w przeciwnym przypadku.
 * W przypadku wprowadzenia błędnych danych program powinien wyświetlić komunikat Incorrect input
 * i niezwłocznie zakończyć działanie z kodem błędu 1.
 *
 * Uwaga: w programie nie wolno używać zmiennych globalnych.
 * Uwaga: w programie nie wolno używać słowa kluczowego static.
 * Uwaga: w programie nie wolno używać pętli.
 */

#include <stdio.h>

int is_destination_reachable(int sx, int sy, int dx, int dy) {
	int	retVal = 0;

	if( sx > dx || sy > dy )
		return 0;
	if( sx == dx && sy == dy )
		return 1;
	if( 1 == is_destination_reachable( sx + sy, sy, dx, dy ) || 1 == is_destination_reachable( sx, sx + sy, dx, dy ) )
		return 1;
	return 0;
}

// -------------------------------------------------------------------------------------

int main() {
	int	retVal;

	//retVal = is_destination_reachable( 9, 4, 9, 13 );
	retVal = is_destination_reachable( 2, 8, 5, 8 );


	switch( retVal ) {
		case 0:
			printf( "NO\n" );
			break;
		case 1:
			printf( "YES\n" );
			break;
	}
}