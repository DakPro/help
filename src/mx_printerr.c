#include "../header.h"

void printerr(const char *s){
    write(2, s, mx_strlen(s));
}
