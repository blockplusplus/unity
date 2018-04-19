#include "unity.h"


void test_failed() {
    TEST_ASSERT_EQUAL_HEX8(0, 0);
    TEST_ASSERT_EQUAL_HEX8(0, 1);
}

void test_pass() {
    TEST_ASSERT_EQUAL_HEX8(0, 0);
}

int main() {

    UNITY_BEGIN();

    RUN_TEST(test_failed);
    RUN_TEST(test_pass);

    UNITY_END();

    return 0;
}