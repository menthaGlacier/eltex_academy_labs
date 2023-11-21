#include "helpers.h"

FILE* open_file(const char* filename, const char* mode) {
	FILE* file = fopen(filename, mode);

	if (!file) {
		printf("Error occured while trying to open %s", filename);
		exit(EXIT_FAILURE);
	}

	return file;
}

char* duplicate_string(const char* src) {
	char* result = (char*)(malloc(strlen(src) + 1));
	if (!result) {
		return NULL;
	}

	strcpy(result, src);
	return result;
}

char* delimit_string(char** src, const char* delimiter) {
	char* begin;
	char* end;

	begin = *src;
	if (!begin) {
		return NULL;
	}

	end = begin + strcspn(begin, delimiter);

	if (end) {
		*end++ = '\0';
		*src = end;
	}
	
	src = NULL;

	return begin;
}
