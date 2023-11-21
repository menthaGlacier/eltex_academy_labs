#include <stdlib.h>
#include <stdio.h>

//#include "user_data.h"

static const char* DEFAULT_FILENAME = "/etc/passwd";
static const int BUFFER_SIZE = 2048;
static const int USERS_AMOUNT_MAX = 100;

FILE* open_file(const char* filename, const char* mode) {
	FILE* file = fopen(filename, mode);

	if (!file) {
		printf("Error occured while trying to open %s", filename);
		exit(EXIT_FAILURE);
	}

	return file;
}

int main(int argc, char* argv[]) {
	FILE* passwd_file;
	char user_data_lines[USERS_AMOUNT_MAX][BUFFER_SIZE];
	
	passwd_file = open_file(DEFAULT_FILENAME, "r");
	
	int i = 0;
	while (fgets(user_data_lines[i], BUFFER_SIZE, passwd_file)) {
		i += 1;
	}

	for (int j = 0; j < i; j++) {
		printf("%s", user_data_lines[j]);
	}

	fclose(passwd_file);

	return 0;
}
