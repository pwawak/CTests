#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

struct  Words {
    char    *wrd;
};

int	main( void )
{
	char 	str[1001], *token;
	char    delim[3] = " \n";
    char    *wlst[501];
    int     maxLen = 0, maxCnt = 0;

	printf( "Podaj tekst:\n" );
	fgets( str, sizeof( str ) / sizeof( char ), stdin );

    token = strtok( str, delim );

    while( token != NULL ) {
        int len = strlen( token );

        if( len > maxLen ) {
            maxLen = len;
            maxCnt = 0;
        }

        if( len == maxLen )
            wlst[ maxCnt++ ] = token;

        token = strtok( NULL, delim );
	}

	printf( "%d %d\n", maxCnt, maxLen );

	for( int i=maxCnt-1; i>=0; i-- )
        printf( "%s\n", wlst[i] );

	return 0;
}
