#include <stdio.h>
#include <stdlib.h>
#include "funcchisla.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Введен неправильный аргумент %s\n", argv[0]);
        return 1;
    }

    int cur=0;
    int futur=0;
    printf("с какого года начинать считать: ");
    scanf("%d", &cur);
    printf("каким годом нужно остановится %d-", cur);
    scanf("%d", &futur);

    if (cur > futur) {
        printf("введены неправильные годы\n");
        return 1;
    }


    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return 1;
    }


    process_years(cur, futur, file);

    fclose(file);
    printf("результаты были записаны в файл: %s\n", argv[1]);
    return 0;
}