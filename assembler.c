#include <stdio.h>
#include <string.h>

void printBinary(int n) {
	for (int i = 7; i >= 0; i--) {
		int bit = (n >> i) & 1;
		printf("%d", bit);
	}
	printf("\n");
}

int main() {
	FILE *mystring, *mybinary;
	mystring = fopen("fibonacci.asm", "r");
	mybinary = fopen("fibonacci.bin", "wb");

	char fptr[100];
	unsigned char bins[100];
	int i = 0;

	if (mystring == NULL) {
		printf("Could not open the file\n");
		return 1;
	}
	if (mybinary == NULL) {
		printf("Could not create the output file\n");
		fclose(mystring);
		return 1;
	}
	printf("\nFunction\n");
	while (fgets(fptr, 100, mystring)) {
		printf("%d: %s",i+1, fptr);
		if (strcmp(fptr, "RA=RA+RB\n") == 0)
			bins[i] = 0b00000000;
		else if (strcmp(fptr, "RB=RA+RB\n") == 0)
			bins[i] = 0b00010000;
		else if (strcmp(fptr, "RA=RA-RB\n") == 0)
			bins[i] = 0b00000100;
		else if (strcmp(fptr, "RB=RA-RB\n") == 0)
			bins[i] = 0b00010100;
		else if (strcmp(fptr, "R0=RA\n") == 0)
			bins[i] = 0b00100000;
		else if (fptr[3] >= '0' && fptr[3] <= '9' && fptr[2] == '=' && fptr[4] == '\n') {
			if (strncmp(fptr, "RA=", 3) == 0)
				bins[i] = 0b00001000 + (fptr[3] - '0');
			else if (strncmp(fptr, "RB=", 3) == 0)
				bins[i] = 0b00011000 + (fptr[3] - '0');
			else if (strncmp(fptr, "JC=", 3) == 0)
				bins[i] = 0b01110000 + (fptr[3] - '0');
		} else if (fptr[2] >= '0' && fptr[2] <= '9' && fptr[1] == '=' && fptr[3] == '\n') {
			bins[i] = 0b10110000 + (fptr[2] - '0');
		} else {
			printf("Invalid operation\n");
			continue;
		}
		i++;
	}
	fclose(mystring);

	fwrite(bins, sizeof(unsigned char), i, mybinary);
	fclose(mybinary);

	printf("\nBinary values\n");
	for (int j = 0; j < i; j++) {
		printf("%d: ", j + 1);
		int n = bins[j];
		for (int k = 7; k >= 0; k--) {
			int bits = (bins[j] >> k) & 1;
			printf("%d", bits);
		}
		printf("\n");
	}

	return 0;
}
