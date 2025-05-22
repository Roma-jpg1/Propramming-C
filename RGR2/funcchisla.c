#include "funcchisla.h"
#include <stdlib.h>

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool is_special_date(int day, int month, int year) {
    return (day * month) == (year % 100);
}

void process_years(int start_year, int end_year, FILE *file) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int *year_counts = calloc(end_year - start_year + 1, sizeof(int));
    if (!year_counts) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        return;
    }

    int total = 0;
    int max_year = 0;
    int max_count = 0;

    for (int year = start_year; year <= end_year; year++) {
        if (is_leap_year(year)){
            days_in_month[1]=29;
        }
        else{
            days_in_month[1]=28;
        }

        for (int month = 1; month <= 12; month++) {
            for (int day = 1; day <= days_in_month[month-1]; day++) {
                if (is_special_date(day, month, year)) {
                    fprintf(file, "%02d.%02d.%04d\n", day, month, year);
                    year_counts[year - start_year]++;
                    total++;
                }
            }
        }

        if (year_counts[year - start_year] > max_count) {
            max_count = year_counts[year - start_year];
            max_year = year;
        }
    }

    fprintf(file, "\nВсего замечательных дат: %d\n", total);
    fprintf(file, "Год с наибольшим количеством замечательных дат: %d (%d дат)\n", max_year, max_count);

    free(year_counts);
}