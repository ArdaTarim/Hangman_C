#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// --- ANIMATIONS ---

void print_firstState() {
  printf("    _____   \n");
  printf("    |       \n");
  printf("    |       \n");
  printf("    |       \n");
  printf(" ___|___    \n");
}

void print_secondState() {
  printf("    _____   \n");
  printf("    |   o   \n");
  printf("    |       \n");
  printf("    |       \n");
  printf(" ___|___    \n");
}

void print_thirdState() {
  printf("    _____   \n");
  printf("    |   o   \n");
  printf("    |   |   \n");
  printf("    |       \n");
  printf(" ___|___    \n");
}

void print_fourthState() {
  printf("    _____   \n");
  printf("    |   o   \n");
  printf("    |  /|   \n");
  printf("    |       \n");
  printf(" ___|___    \n");
}

void print_fifthState() {
  printf("    _____   \n");
  printf("    |   o   \n");
  printf("    |  /|\\  \n");
  printf("    |       \n");
  printf(" ___|___    \n");
}

void print_sixthState() {
  printf("    _____   \n");
  printf("    |   o   \n");
  printf("    |  /|\\  \n");
  printf("    |  /    \n");
  printf(" ___|___    \n");
}

void print_seventhState() {
  printf("    _____   \n");
  printf("    |   o   \n");
  printf("    |  /|\\  \n");
  printf("    |  / \\  \n");
  printf(" ___|___    \n");
}

// --- METHODS ---

// lose
void deleteOperationSystem() {
  sleep(1);
  system("clear");
  sleep(1);
  printf("deleting operating system...\n");
  sleep(3);
  printf("deleting system files...\n");
  sleep(3);

  system("osascript -e 'tell application \"System Events\" to sleep'");
}

// generate random integer
int generateRandom(int min, int max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// methods to get input
bool isAvailableChar(char input) {
  char availableChars[] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; availableChars[i] != '\0'; i++) {
    if (input == availableChars[i]) {
      return true;
    }
  }
  return false;
}

char getInput() {
  char input;
  do {
    scanf(" %c", &input);
  } while (input == '\n' || !isAvailableChar(input));
  return input;
}

// check if the given array contains the char
bool isCharInArray(char c, char *chars, int charsLength) {
  int i;
  for (i = 0; i < charsLength; i++) {
    if (c == chars[i]) {
      return true;
    }
  }
  return false;
}

// print the word with found chars
void printWord(char *word, int wordLength, char *charsFound, int charFoundIdx) {
  // testword
  // _ _ _ _ _ _ _ _
  // t
  // t _ _ t _ _ _ _

  for (int i = 0; i < wordLength; ++i) {
    if (isCharInArray(word[i], charsFound, charFoundIdx + 1)) {
      printf("%c ", word[i]);
    } else {
      printf("_ ");
    }
  }

  printf("\n");
}

// --- MAIN ---
int main() {
  system("clear");

  // choose a random word for the game
  srand(42);
  char *words[] = {"tedujam"};
  int arrSize = sizeof(words) / sizeof(words[0]);
  int randomIndex = generateRandom(0, arrSize);

  // chosen word to play the game
  char *word = words[randomIndex];

  // finding individual chars in word
  char charsInWord[26];
  int charsInWordIdx = 0;

  for (; charsInWordIdx < strlen(word); charsInWordIdx++) {
    if (!isCharInArray(word[charsInWordIdx], charsInWord, strlen(word))) {
      charsInWord[charsInWordIdx] = word[charsInWordIdx];
    }
  }

  // used chars by player
  char charsUsed[26];
  int charsUsedIdx = 0;

  // correct chars
  char charsFound[26];
  int charsFoundIdx = 0;

  int wrongGuesses = 0;

  while (wrongGuesses < 6) {
    // Print the current state of the game
    switch (wrongGuesses) {
    case 0:
      print_firstState();
      break;
    case 1:
      print_secondState();
      break;
    case 2:
      print_thirdState();
      break;
    case 3:
      print_fourthState();
      break;
    case 4:
      print_fifthState();
      break;
    case 5:
      print_sixthState();
      break;
    }

    // print the word with found and secret characters
    int wordLength = strlen(word);
    printWord(word, wordLength, charsFound, charsFoundIdx);

    // get the input from user
    char input = getInput();

    system("clear");

    if (isCharInArray(input, charsUsed, charsUsedIdx + 1)) {
      printf("You already used this !!!\n");
    } else {
      charsUsed[charsUsedIdx] = input;
      charsUsedIdx++;
    }

    if (isCharInArray(input, charsInWord, charsInWordIdx + 1)) {
      printf("You guessed correctly !!!\n");
      charsFound[charsFoundIdx] = input;
      charsFoundIdx++;
    } else {
      printf("You guessed incorrectly !!!\n");
      wrongGuesses++;
    }
  }

  if (wrongGuesses == 6) {
    print_seventhState();
    printf("You lose :(\n");
    deleteOperationSystem();
  }

  return 0;
}
