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
    for(int i=0;s[i]!='\0';i++)
        if( ! ((s[i]-'0'>=0 && s[i]-'0'<10)||s[i]==' '||s[i]=='?'))
            return 1;

    return 0;
}
char * format(char *x){
    int l = 0;
    for(int i=0;x[i]!='\0';i++) {
        if (x[i] != ' ')l++;    //find number of digits or '?';
    }
    char *y=malloc(sizeof(char)*(l+2));
    int j=0;
    for(int i=0;x[i]!='\0';i++){
        if(x[i]!=' '){
            y[j]=x[i];
            j++;
        }
    }
    y[j]='\0';
    return y;
}
void check(char* operator,char* op1,char* op2,char* res){
    int o1 = 0;
    for(int i=0;op1[i]!='\0';i++){
        o1*=10;
        o1+=(op1[i]-'0');
    }
    int o2 = 0;
    for(int i=0;op2[i]!='\0';i++){
        o2*=10;
        o2+=(op2[i]-'0');
    }
    int r = 0;
    for(int i=0;res[i]!='\0';i++){
        r*=10;
        r+=(res[i]-'0');
    }

    if(*operator=='+') {
        if (o1 + o2 == r)printf("%d + %d = %d\n",o1,o2,r);
    }else if(*operator=='-'){
//        if(o2==310701)printf("check %d - %d = %d is %d\n",o1,o2,r,o1-o2==r);
        if(o1-o2==r)printf("%d - %d = %d\n",o1,o2,r);
    }else if(*operator=='*'){
        if(o1*o2==r)printf("%d * %d = %d\n",o1,o2,r);
    }
    if(*operator=='/'){
        if(o1/o2==r)printf("%d / %d = %d\n",o1,o2,r);
    }
}
int process(char* operator, char* op1, char* op2, char*res){
    int no_questions = 1;
    if(operator[0]=='?'){
        no_questions = 0;
        operator[0]='+';
        process(operator,op1,op2,res);
        operator[0]='-';
        process(operator,op1,op2,res);
        operator[0]='*';
        process(operator,op1,op2,res);
        operator[0]='/';
        process(operator,op1,op2,res);
    }
    if(no_questions) {
        for (int i = 0; op1[i] != '\0'; i++) {
            if (op1[i] == '?') {
                no_questions = 0;
                for (char j = '0'; j <= '9'; j++) {
                    op1[i] = j;
                    process(operator, op1, op2, res);
                }
                op1[i] = '?';
                break;
            }
        }
    }
    if(no_questions) {
        for (int i = 0; op2[i] != '\0'; i++) {
            if (op2[i] == '?') {
                no_questions = 0;
                for (char j = '0'; j <= '9'; j++) {
                    op2[i] = j;
                    process(operator, op1, op2, res);
                }
                op2[i] = '?';
                break;
            }
        }
    }
    if(no_questions) {
        for (int i = 0; res[i] != '\0'; i++) {
            if (res[i] == '?') {
                no_questions = 0;
                for (char j = '0'; j <= '9'; j++) {
                    res[i] = j;
                    process(operator, op1, op2, res);
                }
                res[i] = '?';
                break;
            }
        }
    }
    if(no_questions){

        check(operator,op1,op2,res);
    }

}
int main(int n,char*args[]){
    if(n!=5){
        printf("usage: ./part_of_the_matrix [operand1] [operator] [operand2] [result]\n");
        exit(0);
    }
//    printf("%s\n%s\n%s\n%s\n",args[1],args[2],args[3],args[4]);
    if(invalid_op(args[2])){
        printf("invalid operator: %s\n",args[2]);
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
    if(invalid_n(args[4])){
        printf("invalid result: %s\n",args[4]);
    }
    char *operator = format(args[2]);
    char *op1 = format(args[1]);
    char *op2 = format(args[3]);
    char *res = format(args[4]);
    process(operator,op1,op2,res);


}