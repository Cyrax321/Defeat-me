#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("cls"); 

void printCat() {
    printf("\033[1;33m"); 

    printf(" /\\_/\\     /\\_/\\\n");
    printf("( o.o )   ( o.o )\n");
    printf(" > ^ <     > ^ <\n");
    
    printf("\033[0m"); 
}

void displayResult(int playerChoice, int computerChoice) {
    clearScreen();
    printf("\033[1;36m");
    printf("╔═══════════════════════════════════════════════════════════╗\n");
    printf("║                 Welcome to Wizard, Knight, Dragon!          ║\n");
    printf("╚═══════════════════════════════════════════════════════════╝\n\n");
    printf("\033[0m");

    if (playerChoice == computerChoice) {
        printf("\033[1;33m");
        printf("It's a draw! The forces of magic are in perfect harmony.\n\n");
        printf("\033[0m");
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        printf("\033[1;32m");
        printf("Victory is yours! The power of your magic reigns supreme.\n\n");
        printf("\033[0m");
    } else {
        printf("\033[1;31m");
        printf("Alas, defeat! The dragon's fire proves too fierce.\n\n");
        printf("\033[0m");
    }
}

void displayAbilities() {
    printf("\033[1;36m");
    printf("Choose your special ability:\n");
    printf("\033[0m");
    printf("1. \033[1;35mWizard\033[0m: Cast a powerful spell to enchant your opponent.\n");
    printf("2. \033[1;35mKnight\033[0m: Unleash your mighty sword for a devastating strike.\n");
    printf("3. \033[1;35mDragon\033[0m: Breathe fire to scorch your enemy with blazing fury.\n");
}

void performAbility(int playerChoice, int computerChoice) {
    clearScreen();
    printf("\033[1;36m");
    printf("Prepare for a display of magic!\n\n");
    printf("\033[0m");
    
    switch(playerChoice) {
        case 1:
            printf("You cast a powerful spell and enchant your opponent!\n");
            break;
        case 2:
            printf("With a mighty swing, your sword strikes true!\n");
            break;
        case 3:
            printf("You unleash a torrent of fire, scorching your enemy!\n");
            break;
        default:
            break;
    }
    
    if (playerChoice == computerChoice) {
        printf("\033[1;33m");
        printf("It's a draw! Your special ability is nullified.\n\n");
        printf("\033[0m");
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        printf("\033[1;32m");
        printf("Your special ability turns the tide in your favor!\n\n");
        printf("\033[0m");
    } else {
        printf("\033[1;31m");
        printf("Your special ability is ineffective against your opponent.\n\n");
        printf("\033[0m");
    }
}

int main() {
    int playerChoice, computerChoice, abilityChoice;
    char playAgain;

    srand(time(0));
    
    do {
        clearScreen();
        printf("\033[1;36m");
        printf("╔═══════════════════════════════════════════════════════════╗\n");
        printf("║                 Welcome to Wizard, Knight, Dragon!          ║\n");
        printf("╚═══════════════════════════════════════════════════════════╝\n\n");
        printf("\033[0m");
        printf("Choose your mystical ally:\n");
        printf("1. Wizard\n");
        printf("2. Knight\n");
        printf("3. Dragon\n");
        scanf("%d", &playerChoice);

        if (playerChoice < 1 || playerChoice > 3) {
            printf("\033[1;31m");
            printf("Invalid choice! Please choose a number between 1 and 3.\n");
            printf("\033[0m");
            continue;
        }

        computerChoice = rand() % 3 + 1;
        displayAbilities();
        scanf("%d", &abilityChoice);
        performAbility(playerChoice, computerChoice);
        displayResult(playerChoice, computerChoice);

        printf("\nNow, let's summon a cute cat to celebrate your adventure!\n");
        printCat();

        printf("\033[1;36m");
        printf("Do you dare to challenge fate again? (y/n): ");
        printf("\033[0m");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\033[1;35m");
    printf("\nFarewell, brave adventurer! May your magic never wane!\n");
    printf("\033[0m");

    return 0;
}
