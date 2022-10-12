#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The notesearch exploit works by corrupting memory to control 
// execution flow.

int check_authentication(char *password) {
    char password_buffer[16];
    int auth_flag = 0;

    strcpy(password_buffer, password);

    if(strcmp(password_buffer, "brillig") == 0)
        auth_flag = 1;
    if(strcmp(password_buffer, "outgrabe") == 0)
        auth_flag = 1;

    return auth_flag;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        exit(0);
    }
    if(check_authentication(argv[1])) {
        printf("\n======================\n");
        printf("\n    ACCESS GRANTED.\n");
        printf("\n======================\n");
    } else {
        printf("    ACCESS DENIED.\n");
    }
}