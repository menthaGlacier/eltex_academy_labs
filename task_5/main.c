#include "pch.h"
#include "helpers.h"
#include "user_data.h"

static const char* DEFAULT_FILENAME = "/etc/passwd";
static const int BUFFER_SIZE = 2048;
static const int USERS_AMOUNT_MAX = 100;

int main(int argc, char* argv[]) {
	FILE* passwd_file;
	user_data users[USERS_AMOUNT_MAX];

	passwd_file = open_file(DEFAULT_FILENAME, "r");
	
	int users_count = 0;
	char user_string[BUFFER_SIZE];
	while (fgets(user_string, BUFFER_SIZE, passwd_file)) {
		users[users_count] = get_user_data_from_string(user_string);
		users_count += 1;
	}

	for (int i = 0; i < users_count; i++) {
		print_user_data(&users[i]);
		printf("\n");
	}

	fclose(passwd_file);

	return 0;
}
