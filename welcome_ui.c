#include "welcome_ui.h"
#include <stdio.h>
#include <stdlib.h>  // For system() to clear the screen

// Function to clear the screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux/Mac/WSL
    #endif
}

// Function to print the welcome message
void printWelcomeMessage() {
    clearScreen();
    
    // Printing the "HANGMAN" text in a styled format
    for(int i=0; i<7; i++)
        printf("__ _ __ ");
    
    printf("\n        _     _     _     _     _     _     _  \n");
    printf("       / \\   / \\   / \\   / \\   / \\   / \\   / \\ \n");
    printf("      ( H ) ( A ) ( N ) ( G ) ( M ) ( A ) ( N )\n");
    printf("       \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/  \n");

    printf("\n         !!! WELCOME TO THE HANGMAN GAME !!!        \n\n");
    printf("BY : RISHU   ---   MOHIT   ---    AYUSH   ---   KARTIK\n");

    for(int i=0; i<7; i++)
        printf("__ _ __ ");
    printf("\n\nPress ENTER key to continue .......");
    getchar();  // Wait for user input before continuing
    clearScreen();
}

// Function to display the main menu
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
