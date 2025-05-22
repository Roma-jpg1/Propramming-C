#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int max_len = 0;
    char buf[1000];
    char longest[1000] = "";
    long longest_pos = 0;

    while (fgets(buf, sizeof(buf), file) != NULL) {
        int len = strlen(buf);
        if (len > max_len) {
            max_len = len;
            strcpy(longest, buf);
            longest_pos = ftell(file) - len;
        }
    }

    char sent[200][1000];
    int word_count = 0;
    char *token = strtok(longest, " \t\n");
    
    while (token != NULL && word_count < 200) {
        strcpy(sent[word_count], token);
        word_count++;
        token = strtok(NULL, " \t\n");
    }

    if (word_count > 1) {
        char tmp[1000];
        strcpy(tmp, sent[0]);
        strcpy(sent[0], sent[word_count-1]);
        strcpy(sent[word_count-1], tmp);
    }

    longest[0] = '\0';
    for (int j = 0; j < word_count; j++) {
        strcat(longest, sent[j]);
        if (j < word_count-1) {
            strcat(longest, " ");
        }
    }


    fseek(file, longest_pos, SEEK_SET);
    fputs(longest, file);
    fclose(file);

    return 0;
}