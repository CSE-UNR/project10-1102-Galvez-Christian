//Author: Christian Galvez
//Date: 04/23/2025
//Purpose: Create a program that runs like the game wordle where a user guesses five letter words until the correct word is guessed

#include<stdio.h>
#define maxChances 6
#define maxLetters 6

//All the function prototypes

void readDoc(char word[]);

void Lowercase(char playerGuess[]);

int checkGuess(char playerGuess[]);

int Correct(char playerGuess[], char word[]);

void displayUppercase(char playerGuess[], char word[]);

void displayArrowHint(char playerGuess[], char word[]);

void showGuesses(int round , char playerGuess[][6], char word[]);

int main() {
	
	//All variable and array declarations
	
	int round = 0;
	
	int correct = 0;
	
	char word[maxLetters];
	
	char playerGuess[maxChances][maxLetters];
	
	//Call to read the file
readDoc(word);
	
	//While statement to make sure program runs as long as the max amount of chances and victory are not hit
	while(round < maxChances && correct == 0){
	
	printf("Please enter a valid guess round %d:  ", round+1);
	
	//Scanf to get player guess
	scanf("%s", playerGuess[round]);
	
	//Call to lowercase format function
Lowercase(playerGuess[round]);
	
	//If statement using call to check if user guess is valid
	if(checkGuess(playerGuess[round]) != 1){
		printf("Please Enter a valid guess \n");
		round--;
	}
	
	//If statement to see if the user wins or not
	if(Correct(playerGuess[round],word) == 1){
	printf("\nYippee!!! You guessed the correct word! \n");
	correct = 1;
	return 0;
	 }

	//Call to the display function that shows all the previous guesses with hints
	showGuesses(round,playerGuess,word);
	 round++;
}
 
 	//losing message
	if(correct == 0){
	printf("Oof that's all your guesses...Better luck next time!!!!!\n");
}
	
	return 0;
}


	//Read file function
void readDoc(char word[]){
	FILE* filePointer = fopen("mystery.txt", "r");
	if(filePointer == NULL){
	printf("Did not open file \n");
	return;
}
	fscanf(filePointer,"%5s",word);
	fclose(filePointer);
}



//Function to convert guesses from the player into lowercase letters (idea from hint from lecture) so that the hints are easier to format, specifically the uppercase
void Lowercase(char playerGuess[]){
	int i = 0;
	while(playerGuess[i] != 0){
	if(playerGuess[i] >= 'A' && playerGuess[i] <= 'Z'){
		playerGuess[i] = playerGuess[i] + 32;
	}
	i++;
	}
}
	
	//Function that checks the players guesses to make sure that they are the wanted length of 5 characters AND make sure that those characters are letters. Uses mainly just the ascii values and then returns a 0 or 1 to the main.
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
	
	//Function that just checks if the user word matches the word in the file, and if so returns a 1 that gives the player the win 
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
	
	//Function that goes through and if the element in the playerguess function matches the one in the word function (the letters match the spots) it makes that letter uppercase and if it doesn't match it stays the same
void displayUppercase(char playerGuess[], char word[]){
	for(int i = 0; i < 5; i++){
	if(playerGuess[i] == word[i]){
	printf("%c", playerGuess[i] - 32);
	}else{
	printf("%c",playerGuess[i]);
}
}
}
	
	//Function that checks if the letter matches the letter in the file and if it does prints a space ' ' but if not it then goes through another check through a second for loop that if the letter is in the players guess but doesn't align with the position it will save that spot in the variable and then in that variable position print a '^' character.
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
	
	//function that calls to the two previous ones to easier display all the previous guesses with hints that are saved in the 2D array playerGuess (calls are in here because it was printing double when they were in the main so this worked so I left it)
void showGuesses(int round , char playerGuess[][6], char word[]){
	for(int i = 0; i <= round; i++){
		displayUppercase(playerGuess[i], word);
		printf("\n");
		displayArrowHint(playerGuess[i], word);
		printf("\n");
		
		}
	}
	
		
	
	
	
	
	
	
	
