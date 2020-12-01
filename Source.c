#include <stdio.h>

int main() {
	unsigned char str[255], vowels[] = { 'A','a','E','e','I','i','O','o','U','u','Y','y' };
	printf("Enter the string: ");
	fgets(str, 255, stdin);
	int i = 0, j = 0, lenght = 0, counter[6] = { 0 };
	float procent = 0, symbols = 0;
	while (str[i] != '\0') {
		lenght++;
		if(!(str[i]>='A' && str[i]<='Z'|| str[i]>='a' && str[i]<='z'))
			symbols++;
		i++;
	}
	for (i = 0; i <= lenght; i++) {
		for (j = 0; j <= 11; j += 2) {
			if ((str[i] == vowels[j]) || (str[i] == vowels[j + 1])) {
				counter[j / 2]++;
				break;
			}
		}
	}
	for (i = 0; i <= 11; i += 2) {
		if (counter[i / 2] == 0)
			printf("No symbols %c and %c, 0% \n", vowels[i], vowels[i + 1]);
		else {
			procent = counter[i / 2]/(lenght - symbols);
			printf("%c + %c = %d ,%2.f %\n", vowels[i], vowels[i + 1], counter[i / 2], procent*100);
		}
	}
	getchar();
	return 0;
}