#include "user_data.h"

void print_user_data(user_data* user) {
	printf("username:\t\t %s\n", user->username);
	printf("password:\t\t %s\n", user->password);
	printf("UID:\t\t %s\n", user->uid);
	printf("GID:\t\t %s\n", user->gid);
	printf("GECOS:\t\t %s\n", user->gecos);
	printf("user directory:\t\t %s\n", user->user_directory);
	printf("shell:\t\t %s\n", user->user_shell);
}


user_data get_user_data_from_string(const char* string, int buffer_size) {
	user_data user;
	return user_data;
}
