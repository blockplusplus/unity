#include "Unity.h"

void test_hello_world() {
    TEST_ASSERT(1 == 2);
    TEST_ASSERT_MESSAGE(3 == 1 + 2, "Error in Add api");
}

int main() {

    unity_test_start();
    RUN_TEST(test_hello_world);
    unity_test_end();
    return 0;
}