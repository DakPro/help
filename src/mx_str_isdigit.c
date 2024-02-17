#include "../inc/header.h"

bool mx_str_isdigit(char *arr) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (!mx_isdigit(arr[i]) && arr[i] != '-' && arr[i] != '?') {
            return false;
        }
    }
    return true;
}
