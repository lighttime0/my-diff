#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILENAME_MAXLEN 256
#define LINE_MAXLEN 256


int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("usage: \n");
		printf("\t my_diff src1 src2\n");
		return 1;
	}

	FILE *src_file_1 = fopen(argv[1], "r");
	if (src_file_1 == NULL) {
		printf("Error: Can't open %s\n!", argv[1]);
		return 2;
	}

	FILE *src_file_2 = fopen(argv[2], "r");
	if (src_file_2 == NULL) {
		printf("Error: Can't open %s\n!", argv[2]);
		return 2;
	}

	char diff_filename[FILENAME_MAXLEN] = "diff_";
	strcat(diff_filename, argv[1]);
	strcat(diff_filename, "-");
	strcat(diff_filename, argv[2]);
	FILE *diff = fopen(diff_filename, "w+");

	char buffer[LINE_MAXLEN];
	while (fgets(buffer, LINE_MAXLEN, src_file_1) != NULL)
		printf("%s",buffer);
	printf("\n");

	fclose(src_file_1);
	fclose(src_file_2);
	fclose(diff);

	return 0;
}