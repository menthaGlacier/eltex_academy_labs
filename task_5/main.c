#include "pch.h"
#include "helpers.h"
#include "user_data.h"

static const char* DEFAULT_FILENAME = "/etc/passwd";
static const char* DEFAULT_OUTPUT = "passwd";
static const int BUFFER_SIZE = 2048;
static const int USERS_AMOUNT_MAX = 100;

void help_message(const char* binary_name) {
	printf("Program usage:\n");
	printf("\t%s --all : display data of all users\n", binary_name);
	printf("\t%s <login> : display data of login\n", binary_name);
	printf("\t%s <login> <new_login> : change login\n", binary_name);
}

user_data* get_user_data_by_login(user_data users[], int users_amount,
		const char* login) {
	for (int i = 0; i < users_amount; i++) {
		if (strcmp(users[i].username, login) == 0) {
			return &users[i];
		}
	}

	puts("No user with such login was found");
	return NULL;
}

void write_user_data_to_file(user_data users[], int users_amount) {
	FILE* output_file = open_file(DEFAULT_OUTPUT, "w");

	for (int i = 0; i < users_amount; i++) {
		fprintf(output_file, "%s\n", get_string_from_user_data(&users[i]));
	}

	fclose(output_file);
}

int main(int argc, char* argv[]) {
	FILE* passwd_file;
	user_data users[USERS_AMOUNT_MAX];

	if (argc <= 1 || argc > 3) {
		help_message(argv[0]);
		exit(EXIT_FAILURE);
	}

	passwd_file = open_file(DEFAULT_FILENAME, "r");
	
	int users_count = 0;
	char user_string[BUFFER_SIZE];
	while (fgets(user_string, BUFFER_SIZE, passwd_file)) {
		users[users_count] = get_user_data_from_string(user_string);
		users_count += 1;
	}

	if (argc == 2) {
		if (strcmp(argv[1], "--all") == 0) {
			for (int i = 0; i < users_count; i++) {
				print_user_data(&users[i]);
				printf("\n");
			}
		}

		print_user_data(get_user_data_by_login(users, users_count, argv[1]));
	} else if (argc == 3) {
		user_data* user = get_user_data_by_login(users, users_count, argv[1]);
		
		if (!user) {
			exit(EXIT_FAILURE);
		}

		free(user->username);
		user->username = duplicate_string(argv[2]);
		write_user_data_to_file(users, users_count);
	}

	for (int i = 0; i < users_count; i++) {
		free_user_data(&users[i]);
	}

	fclose(passwd_file);
	return 0;
}
