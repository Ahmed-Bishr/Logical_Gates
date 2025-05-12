#include <ctype.h>
#include <stdio.h>

const char f = 'f';
const char t = 't';

char AND(char p, char q) {
  if (p == t && q == t) {
    return t;
  }
  return f;
}

char OR(char p, char q) {
  if (p == f && q == f) {
    return f;
  }
  return t;
}

char NOT(char p) {
  return (p == t) ? f : t;
}

char XOR(char p, char q) {
  if ((p == t && q == f) || (p == f && q == t)) {
    return t;
  }
  return f;
}

char IfThen(char p, char q) {
  return (p == t && q == f) ? f : t;
}

char IfANDOnlyIf(char p, char q) {
  return (p == q) ? t : f;
}

void toLowerCase(char *p, char *q) {
  *p = tolower(*p);
  *q = tolower(*q);
}

void showValues(char p, char q) {
  printf("p = %c, q = %c\n", p, q);
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
  printf("7. TruthTable  \n");
  printf("0. Exit  \n");
}

void truthTable(char p, char q) {
  printf("\nTruth Table:\n");
  printf("p q | AND OR NOTp NOTq XOR IF-> IFF\n");
  printf("-----------------------------------\n");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%c %c | ", p, q);
      
      printf("%c  ", AND(p, q));
      printf("%c  ", OR(p, q));
      printf("%c  ", NOT(p));
      printf("%c  ", NOT(q));
      printf("%c  ", XOR(p, q));
      printf("%c  ", IfThen(p, q));
      printf("%c  ", IfANDOnlyIf(p, q));
      printf("\n");
    }
  }
}

void choices(int choice, char p, char q) {
  switch (choice) {
  case 1:
    showValues(p, q);
    printf("AND result: %c\n", AND(p, q));
    break;
  case 2:
    showValues(p, q);
    printf("OR result: %c\n", OR(p, q));
    break;
  case 3:
    showValues(p, q);
    printf("NOT p result: %c\n", NOT(p));
    printf("NOT q result : %c\n", NOT(q));
    break;
  case 4:
    showValues(p, q);
    printf("XOR result: %c\n", XOR(p, q));
    break;
  case 5:
    showValues(p, q);
    printf("If Then result: %c\n", IfThen(p, q));
    break;
  case 6:
    showValues(p, q);
    printf("If AND Only If result: %c\n", IfANDOnlyIf(p, q));
    break;
  case 7:
    truthTable(p, q);
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
