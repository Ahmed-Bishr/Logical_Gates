#include <ctype.h>
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

  printf("~p = %c\n", pResult);
  printf("~q = %c\n", qResult);
}

void XOR(char p, char q) {
  char result;
  if (p == t && q == t) {
    result = f;
    printf("p xor q = %c\n", result);
  } else if (p == f && q == f) {
    result = f;
    printf("p xor q = %c\n", result);
  } else {
    result = t;
    printf("p xor q = %c\n", result);
  }
}

void IfThen(char p, char q) {
  char result;
  if (p == t && q == f) {
    result = f;
    printf("p -> q = %c\n", result);
  } else {
    result = t;
    printf("p -> q = %c\n", result);
  }
}

void IfANDOnlyIf(char p, char q) {
  char result;
  if (p == t && q == t) {
    result = t;
    printf("p <-> q = %c\n", result);
  } else if (p == f && q == f) {
    result = t;
    printf("p <-> q = %c\n", result);
  } else {
    result = f;
    printf("p <-> q = %c\n", result);
  }
}

void toLowerCase(char *p, char *q) {
  *p = tolower(*p);
  *q = tolower(*q);
}

void showValues(char p, char q) {
  printf("p = %c", p);
  printf(" q = %c\n", q);
}

void welcomeUI() {
  printf("====================================== \n");
  printf("Welcome to the Project (Logical gates) \n");
  printf("====================================== \n");
}

void gatesChoices() {
  printf("1. AND \n");
  printf("2. OR  \n");
  printf("3. NOT  \n");
  printf("4. XOR  \n");
  printf("5. If Then  \n");
  printf("6. If AND Only If  \n");
  printf("0. Exit  \n");
}

void choices(int choice, char p, char q) {
  switch (choice) {
  case 1:
    showValues(p, q);
    AND(p, q);
    break;
  case 2:
    showValues(p, q);
    OR(p, q);
    break;
  case 3:
    showValues(p, q);
    NOT(p, q);
    break;
  case 4:
    showValues(p, q);
    XOR(p, q);
    break;
  case 5:
    showValues(p, q);
    IfThen(p, q);
    break;
  case 6:
    showValues(p, q);
    IfANDOnlyIf(p, q);
    break;
  default:
    printf("Choice is invalid\n");
    break;
  }
}

int main() {
  welcomeUI();

  int choice;
  char p;
  char q;

  while (1) {

    printf("Enter P value (t/f)  : ");
    scanf(" %c", &p);
    toLowerCase(&p, &q);

    if (p != 't' && p != 'f' && p != 'T' && p != 'F') {
      printf("Invalid input. Please enter 't' or 'f'.\n");
      break;
    }

    printf("Enter q value (t/f) : ");
    scanf(" %c", &q);
    toLowerCase(&p, &q);

    if (q != 't' && q != 'f') {
      printf("Invalid input. Please enter 't' or 'f'.\n");
      break;
    }

    

    gatesChoices();
    printf("Choose Logical Gate : ");
    scanf("%d", &choice);

    if (choice == 0) {
      printf("Goodbye!!\n");
      return 0;
    } else {
      choices(choice, p, q);
    }
  }

  return 0;
}