#include <stdio.h> 
int main() {
	unsigned char str[255] = "", buffer = 0, letters[26] = "", LETTERS[26] = "";
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
		fgets(str, 255, stdin);
		if (!(str[253] == '\0' || str[253] == '\n')) {
			buffer = getchar();
			if (buffer != '\n') {
				while (buffer != '\n')			//buffercleaner
					scanf("%c", &buffer);
				printf("Checking an array for overflow...\n\nError! Please try again.\n\n");
			}
			else {
				printf("Checking an array for overflow...\n\nSuccessfully!\n\n");
				break;
			}
		}
		else {
			printf("Checking an array for overflow...\n\nSuccessfully!\n\n");
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
	printf("LENGTH = %.0f\n", lenght);
	for (i = 0; i <= 25; i++) {
		if (i % 5 == 0)
			printf("\n%c + %c = %d, %.2f \t", LETTERS[i], letters[i], counter[i], counter[i] * 100 / lenght);
		else printf("%c + %c = %d, %.2f \t", LETTERS[i], letters[i], counter[i], counter[i] * 100 / lenght);
	}
	getchar();
	return 0;
}