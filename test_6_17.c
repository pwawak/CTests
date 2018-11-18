#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <ctype.h>

struct  Words {
    char    *wrd;
    int     freq;
};

int	main( void )
{
	char 	str[1001], *token;
	char    delim[3] = " \n";
    char    vowels[] = "aeioyu";
    struct  Words   w[501];
    int     wrdCnt = 0, maxFreq = 0;

	printf( "Podaj tekst:\n" );
	fgets( str, sizeof( str ) / sizeof( char ), stdin );

    token = strtok( str, delim );

	while( token != NULL ) {
        char    *sptr;
        int     vcnt = 0, sl, vfreq;

        sptr = token;
        while( *sptr ) {   // policz samogloski w wyrazie
            if( NULL != strchr( vowels, *sptr ) )
                vcnt++;
            else if ( isalpha( *sptr ) == 0 && *sptr != ' ' && *sptr != '\n' ) {
                printf( "Incorrect input\n" );
                return 1;
            }
            ++sptr;
        }

        sl = strlen(token);
        vfreq = vcnt * 100 / sl;    // stosunek samoglosek do spolglosek do 2 miejsc po przecinku.

        w[ wrdCnt ].wrd = token;
        w[ wrdCnt ].freq = vfreq;

        wrdCnt++;

        if( vfreq > maxFreq )
            maxFreq = vfreq;

        token = strtok( NULL, delim );
	}

	for( int i = wrdCnt - 1; i >= 0; i-- )
        if( w[ i ].freq == maxFreq )
            printf( "%s\n", w[ i ].wrd );

	return 0;
}
