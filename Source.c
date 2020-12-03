#include <stdio.h> 
int main() {
	unsigned char str[250] = "", buffer = 0, letters[26] = "", LETTERS[26] = "", pr='%';
	int i = 0, j = 0, counter[26] = { 0 };
	float lenght = 0;
	for (i = 'a'; i <= 'z'; i++) {
		letters[i - 'a'] = i;
	}
	for (i = 'A'; i <= 'Z'; i++) {
		LETTERS[i - 'A'] = i;
	}
	while (1) {
		printf("Enter the string: ");
		fgets(str, 250, stdin);
		if (!(str[248] == '\0' || str[248] == '\n')) {
			buffer = getchar();
			if (buffer != '\n') {
				while (buffer != '\n')			//buffercleaner
					scanf("%c", &buffer);
				printf("\nChecking an array for overflow...\n\nError! Please try again.\n\n");
			}
			else {
				printf("\nChecking an array for overflow...\n\nSuccessfully!\n\n");
				break;
			}
		}
		else {
			printf("\nChecking an array for overflow...\n\nSuccessfully!\n\n");
			break;
		}
	
	}
	for (i = 0; str[i] != '\n'; i++) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			for (j = 0; j <= 25; j++) {
				if (str[i] == letters[j] || str[i] == LETTERS[j])
					counter[j]++;
			}
			lenght++;
		}
	}
	printf("Result:\n");
	for (i = 0; i <= 25; i++) {
		if (i % 5 == 0)
			printf("\n%c + %c = %d, %.2f%c \t", LETTERS[i], letters[i], counter[i], counter[i] * 100 / lenght, pr);
		else printf("%c + %c = %d, %.2f%c\t", LETTERS[i], letters[i], counter[i], counter[i] * 100 / lenght, pr);
	}
	getchar();
	return 0;
}