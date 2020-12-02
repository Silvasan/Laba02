#include <stdio.h>

int main() {
	unsigned char str[250] = "", vowels[] = { 'A','a','E','e','I','i','O','o','U','u','Y','y' }, buffer = 0, pr='%';
	int i = 0, j = 0, counter[6] = { 0 };
	float procent = 0, lenght = 0;
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
			for (j = 0; j <= 11; j += 2) {
						if ((str[i] == vowels[j]) || (str[i] == vowels[j + 1])) {
							counter[j / 2]++;
							break;
						}
			}
			lenght++;
		}
	}
	printf("Result:\n");
	for (i = 0; i <= 11; i += 2) {
		if (counter[i / 2] == 0)
			printf("No symbols %c and %c, 0%c\n", vowels[i], vowels[i + 1], pr);
		else {
			procent = counter[i / 2]*100/lenght;
			printf("%c + %c = %d, %2.f%c\n", vowels[i], vowels[i + 1], counter[i / 2], procent, pr);
		}
	}
	getchar();
	return 0;
}
