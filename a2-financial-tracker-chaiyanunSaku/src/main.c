/*
    Author: Chaiyanun Sakulsaowapakkul
    Description: Command-line Personal-Finance-Tracker project A2 for ICCS121 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/transaction.h"


// functions appear before main is a prototype, we need to declare so main can see
Transaction* loadTransaction(const char *filename);


int main() {
    const char *filename = "logs/transaction_log.txt";
    char answer[16];
    int resume = 0;
    Transaction *head = NULL;

    // welcome message and ask to resume
    printf("Welcome to your Personal Finance Tracker!\n\n");

    // keep asking yes or no to get 'resume'
    while(1) {
        printf("Would you like to resume your previous session? (y/n): ");
        int r = scanf(" %15s", answer);
        if (r != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (strlen(answer) == 1) {
            if (answer[0] == 'y' || answer[0] == 'Y') {
                resume = 1;
                break;
            } 
            if (answer[0] == 'n' || answer[0] == 'N') {
                resume = 0;
                break;
            } 
        }
        printf("Please answer with 'y' or 'n'.\n");
    }

    if (resume) {   // if resume then load old transactions
        printf("\nResuming from the last session...\n");
        head = loadTransaction(filename);
        if (head != NULL) {
            printf("Previous transaction loaded.\n\n");
            printCurrentBalance(head);
        } else {
            printf("No transacitons found!\n");
            printf("Starting a new session...\n");
        }
    } else {
        printf("Starting a new session...\n");
    }


    char command[50];  // keep asking for command until "quit"
    while(1) {
        printf("\nEnter command: ");
        scanf(" %[^\n]", command);

        // we use strcmp and strncmp to compare the command and input
        // "quit" write everything back into file but not those tagged as 'deleted'
        if (strcmp(command, "quit") == 0) {
            printf("\nSaving transactions to file...\n");
            saveTransaction(filename, head);
            printf("Done. Exiting program.\n");
            break;
        } else if (strncmp(command, "delete", 6) == 0) {
            int position = atoi(command + 7); // skip "delete" -> get number
            deleteTransaction(&head, position);
        } else if (strcmp(command, "print") == 0) {
            printTransactions(head); // print transac
        } else if (strncmp(command, "add ", 4) == 0) { // add expense or income
            char type[20];
            sscanf(command + 4, "%s", type); // get the part after "add "

            if (strcmp(type, "income") == 0 || strcmp(type, "expense") == 0) {
                addTransaction(&head, type);
            } else {
                printf("Invalid add command. Use \"add income\" or \"add expense\"\n");
            }
        } else if (strcmp(command, "add") == 0) { // invalid add command
            printf("Invalid add command. Use \"add income\" or \"add expense\"\n");
        } 

        else {
            printf("\nInvalid command.\n"); // if typed something else
            printf("Here are the existing commands: \n");
            printf("   'add income' 'add expense' 'delete <pos>' 'print' 'quit'.\n");
        }
    }

    return 0;
}