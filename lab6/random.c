#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

void writeEmployeeToFile(FILE *file, int position, struct Employee emp) {
    fseek(file, position * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);
}

void readEmployeeFromFile(FILE *file, int position, struct Employee *emp) {
    fseek(file, position * sizeof(struct Employee), SEEK_SET);
    fread(emp, sizeof(struct Employee), 1, file);
}

int main() {
    FILE *file;
    struct Employee emp;
    int choice, position;

file = fopen("employees.txt", "w+");

    do {
        printf("\n1. Add employee\n2. Display employee\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter employee position: ");
                scanf("%d", &position);
                printf("Enter employee name: ");
                scanf(" %[^\n]", emp.name);
                printf("Enter employee age: ");
                scanf("%d", &emp.age);
                printf("Enter employee salary: ");
                scanf("%f", &emp.salary);
                writeEmployeeToFile(file, position, emp);
                break;
            case 2:
                printf("\nEnter employee position: ");
                scanf("%d", &position);
                readEmployeeFromFile(file, position, &emp);
                printf("Employee details:\n");
                printf("Name: %s\n", emp.name);
                printf("Age: %d\n", emp.age);
                printf("Salary: %.2f\n", emp.salary);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);

    fclose(file);

    return 0;
}
