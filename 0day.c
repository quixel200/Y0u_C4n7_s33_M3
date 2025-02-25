#include <stdio.h>
#include <string.h>

int main() {
    int encoded[] = {
        7, 53, 112, 17, 56, 49, 105, 99, 95, 
        11, 51, 12, 48, 11, 95, 97, 52, 102, 65, 100, 52, 110, 103, 51, 
        14, 79, 17, 11, 35, 90, 50, 10, 48, 97, 88, 78, 106, 98, 50, 
        57
    };
    
    int encoded_len = sizeof(encoded) / sizeof(encoded[0]);
    
    int key[encoded_len];
    key[0] = 3;
    key[1] = 2;
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
