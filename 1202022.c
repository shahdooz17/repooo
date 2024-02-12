#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 100
#define MAX_NAME_LENGTH 50

char friendNames[MAX_FRIENDS][MAX_NAME_LENGTH];
int friendDays[MAX_FRIENDS];
int friendMonths[MAX_FRIENDS];
int numFriends = 0;

int getDaysInMonth(int month) {
    switch (month) {
        case 2: // February
            return 28;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            return 30;
        default:
            return 31;
    }
}

void addFriend() {
    if (numFriends == MAX_FRIENDS) {
        printf("Cannot add more friends. The list is full.\n");
        return;
    }

    printf("Enter friend's name: ");
    scanf("%s", friendNames[numFriends]);

    printf("Enter friend's birth month (1-12): ");
    scanf("%d", &friendMonths[numFriends]);

    int daysInMonth = getDaysInMonth(friendMonths[numFriends]);
    printf("Enter friend's birth day (1-%d): ", daysInMonth);
    scanf("%d", &friendDays[numFriends]);

    numFriends++;
    printf("Friend added successfully!\n");
}

void displayList() {
    if (numFriends == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("Birthday List:\n");
    printf("--------------\n");

    for (int i = 0; i < numFriends; i++) {
        printf("%s - %d/%d\n", friendNames[i], friendDays[i], friendMonths[i]);
    }
}

void searchFriend() {
    if (numFriends == 0) {
        printf("The list is empty.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter friend's name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numFriends; i++) {
        if (strcmp(searchName, friendNames[i]) == 0) {
            printf("%s's birthday is on %d/%d\n", friendNames[i], friendDays[i], friendMonths[i]);
            return;
        }
    }

    printf("Friend not found.\n");
}

void birthdaysInMonth() {
    if (numFriends == 0) {
        printf("The list is empty.\n");
        return;
    }

    int searchMonth;
    printf("Enter month (1-12) to find birthdays: ");
    scanf("%d", &searchMonth);

    printf("Birthdays in Month %d:\n", searchMonth);
    printf("---------------------\n");

    for (int i = 0; i < numFriends; i++) {
        if (friendMonths[i] == searchMonth) {
            printf("%s - %d/%d\n", friendNames[i], friendDays[i], friendMonths[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nBirthday List Menu\n");
        printf("------------------\n");
        printf("1. Add a friend\n");
        printf("2. Display the list\n");
        printf("3. Search a friend's birthday\n");
        printf("4. List birthdays in a month\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFriend();
                break;
            case 2:
                displayList();
                break;
            case 3:
                searchFriend();
                break;
            case 4:
                birthdaysInMonth();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
