#include <stdio.h>

char f = 'f';
char t = 't';

void AND(char p, char q) {
  char result;
  if (p == t && q == t) {
    result = t;
    printf("p and q = %c\n", result);
  } else {
    result = f;
    printf("p and q = %c\n", result);
  }
}

void OR(char p, char q) {
  char result;
  if (p == f && q == f) {
    result = f;
    printf("p or q = %c\n", result);
  } else {
    result = t;
    printf("p or q = %c\n", result);
  }
}

void NOT(char p, char q) {
  char pResult;
  char qResult;
  if (p == t) {
    pResult = f;
  } else {
    pResult = t;
  }
  if (q == t) {
    qResult = f;
  } else {
    qResult = t;
  }

  printf("¬p = %c\n", pResult);
  printf("   ¬q = %c\n", qResult);
}

void XOR(char p, char q) {
  char result;
  if (p == t && q == t) {
    result = f;
    printf("p ⊕ q = %c\n", result);
  } else if (p == f && q == f) {
    result = f;
    printf("p ⊕ q = %c\n", result);
  } else {
    result = t;
    printf("p ⊕ q = %c\n", result);
  }
}

void IfThen(char p, char q) {
  char result;
  if (p == t && q == f) {
    result = f;
    printf("p → q = %c\n", result);
  } else {
    result = t;
    printf("p → q = %c\n", result);
  }
}

void IfANDOnlyIf(char p, char q) {
  char result;
  if (p == t && q == t) {
    result = t;
    printf("p ↔ q = %c\n", result);
  } else if (p == f && q == f) {
    result = t;
    printf("p ↔ q = %c\n", result);
  } else {
    result = f;
    printf("p ↔ q = %c\n", result);
  }
}

void welcomeUI() {
  printf("=========================== \n");
  printf("Welcome to the Project (Logical gates) \n");
  printf("=========================== \n");
}

void gatesChoices() {
  printf("1. AND \n");
  printf("2. OR  \n");
  printf("3. NOT  \n");
  printf("4. XOR  \n");
  printf("5. If Then  \n");
  printf("6. If AND Only If  \n");
}

int main() {
  welcomeUI();

  int choice;
  char p;
  char q;

  while (1) {
    
    do {
      printf("Enter P value (t/f)  : ");
      scanf(" %c", &p);
      p = tolower(p); // Convert to lowercase
      if (p != 't' && p != 'f') {
        printf("Invalid input. Please enter 't' or 'f'.\n");
      }
      printf("Enter q value (t/f) : ");
      scanf(" %c", &q);
      q = tolower(q); // Convert to lowercase
      if (q != 't' && q != 'f') {
        printf("Invalid input. Please enter 't' or 'f'.\n");
      }
    } while (p != 't' && p != 'f' && q != 't' && q != 'f');

    gatesChoices();
    printf("Choose Logical Gate : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      AND(p, q);
      break;
    case 2:
      OR(p, q);
      break;
    case 3:
      NOT(p, q);
      break;
    case 4:
      XOR(p, q);
      break;
    case 5:
      IfThen(p, q);
      break;
    case 6:
      IfANDOnlyIf(p, q);
      break;
    case 0:
      printf("Goodbye!!\n");
      return 0;
    default:
      printf("Choice is invalid\n");
      break;
    }
  }

  return 0;
}