#include <stdlib.h>

char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
int mx_strlen(const char *s);

char *mx_strdup(const char *str) {
    int size_str = mx_strlen(str);
    char *dup = mx_strnew(size_str + 1);

    if (dup == NULL) {
        return NULL; 
    }

    return mx_strcpy(dup, str);
}
