//
// Created by William Munoz Rodas on 13/09/24.
//

#include "overloading.h"

#include <algorithm>
#include <cstdio>

void overloading(bool show) {
    if (show) {
        printf("Functions Overloading\n");

        char buff[10];
        int a = 1;
        long b = 2;
        unsigned long c = 3;

        toa(a, buff, 10);
        toa(b, buff, 10);
        toa(c, buff, 10);

        printf("%s\n", buff);
    }
}

char* toa(int value, char *buffer, int base) {
    if (base < 2 || base > 36) {
        *buffer = '\0';
        return buffer;
    }

    char* ptr = buffer;
    char* start = buffer;

    bool isNegative = false;

    if (value < 0 && base == 10) {
        isNegative = true;
        value = -value;
    }

    do {
        int digit = value / base;
        *ptr++ = static_cast<char>((digit < 10) ? (digit + '0') : (digit - 10 + 'a'));
        value /= base;
    } while (value > 0);

    if (isNegative) {
        *ptr++ = '-';
    }

    *ptr = '\0';

    std::reverse(start, ptr);

    return buffer;
}

char* toa(long value, char* buffer, int base) {
    if (base < 2 || base > 36) {
        *buffer = '\0';  // Invalid base case
        return buffer;
    }

    char* ptr = buffer;
    char* start = buffer;

    bool isNegative = false;

    // Handle negative numbers for base 10
    if (value < 0 && base == 10) {
        isNegative = true;
        value = -value;
    }

    // Convert long integer to string in the specified base
    do {
        long digit = value % base;
        *ptr++ = static_cast<char>((digit < 10) ? (digit + '0') : (digit - 10 + 'a'));
        value /= base;
    } while (value > 0);

    // Add minus sign for negative numbers
    if (isNegative) {
        *ptr++ = '-';
    }

    *ptr = '\0';  // Null-terminate the string

    // Reverse the string
    std::reverse(start, ptr);

    return buffer;
}

char* toa(unsigned long value, char* buffer, int base) {
    if (base < 2 || base > 36) {
        *buffer = '\0';  // Invalid base case
        return buffer;
    }

    char* ptr = buffer;
    char* start = buffer;

    // Convert unsigned long integer to string in the specified base
    do {
        unsigned long digit = value % base;
        *ptr++ = static_cast<char>((digit < 10) ? (digit + '0') : (digit - 10 + 'a'));
        value /= base;
    } while (value > 0);

    *ptr = '\0';  // Null-terminate the string

    // Reverse the string
    std::reverse(start, ptr);

    return buffer;
}
