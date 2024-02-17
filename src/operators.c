#include "../header.h"

void mx_operations(char *operator1, char *operation, char *operator2, char *result) {
    if (*operation == '?') {
        mx_operations(operator1, "+", operator2, result);
        mx_operations(operator1, "-", operator2, result);
        mx_operations(operator1, "*", operator2, result);
        mx_operations(operator1, "/", operator2, result);
        return;
    }

    int op1_len = mx_strlen(operator1);
    int op2_len = mx_strlen(operator2);
    int res_len = mx_strlen(result);

        
}
