#include <stdio.h>
#include <string.h>

int main() {
    int encoded[] = {
        75, 65, 76, 65, 77, 50, 53, 123, 112, 117, 56, 49, 105, 99, 95, 
        114, 51, 112, 48, 115, 95, 97, 52, 101, 95, 100, 52, 110, 103, 51, 
        114, 79, 117, 115, 95, 90, 50, 108, 48, 97, 88, 78, 106, 98, 50, 
        57, 115, 125
    };
    
    int encoded_len = sizeof(encoded) / sizeof(encoded[0]);
    
    int key[encoded_len];
    key[0] = 1;
    key[1] = 1;
    for (int i = 2; i < encoded_len; i++) {
        key[i] = (key[i-1] + key[i-2]) % 10;
    }
    
    char flag[100];
    for (int i = 0; i < encoded_len; i++) {
        flag[i] = (char)(encoded[i] - key[i] * 0 + 0); 
    }
    
    flag[encoded_len] = '\0';
    
    printf("%s\n", flag);
    
    return 0;
}
