#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

char *morse_codes;

void home();
int find_length_of(char *s); //returns length of a string
void palindrome(); //asks for a string and says if it is palindrome or not
void guess_number(); //guess a two digit number
void spr(); //scissor paper rock game, computer vs user

int main(){
	home();
	getch();
	return 0;
}

void home(){
	srand(time(NULL)); //seeding the random number generator
	int n = 0;
	printf("[ Welcome To All_In_1_C_Programs ]\n");
	printf("----------------------------------\n");
	//Options are still incomplete
	printf("1. Palindrome Checker\n");
	printf("2. Guess the number\n");
	printf("3. Scissor Paper Rock\n");
	printf("----------------------------------\n");
	printf("Choose one: ");
	scanf("%d", &n);
	int l  =0;
	switch(n){
		case 1:
			//call palindrome function
			palindrome();
			break;
		case 2:
			//call guess_number function
			guess_number();
			break;
		case 3:
			//call spr function
			spr();
			break;
		default:
			printf("Invalid choice\n");
			break;
	}
}

int find_length_of(char *s){
	int len = 0;
	while(s[len] != '\0'){
		len++;
	}
	return len;
}

void palindrome(){
	char *text;
	printf("Enter a string: ");
	scanf("%s", text);
	int i, j, len = find_length_of(text);
	j = len - 1;
	for(i = 0; i <= j; i++){
		if(text[i] != text[j]){
			printf("Not palindrome!\n");
			return;
		}
		j--;
	}
	printf("Palindrome!\n");
}

void guess_number(){
	int random_number = (rand() % 90) + 10;
	int rleft = random_number, rright = random_number % 10, ileft, iright;
	rleft = (rleft / 10) % 10;
	int n = 0, tries = 0;
	do{
		printf("Enter the two digit number: ");
		scanf("%d", &n);
		if(n < 0){
			printf("Reveal: %d\n", random_number);
			printf("Enter the two digit number: ");
			scanf("%d", &n);
		}
		tries++;
		iright = n % 10;
		ileft = n;
		ileft = (ileft / 10 ) % 10;
		
		if(ileft != rleft && iright == rright){
			printf("-+\n");
		}
		else if(ileft == rleft && iright != rright){
			printf("+-\n");
		}
		else if(n == random_number){
			printf("++\nYou Win in %d tries!\n", tries);
		}
		else if(ileft != rleft && ileft == rright && iright != rright && iright == rleft){
			printf("##\n");
		}
		else if(iright != rright && iright == rleft && ileft != rleft){
			printf("-#\n");
		}
		else if(ileft != rleft && ileft == rright && iright != rright){
			printf("#-\n");
		}
		else if(ileft != rleft && iright != rright){
			printf("--\n");
		}
	}while(n!=random_number);
}

void spr(){
	//s=1, r=2, p=3
	int play = 1;
	int p1=0, p2=0;
	while(play == 1){
		p1 = (rand() % 3) + 1;
		do{
			printf("1.Scissor  2.Rock  3.Paper  Choose one: ");
			scanf("%d", &p2);
		}while(p2 < 0 || p2 > 3);
		
		if(p1 == p2){
			if(p1 == 1) printf("Scissor vs Scissor\n");
			if(p1 == 2) printf("Rock vs Rock\n");
			if(p1 == 3) printf("Paper vs Paper\n");
			printf("Draw\n");
		}
		else if(p1 = 1 && p2 == 2) printf("Scissor < Rock \nYou win!\n"); //rock p2 wins
		else if(p1 = 2 && p2 == 1) printf("Rock > Scissor \nComputer wins!\n"); //rock p1 wins 
		else if(p1 = 2 && p2 == 3) printf("Rock < Paper \nYou win!\n"); //paper p2 wins
		else if(p1 = 3 && p2 == 2) printf("Paper > Rock \nComputer wins!\n"); //paper p1 wins
		else if(p1 = 3 && p2 == 1) printf("Paper < Scissor \nYou win!\n"); //scissor p2 wins
		else if(p1 = 1 && p2 == 3) printf("Scissor > Paper \nComputer wins!\n"); //scissor p1 wins
		printf("Play again (1/0)? ");
		scanf("%d", &play);
	}
}
