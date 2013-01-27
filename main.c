#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __DEBUG_UT
#define dbg_start(fmt, ...) printf("DEBUG : %s() start " fmt, __func__,  __VA_ARGS__ )
#define dbg_end(fmt, ...)   printf("DEBUG : %s() end " fmt, __func__, __VA_ARGS__ )
#else
#define dbg_start(fmt, ...)
#define dbg_end(fmt, ...)
#endif

void
_doSwap( int *ary, int i, int j )
{
    int _tmp = 0;

    _tmp    = ary[i];
    ary[i]  = ary[j];
    ary[j]  = _tmp;

    return ;
}

void
_swap( int *ary, int i, int j )
{
    if( ary[i] > ary[j] )
    {
        _doSwap( ary, i, j );
    }
}

void
searchMinAndSwap( int *ary, int i, int size )
{
    int j = 0;

    dbg_start("ary = %p, i = %d, size = %d\n", ary, i, size);

    for( j = i + 1; j < size; j++ )
    {
        _swap( ary, i, j );
    }

    dbg_end("ary = %p\n", ary);
}

void
simpleSort( int *ary, unsigned int size )
{
    int i = 0;

    for( i = 0; i < size - 1; i++ )
    {
        searchMinAndSwap( ary, i, size );
    }
}

void
aryPrint( int *ary, int size )
{
    int _i = 0;

    for( _i = 0; _i < size; _i++ )
    {
        printf( "%d ", ary[_i] );
    }
    printf("\n");

    return ;
}

void
cmvToInt( int size, const char **argv, int *ary )
{
    int _i = 0;

    for( _i = 0; _i < size; _i++ )
    {
        ary[_i] = atoi( argv[_i+1] );
    }

    return ;
}

int
#ifdef __DEBUG_UT
main_dummy( int argc, char **argv )
#else
main( int argc, char **argv )
#endif
{
    int *_ary            = NULL;
    //unsigned int _size   = 0;

    _ary = (int *)malloc( argc - 1 );
    if( NULL == _ary )
    {
        printf("malloc error\n");
        exit(EXIT_FAILURE);
    }
    memset( _ary, 0x00, argc - 1 );

    cmvToInt( argc - 1, ( const char ** )argv, _ary );

    simpleSort( _ary, argc - 1 );

    aryPrint( _ary, argc - 1 );

    return 0;
}
