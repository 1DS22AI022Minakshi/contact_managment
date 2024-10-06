#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;
Contact contacts[100];  
int contactCount = 0;   

// Function to add a new contact
void addContact() {
    if (contactCount < 100) {
        printf("Enter Name: ");
        scanf(" %[^\n]", contacts[contactCount].name);
        printf("Enter Phone: ");
        scanf(" %[^\n]", contacts[contactCount].phone);
        printf("Enter Email: ");
        scanf(" %[^\n]", contacts[contactCount].email);
        
        contactCount++;  
        printf("Contact added successfully!\n");
    } else {
        printf("Contact list is full!\n");
    }
}
void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts available!\n");
        return;
    }

    printf("\nContacts List:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}
void searchContact() {
    char searchName[50];
    printf("Enter Name to search: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No contact found with name %s\n", searchName);
    }
}
void deleteContact() {
    char deleteName[50];
    printf("Enter Name to delete: ");
    scanf(" %[^\n]", deleteName);

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            found = 1;
            // Shift all contacts after the deleted one
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;  // Reduce the contact count
            printf("Contact deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("No contact found with name %s\n", deleteName);
    }
}
void editContact() {
    char editName[50];
    printf("Enter Name to edit: ");
    scanf(" %[^\n]", editName);

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, editName) == 0) {
            printf("Enter new Phone: ");
            scanf(" %[^\n]", contacts[i].phone);
            printf("Enter new Email: ");
            scanf(" %[^\n]", contacts[i].email);
            found = 1;
            printf("Contact edited successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("No contact found with name %s\n", editName);
    }
}
int main() {
    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Edit Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                editContact();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
