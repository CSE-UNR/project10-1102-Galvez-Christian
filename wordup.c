//Author: Christian Galvez
//Date: 04/23/2025
//Purpose: Create a program that runs like the game wordle where a user guesses five letter words until the correct word is guessed

#include<stdio.h>
#define maxChances 6
#define maxLetters 6

void readDoc(char word[]);

void Lowercase(char playerGuess[]);

int checkGuess(char playerGuess[]);

int Correct(char playerGuess[], char word[]);

void displayUppercase(char playerGuess[], char word[]);

void displayArrowHint(char playerGuess[], char word[]);

void showGuesses(int round , char playerGuess[][6], char word[]);

int main() {
	
	int round = 0;
	
	int correct = 0;
	
	char word[maxLetters];
	
	char playerGuess[maxChances][maxLetters];
	
readDoc(word);
	
	while(round < maxChances && correct == 0){
	
	printf("Please enter a valid guess round %d:  ", round+1);
	scanf("%s", playerGuess[round]);
Lowercase(playerGuess[round]);
	
	if(checkGuess(playerGuess[round]) != 1){
		printf("Please Enter a valid guess \n");
		round--;
	}
	if(Correct(playerGuess[round],word) == 1){
	printf("\nYippee!!! You guessed the correct word! \n");
	correct = 1;
	return 0;
	 }

	showGuesses(round,playerGuess,word);
	 round++;
}
 
	if(correct == 0){
	printf("Oof that's all your guesses...Better luck next time!!!!!\n");
}
	
	return 0;
}



void readDoc(char word[]){
	FILE* filePointer = fopen("mystery.txt", "r");
	if(filePointer == NULL){
	printf("Did not open file \n");
	return;
}
	fscanf(filePointer,"%5s",word);
	fclose(filePointer);
}



//Function to convert guesses from the player into lowercase letters (idea from hint from lecture)
void Lowercase(char playerGuess[]){
	int index = 0;
	while(playerGuess[index] != 0){
	if(playerGuess[index] >= 'A' && playerGuess[index] <= 'Z'){
		playerGuess[index] = playerGuess[index] + 32;
	}
	index++;
	}
}
	
int checkGuess(char playerGuess[]){
	int guessLength = 0;
	while(playerGuess[guessLength] != '\0'){
		guessLength++;
	}	
	if(guessLength != 5){
	return 0;
}
	for(int index = 0; index < 5; index++){
		if((playerGuess[index] < 'A' || playerGuess[index] > 'Z')&&(playerGuess[index] < 'a' || playerGuess[index] > 'z')){
	return 0;
	
	}
}
	return 1;
}
	
int Correct(char playerGuess[], char word[]){
	int index = 0;
	
    while (index < 5) {
        if (playerGuess[index] != word[index]) {
            return 0; 
        }
        index++;
    }

    return 1;
}
	
void displayUppercase(char playerGuess[], char word[]){
	for(int i = 0; i < 5; i++){
	if(playerGuess[i] == word[i]){
	printf("%c", playerGuess[i] - 32);
	}else{
	printf("%c",playerGuess[i]);
}
}
}
	
void displayArrowHint(char playerGuess[], char word[]){
	printf("\n");
	for(int i = 0; i < 5; i++){
	int hintSpot;
		if(playerGuess[i] == word[i]){
		printf(" ");
		hintSpot = 0;
	
}else{
	
	for(int l = 0; l < 5; l++){
		if(playerGuess[i] == word[l] && i != l && playerGuess[l] != word[l]){
		hintSpot = 1;
	}
	}
	if(hintSpot == 1){
	printf("^");
}
	}
}
	printf("\n");
}
	
void showGuesses(int round , char playerGuess[][6], char word[]){
	for(int i = 0; i <= round; i++){
		displayUppercase(playerGuess[i], word);
		printf("\n");
		displayArrowHint(playerGuess[i], word);
		printf("\n");
		
		}
	}
	
		
	
	
	
	
	
	
	
