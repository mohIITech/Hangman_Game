#include <stdio.h>
#include "select_level.h"

int selectLevel() {
    int level;

    // Display difficulty levels
    printf("\nSelect Difficulty Level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter your choice: ");
    scanf("%d", &level);

    return level;
}
