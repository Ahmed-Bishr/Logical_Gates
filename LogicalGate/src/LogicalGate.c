#include <stdio.h>
#include <ctype.h>

#define TRUE 't'
#define FALSE 'f'

/* Function Prototypes */
void and_gate(char p, char q);
void or_gate(char p, char q);
void not_gate(char p, char q);
void xor_gate(char p, char q);
void if_then_gate(char p, char q);
void iff_gate(char p, char q);
void to_lower_case(char *p, char *q);
void show_values(char p, char q);
void welcome_ui(void);
void gates_choices(void);
void process_choice(int choice, char p, char q);

int main(void) {
    welcome_ui();

    int choice;
    char p, q;

    while (1) {
        printf("Enter P value (t/f): ");
        scanf(" %c", &p);
        to_lower_case(&p, &q);

        if (p != TRUE && p != FALSE) {
            printf("Invalid input. Please enter 't' or 'f'.\n");
            continue;  // Continue to ask for valid input
        }

        printf("Enter Q value (t/f): ");
        scanf(" %c", &q);
        to_lower_case(&p, &q);

        if (q != TRUE && q != FALSE) {
            printf("Invalid input. Please enter 't' or 'f'.\n");
            continue;  // Continue to ask for valid input
        }

        gates_choices();
        printf("Choose Logical Gate: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Goodbye!!\n");
            break;
        } else {
            process_choice(choice, p, q);
        }
    }

    return 0;
}

/* Logical Gate Functions */
void and_gate(char p, char q) {
    char result = (p == TRUE && q == TRUE) ? TRUE : FALSE;
    printf("p AND q = %c\n", result);
}

void or_gate(char p, char q) {
    char result = (p == FALSE && q == FALSE) ? FALSE : TRUE;
    printf("p OR q = %c\n", result);
}

void not_gate(char p, char q) {
    char p_result = (p == TRUE) ? FALSE : TRUE;
    char q_result = (q == TRUE) ? FALSE : TRUE;

    printf("~p = %c\n", p_result);
    printf("~q = %c\n", q_result);
}

void xor_gate(char p, char q) {
    char result = (p != q) ? TRUE : FALSE;
    printf("p XOR q = %c\n", result);
}

void if_then_gate(char p, char q) {
    char result = (p == TRUE && q == FALSE) ? FALSE : TRUE;
    printf("p -> q = %c\n", result);
}

void iff_gate(char p, char q) {
    char result = (p == q) ? TRUE : FALSE;
    printf("p <-> q = %c\n", result);
}

/* Utility Functions */
void to_lower_case(char *p, char *q) {
    *p = tolower(*p);
    *q = tolower(*q);
}

void show_values(char p, char q) {
    printf("p = %c, q = %c\n", p, q);
}

void welcome_ui(void) {
    printf("====================================== \n");
    printf("Welcome to the Project (Logical gates)\n");
    printf("====================================== \n");
}

void gates_choices(void) {
    printf("1. AND \n");
    printf("2. OR  \n");
    printf("3. NOT  \n");
    printf("4. XOR  \n");
    printf("5. If Then  \n");
    printf("6. If AND Only If  \n");
    printf("0. Exit  \n");
}

void process_choice(int choice, char p, char q) {
    switch (choice) {
        case 1:
            show_values(p, q);
            and_gate(p, q);
            break;
        case 2:
            show_values(p, q);
            or_gate(p, q);
            break;
        case 3:
            show_values(p, q);
            not_gate(p, q);
            break;
        case 4:
            show_values(p, q);
            xor_gate(p, q);
            break;
        case 5:
            show_values(p, q);
            if_then_gate(p, q);
            break;
        case 6:
            show_values(p, q);
            iff_gate(p, q);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }
}
