#include <stdio.h>
#include <string.h>

int main() {
int c=0;
char *is;
char *new;
char s[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna. aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
is=strtok(s,". ,"); // разделяем строку по точкам запятым и пробелам
int count=0;
int max = -1;
while(is != NULL){ //идем до конца строки
    // printf("%s\n",is);
    for (int i = 0; i<strlen(is);i++){ //перебираем каждое слово теперь каждое слово является строкой
        if (is[i]=='a' || is[i]=='A'){
            count+=1; //считаем количество букв (а) в двух регистрах
        }
    }
    if (max<count){
        max=count; //обновляем максимальное количество букв в слове каждый раз когда находится слово с большим количесвом (а)
        new=is; //обновляем максимальное слово 
    }
    count=0;
    is = strtok(NULL,". ,");
}
printf("%s %d \n", new, max); //выводим ответ
}