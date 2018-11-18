#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

int	main( void )
{
	char 	str[1001], *token;
	char    delim[3] = " \n";
    int     wcnt[1001];

    for( int i=0; i < sizeof( wcnt) / sizeof( int ); i++)
        wcnt[i] = 0;

	printf( "Podaj tekst:\n" );
	fgets( str, sizeof( str ) / sizeof( char ), stdin );

    token = strtok( str, delim );

	while( token != NULL ) {
        ++wcnt[ strlen( token ) ];
        token = strtok( NULL, delim );
	}

	for( int i=0; i < sizeof( wcnt) / sizeof( int ); i++)
        if( wcnt[i] != 0 )
            printf( "%d - %d\n", i, wcnt[i] );

	return 0;
}
