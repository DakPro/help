#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int invalid_op(const char *s){
    int number_of_ok = 0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' ')
            continue;

        if(s[i]=='*'||s[i]=='+'||s[i]=='/'||s[i]=='-'||s[i]=='?')
            number_of_ok++;
        else
            return 1;       // return 1 because invalid (unpredicted character)

        if(number_of_ok>1)
            return 1;       //return 1 because invalid (too many operands)
    }
    if(number_of_ok!=1)
        return 1;             //return 1 because invalid (no operands)
    else
        return 0;               // if reached here we have only ' ' and 1 "ok" operand
}
int invalid_n(const char *s){
    for(int i=0;s[i]!='\0';i++){
        if( ! ((s[i]-'0'>=0 && s[i]-'0'<10)||s[i]==' '||s[i]=='?')){
            return 1;
        }
    }
    return 0;
}
int main(int n,char*args[]){
    if(n!=5){
        printf("usage: ./part_of_the_matrix [operand1] [operator] [operand2] [result]\n");
        exit(0);
    }
    if(invalid_op(args[2])){
        printf("invalid operation: %s\n",args[2]);
        exit(0);
    }
    if(invalid_n(args[1])){
        printf("invalid operand: %s\n",args[1]);
        exit(0);
    }
    if(invalid_n(args[3])){
        printf("invalid operand: %s\n",args[3]);
        exit(0);
    }
}