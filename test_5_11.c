#include  <stdio.h>

int	main( void )
{
	char 	arr[11];
	int		num = 0;

	for( int i=0; i<=10; i++ )
		arr[i] = 0;

	printf( "Podaj liczby: " );

	do {
		if ( 0 == scanf( "%d", &num ) ) {
            printf( "Incorrect input" );
            return 1;
		}

		if( num >= 0 && num <= 10 )
			++arr[ num ];

	} while ( num != -1 );

	for( int i=0; i<=10; i++ )
		printf( "%d - %d\n", i, arr[i] );

	return 0;
}
