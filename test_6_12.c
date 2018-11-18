#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

int	main( void )
{
	char 	str[101], *strPtr, *endPtr;
	long    sum = 0;

	printf( "Podaj tekst:\n" );
	scanf( "%s", str );

	if( strlen( str ) != strspn( str, "0123456789+-") ) {
        printf( "Incorrect input" );
        return 1;
	}

    strPtr = str;

	do {
        sum += strtol( strPtr, &endPtr, 10);
        strPtr = endPtr;

	} while( *strPtr );

	printf( "%d", sum );

	return 0;
}
