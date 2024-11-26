#include <stdio.h>
#include <string.h>
#include "leader_board.h"
#include "user_profiles.h"
#include "welcome_ui.h"

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define USER_DATA_FILE "leaderboard.txt"

// Update the score of a user or add a new user to the leaderboard
void updateScore(char *username, int newScore) {
    FILE *file = fopen(USER_DATA_FILE, "r+");
    
    if (!file) {
        // If file does not exist, create a new one
        file = fopen(USER_DATA_FILE, "w+");
        if (!file) {
            printf("Error opening leaderboard file!\n");
            return;
        }
    }

    User users[MAX_USERS];
    int count = 0;
    int found = 0;

    // Read existing leaderboard data
    while (fscanf(file, "%s %d", users[count].username, &users[count].score) != EOF) {
        count++;
    }

    // Update the score of the current user if found
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].score = newScore;
            found = 1;
            break;
        }
    }

    // If the user is not found, add them to the leaderboard
    if (!found) {
        strcpy(users[count].username, username);
        users[count].score = newScore;
        count++;
    }

    // Rewind file and write all users' scores back
    rewind(file);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", users[i].username, users[i].score);
    }

    fclose(file);
}

// Display the leaderboard with colored output
void displayLeaderboard() {
    FILE *file = fopen(USER_DATA_FILE, "r");
    if (!file) {
        printf("No leaderboard available.\n");
        return;
    }

    User users[MAX_USERS];
    int count = 0;

    // Read all user data from the leaderboard
    while (fscanf(file, "%s %d", users[count].username, &users[count].score) != EOF) {
        count++;
    }

    // Print the leaderboard with color
    printf(MAGENTA"\n+--------------------------+\n"RESET);
    printf(MAGENTA"|   LEADERBOARD            |\n"RESET);
    printf(MAGENTA"+--------------------------+\n"RESET);
    for (int i = 0; i < count; i++) {
        printf("| %d. %-20s %-10d |\n", i + 1, users[i].username, users[i].score);
    }
    printf(MAGENTA"+--------------------------+\n"RESET);

    fclose(file);
}
