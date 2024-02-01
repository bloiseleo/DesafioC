#include <stdio.h>
#include <ctype.h>
#include <string.h>

int binToDec(int v, int p) {
    int i = v << p;
    return i;
}

int charToInt(char c) {
    return c - '0';
}

void decodeMessage(char *msg) {
    printf("Message Decoded below:\n");
    int p = 3;
    int partDecoded = 0;
    for (int i = 0; i < strlen(msg); i++) {
        char c = msg[i];
        if (isspace(c)) {
            continue;
        }
        if (p != -1) {
            partDecoded += binToDec(charToInt(c), p);
            p--;
            continue;
        }
        p = 7;
        while (p != 3) {
            c = msg[i];
            if (p == 4 || p == 5) {
                partDecoded += binToDec(!charToInt(c), p);
            }
            else {
                partDecoded += binToDec(charToInt(c), p);
            }
            p--;
            i++;
        }
        i--;
        printf("%c", (char) partDecoded);
        partDecoded = 0;
    }
}

int main() {
    char *msg = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";
    decodeMessage(msg);
}