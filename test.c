#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "/home/adduser/stud_roma/RGR2/funcchisla.h"


static void test_is_leap_year(void **state) {
    (void)state; 

    assert_true(is_leap_year(2020));
    assert_true(is_leap_year(2000));

    assert_false(is_leap_year(2021));
    assert_false(is_leap_year(1900));
}

static void test_is_special_date(void **state) {
    (void)state;
    
    assert_true(is_special_date(28, 1, 28));
    assert_false(is_special_date(1, 1, 2023));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_is_leap_year),
        cmocka_unit_test(test_is_special_date),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}