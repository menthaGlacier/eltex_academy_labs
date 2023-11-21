#ifndef HELPERS_H
#define HELPERS_H

#include "pch.h"

FILE* open_file(const char* filename, const char* mode);
char* duplicate_string(const char* src);
char* delimit_string(char** src, const char* delimiter);

#endif /* HELPERS_H */
