#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    float units_consumed;
};

struct User users[MAX_USERS];
int user_count = 0;

bool login(char *username, char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}

void register_user(char *username, char *password) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].username, username);
        strcpy(users[user_count].password, password);
        users[user_count].units_consumed = 0;
        user_count++;
        printf("User registered successfully.\n");
    } else {
        printf("Maximum user limit reached. Cannot register new users.\n");
    }
}

float calculate_bill(float units) {
    float bill = 50;
    if (units <= 100) {
        bill = units * 7.25;
    } else if (units <= 200) {
        bill = 100 + (units - 100) * 8.25;
    } else {
        bill = 250 + (units - 200) * 9.3;
    }
    return bill;
}

int main() {
    int choice;
    char username[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    float units;

    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                register_user(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (login(username, password)) {
                    printf("Login successful.\n");
                    printf("Enter units consumed: ");
                    scanf("%f", &units);
                    if (units < 0) {
                        printf("Invalid input. Units consumed cannot be negative.\n");
                    } else {
                        float bill = calculate_bill(units);
                        printf("Your electric bill is: %.2f\n", bill);
                    }
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}