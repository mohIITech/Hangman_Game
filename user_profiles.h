#ifndef USER_PROFILES_H
#define USER_PROFILES_H

#define MAX_USERS 100

typedef struct {
    char username[50];
    int score;
} User;

int userExists(char *username);
void createUser(char *username);
void handleUserLogin(User *user);
void updateLeaderboard(User *user); 

#endif 

