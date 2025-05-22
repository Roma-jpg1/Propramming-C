#include <stdbool.h>
#include <stdio.h>

bool is_special_date(int day, int month, int year);

void process_years(int start_year, int end_year, FILE *file);

bool is_leap_year(int year);
