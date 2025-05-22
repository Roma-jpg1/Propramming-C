#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

// отсорт
static int is_sorted(long long int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) return 0;
    }
    return 1;
}

// с.сорт1
static void test_SelectSort_basic(void **state) {
    long long int arr[] = {3, 1, 4, 2, 5};
    int ops = SelectSort(arr, 5);
    
    assert_true(is_sorted(arr, 5));
    assert_true(ops > 0);
}

// с.сорт2
static void test_SelectSort2_basic(void **state) {
    long long int arr[] = {5, 4, 3, 2, 1};
    int ops = SelectSort2(arr, 5);
    
    assert_true(is_sorted(arr, 5));
    assert_true(ops > 0);
}

// 3. Сравнение двух алгоритмов на одном массиве
static void test_compare_sorts(void **state) {
    
    long long int arr1[] = {7, 3, 9, 2, 5};
    long long int arr2[] = {7, 3, 9, 2, 5};
    
    int ops1 = SelectSort(arr1, 5);
    int ops2 = 100;
    
    assert_true(is_sorted(arr1, 5));
    assert_true(is_sorted(arr2, 5));
    assert_true(ops2 <= ops1); 
}

// 4. Тест на уже отсортированном массиве
static void test_sorted_input(void **state) {
    long long int arr[] = {1, 2, 3, 4, 5};
    int ops = SelectSort2(arr, 5);
    
    assert_true(is_sorted(arr, 5));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_SelectSort_basic),
        cmocka_unit_test(test_SelectSort2_basic),
        cmocka_unit_test(test_compare_sorts),
        cmocka_unit_test(test_sorted_input),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}