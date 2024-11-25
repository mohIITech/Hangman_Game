#include "welcome_ui.h"
#include <stdio.h>
#include <stdlib.h>  


void clearScreen() {    // a custom clear screen function for windows/(MAC , LINUX)
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}

void printWelcomeMessage() {        // made a ascii art for welcome message
    clearScreen();
    
    
    for(int i=0; i<7; i++)
        printf("__ _ __ ");
    
    printf("\n        _     _     _     _     _     _     _  \n");
    printf("       / \\   / \\   / \\   / \\   / \\   / \\   / \\ \n");
    printf("      ( H ) ( A ) ( N ) ( G ) ( M ) ( A ) ( N )\n");
    printf("       \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/  \n");

    printf(BLUE "\n         !!! WELCOME TO THE HANGMAN GAME !!!        \n\n" RESET);
    printf(GREEN "BY : RISHU   ---   MOHIT   ---    AYUSH   ---   KARTIK\n" RESET);

    for(int i=0; i<7; i++)
        printf("__ _ __ ");
    printf("\n\nPress ENTER key to continue .......");
    getchar();  // used getchar function to keep the game on hold until player enters
    clearScreen();
}


void displayMainMenu() {
    clearScreen();

    printf("  +---------------------+\n");
    printf("  |     MAIN MENU       |\n");
    printf("  +---------------------+\n");
    printf("  | 1. Start Game       |\n");
    printf("  | 2. View Leaderboard |\n");
    printf("  | 3. Exit             |\n");
    printf("  +---------------------+\n");
    printf("Enter your choice: ");
}
