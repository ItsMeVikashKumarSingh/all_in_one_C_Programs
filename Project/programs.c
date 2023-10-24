#include<stdio.h>
#include<conio.h>

void home();
int find_length_of(char *s); //returns length of a string
void palindrome(); //asks for a string and says if it is palindrome or not

int main(){
	home();
	getch();
	return 0;
}

void home(){
	int n = 0;
	printf("[ Welcome To All_In_1_C_Programs ]\n");
	printf("----------------------------------\n");
	//Options are still incomplete
	printf("1. Palindrome Checker\n");
	printf("----------------------------------\n");
	printf("Choose one: ");
	scanf("%d", &n);
	int l  =0;
	switch(n){
		case 1:
			//call palindrome function
			palindrome();
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
