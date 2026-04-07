#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char username[50];
    char password[50];
}
User;

int main(int argc, char *argv[])
{

    if(argc != 3){
        printf("Error receiving data");
        return 1;
    }

    User newUser;

    strcpy(newUser.username, argv[1]);
    strcpy(newUser.password, argv[2]);

    printf("User %s registered successfully!", newUser.username);

    return 0;
}