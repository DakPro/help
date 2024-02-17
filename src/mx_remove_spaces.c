#include "../header.h"

char *mx_remove_spaces(const char *str) {
    char *result = malloc(mx_strlen(str) + 1);
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}
