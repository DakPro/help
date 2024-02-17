#include "../inc/header.h"

int error_handling(int argc, char *argv[]) {
    if (argc < 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand] [operation] [operand2] [result]\n");
        exit(-1);
    }
    char *operation = mx_remove_spaces(argv[2]);
	if (mx_strlen(operation) != 1){
		mx_printerr("Invalid operator: ");
		mx_rinterr(operation);
		mx_printerr("\n");
		exit(-1);
	}
	else if( *operation != '+' && *operation != '-' && *operation != '/' && *operation != '*' && *operation != '?') {
		mx_printerr("Invalid operator: ");
		mx_printerr(operation);
		mx_printerr("\n");
		exit(-1);
	}
    char *operand1 = mx_remove_spaces(argv[1]);
    char *operand2 = mx_remove_spaces(argv[3]);
    char *result = mx_remove_spaces(argv[4]);
    if (!mx_str_isdigit(operand1)) {
        mx_printerr("Invalid operand: ");
        mx_printerr(operand1);
        mx_printerr("\n");
        exit(-1);
    }
    if (!mx_str_isdigit(operand2)) {
        mx_printerr("Invalid operand: ");
        mx_printerr(operand2);
        mx_printerr("\n");
        exit(-1);
    }
    if (!mx_str_isdigit(result)) {
        mx_printerr("Invalid result: ");
        mx_printerr(result);
        mx_printerr("\n");
        exit(-1);
    }
    if(mx_atoi(operand2) == 0 && *operation == '/'){
		exit(-1);
	}

    return 1;
}
