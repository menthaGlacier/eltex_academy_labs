#include "user_data.h"

void print_user_data(user_data* user) {
	printf("username: %s\n", user->username);
	printf("password: %s\n", user->password);
	printf("UID: %d\n", user->uid);
	printf("GID: %d\n", user->gid);
	printf("GECOS: %s\n", user->gecos);
	printf("user directory: %s\n", user->user_directory);
	printf("shell: %s\n", user->user_shell);
}

user_data get_user_data_from_string(const char* string) {
	user_data user;
	char* string_copy = duplicate_string(string);

	user.username = duplicate_string(delimit_string(&string_copy, ":"));
	user.password = duplicate_string(delimit_string(&string_copy, ":"));
	user.uid = strtol(duplicate_string(delimit_string(&string_copy, ":")), NULL, 10);
	user.gid = strtol(duplicate_string(delimit_string(&string_copy, ":")), NULL, 10);
	user.gecos = duplicate_string(delimit_string(&string_copy, ":"));
	user.user_directory = duplicate_string(delimit_string(&string_copy, ":"));
	user.user_shell = duplicate_string(delimit_string(&string_copy, ":\n"));

	return user;
}
