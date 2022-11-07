#include <iostream>

long int hex2dec(const char *str) {
    long int result;
    if (str == nullptr || *str == '\0') {
        exit(-1);
    }
    bool is_negative = (str[0] == '-');
    if (*str == '+' || *str == '-') {
        ++str;
    }
    if (*str == '0' && *(++str) == 'x') {
        ++str;
    } else {
        exit(-1);
    }
    result = 0;
    if (*str == '\0') {
        exit(-1);
    }
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 16 + (*str - '0');
        } else if (*str >= 'A' && *str <= 'F') {
            result = result * 16 + (*str - '7');
        } else if (*str >= 'a' && *str <= 'f') {
            result = result * 16 + (*str - 'W');
        } else {
            exit(-1);
        }
        ++str;
    }
    return (is_negative) ? result * -1 : result;
}

int main(int argc, char **argv) {
    int i;
    for (i = 1; i < argc; ++i) {
        std::cout << hex2dec(argv[argc - i]) + 100 + 16 << '\n';
    }
    return 0;
}
