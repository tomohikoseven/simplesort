#include"noConstFib.h"

#include<CUnit/CUnit.h>
#include<CUnit/Console.h>

// fib(0)のテスト
void
testNoConstFib0(void)
{
    unsigned int _ret = 0;
    _ret = fib( 0 );

    CU_ASSERT_EQUAL( 1, _ret );
}

// fib(1)のテスト
void
testNoConstFib1(void)
{
    unsigned int _ret = 0;
    _ret = fib( 1 );

    CU_ASSERT_EQUAL( 1, _ret );
}

void
testNoConstFib2(void)
{
    unsigned int _ret = 0;
    _ret = fib( 2 );

    CU_ASSERT_EQUAL( 2, _ret );
}

void
testNoConstFib5(void)
{
    unsigned int _ret = 0;
    _ret = fib( 5 );

    CU_ASSERT_EQUAL( 8, _ret );
}

int
main(void)
{
    CU_pSuite _testSuite;
    // テストレジストリ作成
    CU_initialize_registry();
    // テストスイート追加
    _testSuite  = CU_add_suite("testNoConstFib", NULL, NULL);
    // テストケース追加
    CU_add_test(_testSuite, "testNoConstFib0", testNoConstFib0);
    CU_add_test(_testSuite, "testNoConstFib1", testNoConstFib1);
    CU_add_test(_testSuite, "testNoConstFib2", testNoConstFib2);
    CU_add_test(_testSuite, "testNoConstFib5", testNoConstFib5);
    // テスト実行
    CU_console_run_tests();
    // テストレジストリ削除
    CU_cleanup_registry();

    return 0;
}
