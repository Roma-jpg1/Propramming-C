#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Work {
    char FIO[100];
    int zar;
    char tel[100];
};

int writeWork(char *filename, struct Work workers[], int N) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }
    fwrite(workers, sizeof(struct Work), N, file);
    fclose(file);
    return 0;
}

int findFIO(char *filename, char choice_str[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct Work temp;
    int i = 0;
    while (fread(&temp, sizeof(struct Work), 1, file) == 1) {
        if (strcmp(temp.FIO, choice_str) == 0) {
            printf("Информация о сотруднике: ФИО %s\n Ср заработок %d\n Номер телфона: %s\n", temp.FIO, temp.zar, temp.tel);
            i ++;
        }
    }

    if (i == 0) printf("Работник не найдена\n");

    fclose(file);
    return 0;
}

int findtel(char *filename, char choice_str[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct Work temp;
    int i = 0;
    while (fread(&temp, sizeof(struct Work), 1, file) == 1) {
        if (strcmp(temp.tel, choice_str) == 0) {
            printf("Информация о сотруднике: ФИО %s\n Ср заработок %d\n Номер телфона: %s\n", temp.FIO, temp.zar, temp.tel);
            i++;
        }
    }

    if (i == 0) printf("Работник не найдена\n");

    fclose(file);
    return 0;
}

int findzar(char *filename, int choice_num) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct Work temp;
    int i = 0;
    while (fread(&temp, sizeof(struct Work), 1, file) == 1) {
        if (temp.zar == choice_num) {
            printf("Информация о сотруднике: ФИО %s\n Ср заработок %d\n Номер телфона: %s\n", temp.FIO, temp.zar, temp.tel);
            i++;
        }
    }

    if (i == 0) printf("Работник не найдена\n");

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Ошибка: укажите имя файла в аргументах командной строки!\n");
        return 1;
    }

    int N;
    printf("Введите кол-во структур: ");
    scanf("%d", &N);
    if (N<1){
        printf("неккоректный ввод");
        return 0;
    }

    char *filename = argv[1];
    struct Work workers[N];

    for (int i = 0; i < N; i++) {
        printf("Введите данные для сотрудников %d\n", i + 1);
        printf("Введите ФИО: ");
        scanf("%s", workers[i].FIO);
        printf("Введите ср Заработок: ");
        scanf("%d", &workers[i].zar);
        printf("Введите номер телефона: ");
        scanf("%s", workers[i].tel);
    }

    writeWork(filename, workers, N);
    char choice[10];
    while (1) {
        printf("Введите поле для поиска (FIO | zar | tel) для выхода введите exit: ");
        scanf("%s", choice);
    

        if (strcmp(choice, "FIO") == 0) {
            char choice_str[100];
            printf("Введите ФИО сотрудника: ");
            scanf("%s", choice_str);
            findFIO(filename, choice_str);
        } else if (strcmp(choice, "zar") == 0) {
            int choice_num;
            printf("Введите ср заработок: ");
            scanf("%d", &choice_num);
            findzar(filename, choice_num);
        } else if (strcmp(choice, "tel") == 0) {
            char choice_str[100];
            printf("Введите номер телефона: ");
            scanf("%s", choice_str);
            findtel(filename, choice_str);
        } 
        else if ((strcmp("exit", choice))==0){
            return 1;
        }
        else {
            printf("Ошибка, введите поле ещё раз\n");
        }
    }
    return 0;
}
