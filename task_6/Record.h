#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define STRING_MAX_SIZE 128

typedef struct Record {
	int id;
	char surname[STRING_MAX_SIZE];
	char faculty[STRING_MAX_SIZE];
	char group[STRING_MAX_SIZE];
} Record;

void input_record(Record* record) {
	printf("Enter ID: ");
	scanf("%d", &record->id);
	printf("Enter surname: ");
	scanf("%s", record->surname);
	printf("Enter faculty: ");
	scanf("%s", record->faculty);
	printf("Enter group: ");
	scanf("%s", record->group);
}

void save_table(Record table[], int size, const char* filename) {
	FILE* file = fopen(filename, "w");
	if (file) {
		for (int i = 0; i < size; i++) {
			fprintf(file, "%d %s %s %s\n", table[i].id, table[i].surname,
					table[i].faculty, table[i].group);
		}

		fclose(file);
	} else {
		printf("Error opening file %s for writing\n", filename);
	}
}

void load_table(Record table[], int* size, const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file) {
		while (fscanf(file, "%d %s %s %s", &table[*size].id, table[*size],
					table[*size].faculty, table[*size].group) != EOF) {
			(*size)++;
		}

		fclose(file);
	} else {
		printf("Error opening file %s for reading\n", filename);
	}
}

void print_record(Record* record) {
	printf("ID: %d\n", record->id);
	printf("Surname: %s\n", record->surname);
	printf("Faculty: %s\n", record->faculty);
	printf("Group: %s\n", record->group);
}

void print_table(Record table[], int size) {
	for (int i = 0; i < size; i++) {
		print_record(&table[i]);
		printf("\n");
	}
}

void edit_table_record(Record table[], int index) {
	Record record;
	input_record(&record);

	table[index] = record;
}

void delete_table_record(Record table[], int* size, int index) {
	for (int i = index; i < *size -1; i++) {
		table[i] = table[i + 1];
	}

	(*size)--;
}

int compare_records_by_id(const void* left, const void* right) {
	const Record* a = (const Record*)(left);
	const Record* b = (const Record*)(right);

	return a->id - b->id;
}

int compare_records_by_surname(const void* left, const void* right) {
	const Record* a = (const Record*)(left);
	const Record* b = (const Record*)(right);

	return strcmp(a->surname, b->surname);
}

int compare_records_by_faculty(const void* left, const void* right) {
	const Record* a = (const Record*)(left);
	const Record* b = (const Record*)(right);

	return strcmp(a->faculty, b->faculty);
}

int compare_records_by_group(const void* left, const void* right) {
	const Record* a = (const Record*)(left);
	const Record* b = (const Record*)(right);

	return strcmp(a->group, b->group);
}

void sort_table_by_id(Record table[], int size) {
	qsort(table, size, sizeof(Record), compare_records_by_id);
}

void sort_table_by_surname(Record table[], int size) {
	qsort(table, size, sizeof(Record), compare_records_by_surname);
}

void sort_table_by_faculty(Record table[], int size) {
	qsort(table, size, sizeof(Record), compare_records_by_faculty);
}

void sort_table_by_group(Record table[], int size) {
	qsort(table, size, sizeof(Record), compare_records_by_group);
}

int search_record_by_id(Record table[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (table[i].id == target) {
			return i;
		}
	}
	
	return -1;
}

int search_record_by_surname(Record table[], int size, const char* target) {
	for (int i = 0; i < size; i++) {
		if (strcmp(table[i].surname, target) == 0) {
			return i;
		}
	}

	return -1;
}

int search_record_by_faculty(Record table[], int size, const char* target) {
	for (int i = 0; i < size; i++) {
		if (strcmp(table[i].faculty, target) == 0) {
			return i;
		}
	}

	return -1;
}

int search_record_by_group(Record table[], int size, const char* target) {
	for (int i = 0; i < size; i++) {
		if (strcmp(table[i].group, target) == 0) {
			return i;
		}
	}

	return -1;
}

int search_closest_id(Record table[], int size, int target) {
	int min_distance = INT_MAX;
	int closest_index = -1;

	for (int i = 0; i < size; i++) {
		int distance = abs(table[i].id - target);

		if (distance == 0) {
			return i;
		}

		if (distance < min_distance) {
			min_distance = distance;
			closest_index = i;
		}
	}

	return closest_index;
}

int search_closest_surname(Record table[], int size, const char* target) {
	int min_distance = INT_MAX;
	int closest_index = -1;

	for (int i = 0; i < size; i++) {
		int distance = strcmp(table[i].surname, target);

		if (distance == 0) {
			return i;
		}

		if (abs(distance) < min_distance) {
			min_distance = abs(distance);
			closest_index = i;
		}
	}

	return closest_index;
}

int search_closest_faculty(Record table[], int size, const char* target) {
	int min_distance = INT_MAX;
	int closest_index = -1;

	for (int i = 0; i < size; i++) {
		int distance = strcmp(table[i].faculty, target);

		if (distance == 0) {
			return i;
		}

		if (abs(distance) < min_distance) {
			min_distance = abs(distance);
			closest_index = i;
		}
	}

	return closest_index;
}

int search_closest_group(Record table[], int size, const char* target) {
	int min_distance = INT_MAX;
	int closest_index = -1;

	for (int i = 0; i < size; i++) {
		int distance = strcmp(table[i].group, target);

		if (distance == 0) {
			return i;
		}

		if (abs(distance) < min_distance) {
			min_distance = abs(distance);
			closest_index = i;
		}
	}

	return closest_index;
}

#endif /* RECORD_H */
