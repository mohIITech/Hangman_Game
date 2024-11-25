#include <stdio.h>
#include <string.h>
#include "leader_board.h"
#include "user_profiles.h"

void updateScore(char *username, int newScore) {
    FILE *file = fopen("leaderboard.txt", "r+");
    if (!file) {
        file = fopen("leaderboard.txt", "w+");
        if (!file) {
            printf("Error opening leaderboard file!\n");
            return;
        }
    }

    User users[MAX_USERS];
    int count = 0;
    int found = 0;

    // Read existing leaderboard
    while (fscanf(file, "%s %d", users[count].username, &users[count].score) != EOF) {
        count++;
    }

    // Update the score of the current user
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].score = newScore;
            found = 1;
            break;
        }
    }

    if (!found) {
        // If user is not found, add to the leaderboard
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

void displayLeaderboard() {
    FILE *file = fopen("leaderboard.txt", "r");
    if (!file) {
        printf("No leaderboard available.\n");
        return;
    }

    User users[MAX_USERS];
    int count = 0;

    while (fscanf(file, "%s %d", users[count].username, &users[count].score) != EOF) {
        count++;
    }

    printf("\n+--------------------------+\n");
    printf("|   LEADERBOARD            |\n");
    printf("+--------------------------+\n");
    for (int i = 0; i < count; i++) {
        printf("| %d. %-20s %-10d |\n", i+1, users[i].username, users[i].score);
    }
    printf("+--------------------------+\n");

    fclose(file);
}
