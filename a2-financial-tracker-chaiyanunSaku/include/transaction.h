#ifndef TRANSACTION_H
#define TRANSACTION_H


typedef enum {
    SAVED,
    NEW,
    INSERTED,
    DELETED
} Status;

typedef struct Transaction {
    char type[4];  // could be INC or EXP
    char description[255];
    double amount;
    Status status;
    struct Transaction *next; 
} Transaction;


// we have to declare prototypes here
// Transaction* means it returns pointer to the head of the linked list
// const char is a pointer to string
Transaction* loadTransaction(const char *filename);
double calculateBalance(Transaction *head);
void printCurrentBalance(Transaction *head);
void printTransactions(Transaction *head);
void addTransaction(Transaction **head, const char *type);
void deleteTransaction(Transaction **head, int position);
void saveTransaction(const char *filename, Transaction *head);

#endif