#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATIO 2.35

int bet_money;
int transaction_number;
char bet_content;

int check_win(int transaction_number, char bet_content) {
  if ((bet_content == 'C' && transaction_number % 2 == 0) ||
      (bet_content == 'L' && transaction_number % 2 == 1)) {
    return 1;
  }
  return 0;
}

void play_game() {
  printf("Enter the amount of money to bet: ");
  scanf("%d", &bet_money);
  if (bet_money < 6000) {
    printf("The amount of money to bet must be greater than 6000\n");
    return;
  }
  srand(time(NULL));
  transaction_number = rand() % 1000000000 + 100000000;
  
  printf("Enter the content of the bet (C or L): ");
  scanf(" %c", &bet_content);
  printf("Transaction number: %d\n", transaction_number);
  int win = check_win(transaction_number, bet_content);
  if (win) {
    printf("You win, the prize money is %d\n", (int)(bet_money * RATIO));
  } else {
    printf("You lose\n");
  }
}

int main() {
  int choice = 1;
  int balance = 0;
  while (choice) {
    
    play_game();
    
    balance == balance + (bet_money * RATIO - bet_money) * check_win(transaction_number, bet_content);
    
    printf("Do you want to continue playing? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
    
  }
  return 0;
}
