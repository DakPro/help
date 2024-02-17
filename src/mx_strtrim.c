#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace(char c);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int len = mx_strlen(str);
    int size_res = 0;

    for (int i = 0; i < len; i++) {
        if (!mx_isspace(str[i])) {
            size_res++;
        }
    }

    if (size_res == 0) {
        char *result = mx_strnew(0);
        return result;
    }

    char *result = mx_strnew(size_res + 1);
    if (result == NULL) {
        return NULL;
    }

    int j = 0;
    bool space_flg = true;

    for (int i = 0; i < len; i++) {
        if (!mx_isspace(str[i])) {
            mx_strncpy(&result[j], &str[i], 1);
            j++;
            space_flg = false;
        } else {
            if (!space_flg && str[i + 1] != '\0' && !mx_isspace(str[i + 1])) {
                result[j] = ' ';
                j++;
                space_flg = true;
            }
        }
    }

    result[j] = '\0';

    return result;
}
