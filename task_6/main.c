#include <stdio.h>
#include <stdlib.h>
#include "Record.h"

#define MAX_RECORDS 100
#define DEFAULT_FILENAME "lmao.txt"

int main() {
	Record table[MAX_RECORDS];
	int size = 0;

	int choice = -1;
	int index = -1;
	int input = -1;
	char buffer[256];

	while (true) {
		printf("\n1. Input record\n2. Save to file\n3. Load from file\n");
		printf("4. Display table\n5. Edit record\n6. Remove record\n");
		printf("7. Sort by id\n8. Sort by surname\n9. Sort by faculty\n");
		printf("10. Sort by group\n11. Search by id\n12. Search by surname\n");
		printf("13. Search by faculty\n14. Search by group\n15. Calculate\n");
		printf("0. - Exit\n");

		printf("> ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				input_record(&table[size]);
				size += 1;
				break;
			case 2:
				if (size == 0) {
					printf("List is empty\n");
					break;
				}

				save_table(table, size, DEFAULT_FILENAME);
				break;
			case 3:
				load_table(table, &size, DEFAULT_FILENAME);
				break;
			case 4:
				print_table(table, size);
				break;
			case 5:
				printf("Enter index: ");
				scanf("%d", &index);

				if (index < 0 || index >= size) {
					printf("Bad index\n");
					break;
				}

				edit_table_record(table, index);
				break;
			case 6:
				printf("Enter index: ");
				scanf("%d", &index);

				if (index < 0 || index >= size) {
					printf("Bad index\n");
					break;
				}

				delete_table_record(table, &size, index);
				break;
			case 7:
				sort_table_by_id(table, size);
				break;
			case 8:
				sort_table_by_surname(table, size);
				break;
			case 9:
				sort_table_by_faculty(table, size);
				break;
			case 10:
				sort_table_by_group(table, size);
				break;
			case 11:
				printf("Enter ID: ");
				scanf("%d", &input);
				index = search_record_by_id(table, size, input);
				if (index != -1) {
					print_record(&table[index]);
					break;
				}

				index = search_closest_id(table, size, input);
				if (index != -1) {
					print_record(&table[index]);
				}

				break;
			case 12:
				printf("Enter surname: ");
				scanf("%s", buffer);
				index = search_record_by_surname(table, size, buffer);
				if (index != -1) {
					print_record(&table[index]);
					break;
				}

				index = search_closest_surname(table, size, buffer);
				if (index != -1) {
					print_record(&table[index]);
				}

				break;
			case 13:
				printf("Enter faculty: ");
				scanf("%s", buffer);
				index = search_record_by_faculty(table, size, buffer);
				if (index != -1) {
					print_record(&table[index]);
					break;
				}

				index = search_closest_faculty(table, size, buffer);
				if (index != -1) {
					print_record(&table[index]);
				}

				break;
			case 14:
				printf("Enter group: ");
				scanf("%s", buffer);
				index = search_record_by_group(table, size, buffer);
				if (index != -1) {
					print_record(&table[index]);
					break;
				}

				index = search_closest_group(table, size, buffer);
				if (index != -1) {
					print_record(&table[index]);
				}

				break;
			case 15:
				printf("Enter faculty: ");
				scanf("%s", buffer);
				calculate(table, size, buffer);

				break;
			case 0:
				exit(0);
		}
	}
}
