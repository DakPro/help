void mx_printchar(char c);

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

    int n_1 = n;
    int size = 0;
    while (n_1 != 0) {
        n_1 /= 10;
        size++;
    }

    int array[size];
    int i = 0;
    while (n != 0) {
        array[i] = n % 10;
        n /= 10;
        i++;
    }

    int j = i - 1;
    while (j >= 0) {
        mx_printchar(array[j] + 48);
        j--;
    }    
}
