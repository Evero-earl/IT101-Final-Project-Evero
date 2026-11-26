#include <stdio.h>

int main() {
    int choice, shape, size;
    int i, j, space;
    int grades[4];
    float average;
    char word[100];
    char again;
    int length, palindrome;

    do {
        printf("\n===== IT101A PROGRAM PORTFOLIO =====\n");
        printf("1. Pattern Generator\n");
        printf("2. Pascal's Triangle\n");
        printf("3. Grade Calculator\n");
        printf("4. Palindrome Checker\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- PATTERN GENERATOR ---\n");
            printf("1. Right Triangle\n");
            printf("2. Square\n");
            printf("3. Isosceles Triangle\n");
            printf("4. Inverted Right Triangle\n");
            printf("5. Christmas Tree\n");
            printf("Choose a shape: ");
            scanf("%d", &shape);

            printf("Enter the size (1 to 20): ");
            scanf("%d", &size);

            if (size < 1 || size > 20) {
                printf("Please enter a size from 1 to 20.\n");
            } else {
                if (shape == 1) {
                    for (i = 1; i <= size; i++) {
                        for (j = 1; j <= i; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                } else if (shape == 2) {
                    for (i = 1; i <= size; i++) {
                        for (j = 1; j <= size; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                } else if (shape == 3) {
                    for (i = 1; i <= size; i++) {
                        for (space = 1; space <= size - i; space++) {
                            printf(" ");
                        }
                        for (j = 1; j <= (2 * i - 1); j++) {
                            printf("*");
                        }
                        printf("\n");
                    }
                } else if (shape == 4) {
                    for (i = size; i >= 1; i--) {
                        for (j = 1; j <= i; j++) {
                            printf("* ");
                        }
                        printf("\n");
                    }
                } else if (shape == 5) {
                    for (i = 1; i <= size; i++) {
                        for (space = 1; space <= size - i; space++) {
                            printf(" ");
                        }
                        for (j = 1; j <= (2 * i - 1); j++) {
                            printf("*");
                        }
                        printf("\n");
                    }
                    for (i = 1; i <= size / 2 + 1; i++) {
                        for (space = 1; space < size; space++) {
                            printf(" ");
                        }
                        printf("*\n");
                    }
                } else {
                    printf("Invalid shape choice.\n");
                }
            }

        } else if (choice == 2) {
            int triangle[20][20] = {0};
            int rows;

            printf("\n--- PASCAL'S TRIANGLE ---\n");
            printf("Enter number of rows (1 to 20): ");
            scanf("%d", &rows);

            if (rows < 1 || rows > 20) {
                printf("Please enter a number from 1 to 20.\n");
            } else {
                for (i = 0; i < rows; i++) {
                    for (j = 0; j <= i; j++) {
                        if (j == 0 || j == i) {
                            triangle[i][j] = 1;
                        } else {
                            triangle[i][j] = triangle[i - 1][j - 1]
                                           + triangle[i - 1][j];
                        }
                    }
                }

                for (i = 0; i < rows; i++) {
                    for (space = 0; space < rows - i - 1; space++) {
                        printf("  ");
                    }
                    for (j = 0; j <= i; j++) {
                        printf("%4d", triangle[i][j]);
                    }
                    printf("\n");
                }
            }

        } else if (choice == 3) {
            printf("\n--- GRADE CALCULATOR ---\n");
            printf("Enter your Prelim grade: ");
            scanf("%d", &grades[0]);
            printf("Enter your Midterm grade: ");
            scanf("%d", &grades[1]);
            printf("Enter your Pre-Final grade: ");
            scanf("%d", &grades[2]);
            printf("Enter your Final grade: ");
            scanf("%d", &grades[3]);

            average = (grades[0] + grades[1] + grades[2] + grades[3]) / 4.0;

            printf("Average: %.2f\n", average);
            if (average >= 75) {
                printf("Status: PASS\n");
            } else {
                printf("Status: FAIL\n");
            }

        } else if (choice == 4) {
            printf("\n--- PALINDROME CHECKER ---\n");
            printf("Enter one word: ");
            scanf("%99s", word);

            length = 0;
            while (word[length] != '\0') {
                length++;
            }

            palindrome = 1;
            for (i = 0; i < length / 2; i++) {
                if (word[i] != word[length - 1 - i]) {
                    palindrome = 0;
                }
            }

            if (palindrome == 1) {
                printf("%s is a palindrome.\n", word);
            } else {
                printf("%s is not a palindrome.\n", word);
            }

        } else if (choice == 5) {
            printf("\nThank you for using the program!\n");
            break;
        } else {
            printf("Invalid menu choice. Please choose 1 to 5.\n");
        }

        if (choice >= 1 && choice <= 4) {
            printf("\nDo you want to try another operation? (Y/N): ");
            scanf(" %c", &again);
        } else {
            again = 'Y';
        }

    } while (again == 'Y' || again == 'y');

    printf("\nProgram ended.\n");
    return 0;
}
    
