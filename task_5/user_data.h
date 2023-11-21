#ifndef USER_DATA_H
#define USER_DATA_H

#include <stdio.h>
#include <string.h>

typedef struct user_data {
	char* username;
	char* password;
	int uid;
	int gid;
	char* gecos;
	char* user_directory;
	char* user_shell;
} user_data;

void print_user_data(user_data* user);

user_data get_user_data_from_string(const char* string, int buffer_size);

#endif /* USER_DATA_H */
