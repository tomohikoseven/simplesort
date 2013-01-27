#include<CUnit/CUnit.h>
#include<CUnit/Console.h>

extern void _doSwap( int *ary, int i, int j );
extern void _swap( int *ary, int i, int j );
extern void searchMinAndSwap( int *ary, int i, int size );
extern void simpleSort( int *ary, int size );

void
test_doSwap01(void)
{
    int ary[2];

    // pre
    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 0;
    ary[1] = 1;

    _doSwap( ary, 0, 1 );
    CU_ASSERT_EQUAL( 1, ary[0] );
    CU_ASSERT_EQUAL( 0, ary[1] );
}

void
test_swap01(void)
{
    int _ary[2];

    memset( _ary, 0x00, sizeof( _ary ) );
    _ary[0] = 0;
    _ary[1] = 1;

    _swap( _ary, 0, 1 );

    CU_ASSERT_EQUAL( 0, _ary[0] );
    CU_ASSERT_EQUAL( 1, _ary[1] );

}

void
test_swap02(void)
{
    int _ary[2];

    memset( _ary, 0x00, sizeof( _ary ) );
    _ary[0] = 1;
    _ary[1] = 0;

    _swap( _ary, 0, 1 );

    CU_ASSERT_EQUAL( 0, _ary[0] );
    CU_ASSERT_EQUAL( 1, _ary[1] );

}

void
test_searchMinAndSwap01(void)
{
    int ary[3];

    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 10;
    ary[1] = 4;
    ary[2] = 5;

    searchMinAndSwap( ary, 0, sizeof(ary)/sizeof(ary[0]) );

    /* before:[10,4,5] */
    /* after:[4,10,5]*/
    CU_ASSERT_EQUAL( 4,     ary[0] );
    CU_ASSERT_EQUAL( 10,    ary[1] );
    CU_ASSERT_EQUAL( 5,     ary[2] );

}

void
test_searchMinAndSwap02(void)
{
    int ary[3];

    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 4;
    ary[1] = 10;
    ary[2] = 5;

    searchMinAndSwap( ary, 1, sizeof(ary)/sizeof(ary[0]) );

    /* before:[4,10,5] */
    /* after:[4,5,10]*/
    CU_ASSERT_EQUAL( 4,     ary[0] );
    CU_ASSERT_EQUAL( 5,     ary[1] );
    CU_ASSERT_EQUAL( 10,    ary[2] );

}

void
test_simpleSort01(void)
{
    int ary[1];

    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 10;

    simpleSort( ary, sizeof(ary)/sizeof(ary[0]) );

    /* before:[10] */
    /* after:[10]*/
    CU_ASSERT_EQUAL( 10,    ary[0] );

}
void
test_simpleSort02(void)
{
    int ary[3];

    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 10;
    ary[1] = 4;
    ary[2] = 5;

    simpleSort( ary, sizeof(ary)/sizeof(ary[0]) );

    /* before:[10,4,5] */
    /* after:[4,5,10]*/
    CU_ASSERT_EQUAL( 4,     ary[0] );
    CU_ASSERT_EQUAL( 5,     ary[1] );
    CU_ASSERT_EQUAL( 10,    ary[2] );

}

int
main(void)
{
    CU_pSuite   _testSuite;
    CU_pSuite   _testSuite_swap;
    CU_pSuite   _testSuite_searchMinAndSwap;
    CU_pSuite   _testSuite_simpleSort;

    CU_initialize_registry();

    // テストスイート
    _testSuite
                = CU_add_suite("test_doSwap", NULL, NULL);
    _testSuite_swap
                = CU_add_suite("test_swap", NULL, NULL);
    _testSuite_searchMinAndSwap
                = CU_add_suite("test_searchMinAndSwap", NULL, NULL);
    _testSuite_simpleSort
                = CU_add_suite("test_simpleSort", NULL, NULL);

    // テストケース
    CU_add_test(_testSuite, "test_doSwap01", test_doSwap01 );

    // テストケース
    CU_add_test(_testSuite_swap, "test_swap01", test_swap01 );
    CU_add_test(_testSuite_swap, "test_swap02", test_swap01 );

    // テストケース
    CU_add_test(_testSuite_searchMinAndSwap,
                    "test_searchMinAndSwap01",
                    test_searchMinAndSwap01 );
    CU_add_test(_testSuite_searchMinAndSwap,
                    "test_searchMinAndSwap02",
                    test_searchMinAndSwap02 );

    // テストケース
    CU_add_test(_testSuite_simpleSort,
                    "test_simpleSort01",
                    test_simpleSort01 );
    // テストケース
    CU_add_test(_testSuite_simpleSort,
                    "test_simpleSort02",
                    test_simpleSort02 );

    // テスト実行
    CU_console_run_tests();
    // テストレジストリ削除
    CU_cleanup_registry();

    return 0;
}
