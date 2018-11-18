#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>

int	main( void )
{
	char 	str[1001], *sptr, *token;
	char    *sub_str[501];
	int     subStrCnt = 0;

	printf( "Podaj tekst:\n" );
	fgets( str, 1000, stdin );

	if( strlen( str ) != strspn( str, "0123456789-|\n") ) {
        printf( "Incorrect input" );
        return 1;
	}

    sptr = str;
    token = str;

	while( *sptr ) {    // podziel na podciagi i zapamietaj w tabeli
        if( *sptr == '|' ) {
            sub_str[ subStrCnt++ ] = token;
            *sptr = '\0';
            token = ++sptr;
        }
        else {
            ++sptr;
            if( *sptr == 0 ) {
                sub_str[ subStrCnt++ ] = token;
            }
        }
	}

    for( int i=0; i < subStrCnt; i++ ) {    // policz sume dla kazdego z podciagow
        long    sum = 0;
        //printf( "Rekord %d - %s\n", i, ( sub_str[ i ] != NULL ) ? sub_str[ i ] : "NULL" );
        token = strtok( sub_str[ i ], "-\n" );
        while( token != NULL ) {
            sum += atol( token );
            token = strtok( NULL, "-\n" );
        }
        printf( "%ld ", sum );
    }

	return 0;
}
