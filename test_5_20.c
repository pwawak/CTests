#include  <stdio.h>

int	main( void )
{
	int 	arr[100];
	int		i, j, num = 1;

	for( i=0; i<100; i++ )
		arr[i] = 0;

	printf( "Podaj liczby: " );

	for( i=0; i<100 && num != 0; i++ ) {
		if ( 0 == scanf( "%d", &num ) ) {
            printf( "Incorrect input" );
            return 1;
		}

		if( num != 0 )
			arr[ i ] = num;
	}

	if( i == 1 ) {
        printf( "not enough data available" );
        return 2;
    }

    j = i - 1;
    if( j%2 != 0)
        --j;

	for( ; j >= 0; j-=2 )
        printf( "%d ", arr[j] );

	return 0;
}
