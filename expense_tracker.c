#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_STRING 50

typedef struct {
    int id;
    float amount;
    char title[MAX_STRING];
    char category[MAX_STRING];
    char date[11];
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validateDate(const char *date) {
    int day, month, year;
    return sscanf(date, "%d/%d/%d", &day, &month, &year) == 3 
           && day > 0 && day <= 31 
           && month > 0 && month <= 12 
           && year >= 2000 && year <= 2100;
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }

    Expense newExpense;
    newExpense.id = expenseCount + 1;

    printf("Enter Expense Title: ");
    fgets(newExpense.title, MAX_STRING, stdin);
    newExpense.title[strcspn(newExpense.title, "\n")] = 0;

    printf("Enter Category: ");
    fgets(newExpense.category, MAX_STRING, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0;

    while (1) {
        printf("Enter Date (DD/MM/YYYY): ");
        fgets(newExpense.date, 11, stdin);
        newExpense.date[strcspn(newExpense.date, "\n")] = 0;
        
        if (validateDate(newExpense.date)) break;
        printf("Invalid date format.\n");
    }

    printf("Enter Amount: ");
    scanf("%f", &newExpense.amount);
    clearBuffer();

    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    printf("ID\tTitle\t\tCategory\tDate\t\tAmount\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d\t%-15s\t%-10s\t%s\t\t%.2f\n", 
               expenses[i].id, 
               expenses[i].title, 
               expenses[i].category, 
               expenses[i].date, 
               expenses[i].amount);
    }
}

void deleteExpense() {
    int id;
    printf("Enter expense ID to delete: ");
    scanf("%d", &id);
    clearBuffer();

    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].id == id) {
            for (int j = i; j < expenseCount - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            expenseCount--;
            printf("Expense deleted successfully!\n");
            return;
        }
    }
    printf("Expense not found.\n");
}

void expenseSummary() {
    float total = 0;
    printf("\n--- Expense Summary ---\n");
    
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    
    printf("Total Expenses: %.2f\n", total);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Expense Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: deleteExpense(); break;
            case 4: expenseSummary(); break;
            case 5: 
                printf("Exiting...\n");
                return 0;
            default: 
                printf("Invalid choice!\n");
        }
    }

    return 0;
}