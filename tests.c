#include "unity.h"
#include "test_instructions.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_inst_sa_two);
    return UNITY_END();
}
