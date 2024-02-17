#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

char *mx_strncpy(char *, const char *, int);
void mx_swap_char(char *, char *);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char);
void mx_printint(int);
int mx_strncmp(const char *, const char *, int);
void mx_printerr(const char *);
void mx_str_reverse(char *);
char *mx_strcpy(char *, const char *);
int mx_strlen(const char *);
char *mx_strnew(const int);
char *mx_strdup(const char *);
void mx_printstr(const char *);
double mx_pow(double, unsigned int);
void mx_strdel(char **);
char *mx_strtrim(const char *str);
void printerr(const char *s);

bool mx_isdigit(int c);

bool mx_str_isdigit(char *arr);

int mx_atoi(const char *str);

int mx_strlen(const char *s);

char *mx_remove_spaces(const char *str);

void operators(char *operand1, char *operator, char * operand2, char *result);
int calculate(int operand1, char operation, int operand2);

#endif