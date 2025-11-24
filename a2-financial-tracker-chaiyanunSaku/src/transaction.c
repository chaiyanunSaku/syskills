#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"

Transaction* loadTransaction(const char *filename) {
    FILE *file = fopen(filename, "r"); // attempt to read file
    if (!file) return NULL;

    char line[256];
    Transaction *head = NULL;
    Transaction *tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n') continue; //skip comments

        char *p1 = strchr(line, '|');
        if (!p1) continue;

        char *p2 = strchr(p1 + 1, '|');
        if (!p2) continue;

        *p1 = '\0';  // decide to end with '\0' so we can write '|' even in descriptions
        *p2 = '\0';

        char *type = line;
        char *desc = p1 + 1;
        char *amount_str = p2 + 1;

        double amount = atof(amount_str);
        
        // create a new node
        // ask OS for some bytes enough to hold one Transaction using malloc, sizeof
        Transaction *newNode = malloc(sizeof(Transaction));
        strcpy(newNode->type, type);        // '->' is likely a dereference
        strcpy(newNode->description, desc); // newNode->amount  =  (*newNode).amount
        newNode->amount = amount;    // strcpy() cuz can't directly store strings into char[]
        newNode->status = SAVED;    // loaded from file so tagged as "SAVED"
        newNode->next = NULL;

        // linking
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}


double calculateBalance(Transaction *head) { // sum all transaction
    double total = 0.0;
    Transaction* current = head;

    while (current != NULL) {
        if (current->status != DELETED) {  // only add non "DELETED" nodes
            total += current->amount;
        }
        current = current->next;
    }
    return total;
}

// we print balance a lot so it is nice to have
void printCurrentBalance(Transaction* head) {
    double balance = calculateBalance(head);

    if (balance < 0) {
        printf("Current Balance: -$%.2f\n", -balance);
    } else {
        printf("Current Balance: $%.2f\n", balance);
    }

    if (balance >= 0) {
        printf("Budget Status: Within Budget\n");
    } else {
        printf("Budget Status: Over Budget!\n");
    }
}


void deleteTransaction(Transaction **head, int position) {
    if (*head == NULL || position <= 0) {
        printf("No transaction to delete.\n");
        return;
    }

    Transaction *temp = *head;
    for (int i = 1; temp !=NULL && i < position; i++) {
        temp = temp->next; // travel
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->status == DELETED) {
        printf("Transaction already marked as DELETED.\n");
        return;
    }

    temp->status = DELETED; // only tag it as DELETED not actually delete
    printf("Transaction at position %d marked for deletion.\n", position);
}

// print all transaction
void printTransactions(Transaction *head) {
    Transaction *current = head;
    int index = 1;

    printf("\n[ Transaction ]\n");
    while (current != NULL) {
        printf("%d. %-20s %8.2f", index, current->description, current->amount);

        if (current->status == NEW) // check statuses and print for each status
            printf("    (new)\n");
        else if (current->status == DELETED)
            printf("    --- d\n");
        else if (current->status == INSERTED)
            printf("    +++ i\n");
        else 
            printf("    (saved)\n");

        // travel
        current = current->next;
        index++;
    }

    printCurrentBalance(head);
}

void addTransaction(Transaction **head, const char *type) {
    char description[255];
    char amountStr[50];
    double amount;

    printf("Enter %s description: ", type);
    scanf(" %[^\n]", description);

    printf("Enter amount: ");
    scanf("%s", amountStr); // read it as string first

    int dotCount= 0;
    for (int i =0; amountStr[i] != '\0'; i++) {
        if (amountStr[i] == '.') {
            dotCount++;
            if (dotCount > 1) {  // example like '100..9'
                printf("Invalid amount. Transaction cancelled\n");
                return;
            }
        }
        else if (amountStr[i] < '0' || amountStr[i] > '9') {
            printf("Invalid amount. Transaction cancelled.\n");
            return;
        }
    }

    amount = atof(amountStr);
    if (amount < 0) {
        printf("Invalid amount. Transaction cancelled.\n");
        return;
    }

    if (strcmp(type, "expense") == 0) { // change to negative
        amount = -amount;
    }

    Transaction *newNode = malloc(sizeof(Transaction));
    if (!newNode) {    // full
        printf("Malloc failed. Transaction cancelled.\n");
        return;
    }
    if (strcmp(type, "income") == 0) {
        strcpy(newNode->type, "INC");
    } else {
        strcpy(newNode->type, "EXP");
    }
    strcpy(newNode->description, description);
    newNode->amount = amount;
    newNode->status = NEW;  // when addTransaction it gain status "NEW"
    newNode->next = NULL;

    char choice;
    printf("Do you want to insert at a certain position? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int position;
        newNode->status = INSERTED;  // if it was an insertion then tagged as "INSERTED"
        printf("Insert at position: ");
        if (scanf("%d", &position) != 1) {
            printf("Invalid position. Transaction cancelled.\n");
            free(newNode);
            while (getchar() != '\n'); // handle leftover
            return;
        }

        if (position <= 1 || *head == NULL) {
            newNode->next = *head;
            *head = newNode;
            if (strcmp(type, "income") == 0) printf("Income added at position 1.\n\n");
            else (printf("Expense added at position 1.\n\n"));
        } else {
            Transaction *temp = *head;
            int i = 1;

            while (temp->next != NULL && i < position - 1) {
                temp = temp->next;
                i++;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            if (strcmp(type, "income") == 0)
                printf("Income added at position %d.\n\n", i + 1);
            else
                printf("Expense added at position %d.\n\n", i + 1);
        }
    } else {
        // insert at the end
        if (*head == NULL) {
            *head = newNode;
        } else {
            Transaction *temp = *head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }

        if (strcmp(type, "income") == 0) printf("Income added.\n\n");
        else printf("Expense added.\n\n");
    }

    printCurrentBalance(*head);
}

void saveTransaction(const char *filename, Transaction *head) {
    FILE *file = fopen(filename, "w"); // write files
    if (!file) {
        printf("Error somehow.\n");
        return;
    }

    Transaction *current = head;
    while (current != NULL) { // keep travel if not NULL
        if (current->status != DELETED) { // If not DELTED we write it back using fprintf
            fprintf(file, "%s|%s|%.2f\n", // so essentially we skip DELTED that's how we save
                current->type,
                current->description,
                current->amount
            );
        }
        current = current->next; // travel
    }
    fclose(file);
}