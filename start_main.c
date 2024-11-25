#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"
#include "leader_board.h"
#include "select_level.h"
#include "user_profiles.h"
#include "welcome_ui.h"

int main() {
    User currentUser;
    int level;
    int choice;

    // Show welcome message first
    printWelcomeMessage();

    // Ask the user to login or register
    handleUserLogin(&currentUser);

    // Now, show the main menu after successful login or registration
    while (1) {
        printf("\n+---------------------+\n");
        printf("|     MAIN MENU       |\n");
        printf("+---------------------+\n");
        printf("| 1. Start Game       |\n");
        printf("| 2. View Leaderboard |\n");
        printf("| 3. Exit             |\n");
        printf("+---------------------+\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume any leftover newline character

        switch (choice) {
            case 1:
                // Game starts
                level = selectLevel();  // Ask for difficulty level
                playGame(&currentUser, level);  // Start the game
                break;

            case 2:
                // View leaderboard
                displayLeaderboard();  // Display the leaderboard
                break;

            case 3:
                // Exit the program
                printf("Exiting the game. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
