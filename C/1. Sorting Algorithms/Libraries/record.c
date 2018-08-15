#include "../Headers/record.h"
#include "../Headers/arraylist.h"

/*
 * Const from max string length
 */
#define STRING_LENGTH 50

/*
 * Const for max read char length
 */
#define CHARS_LENGTH 20

/*
 * Function: create_record
 * -------------------------
 * create_record implementation.
 * Allocates a new _record struct and all fields inside it. Fields are
 * specified by str parameter, and are comma separated.
 *
 */
Record create_record(char* str){
	char* token;

	token = strtok(str, ",");
	int id = atoi(token);

	token = strtok(NULL, ",");
	char* field1 = (char*)malloc(sizeof(char)*CHARS_LENGTH);
	strcpy(field1, token);

	token = strtok(NULL, ",");
	int field3 = atoi(token);

	token = strtok(NULL, "\0");
	float field2 = atof(token);

	Record r;
	r = (Record)malloc(sizeof(struct _record));

	r->field1 = (char*)malloc(sizeof(char)*CHARS_LENGTH);
	r->id = id;
	strcpy(r->field1, field1);

	r->field2 = field2;
	r->field3 = field3;

	free(field1);
	return r;
}

/* Function to read from file, allocate Arraylist and add record to Arraylist */
/*
 * Function: read_file
 * -------------------------
 * read_file implementation.
 * Allocates a new _arraylist struct and the array inside it which is as big as
 * specified size. Reads from file records.csv and adds _record struct to
 * _arraylist with information from file.
 *
 */
void** read_file(int l){
	FILE* fp = fopen("../../../records.csv", "r");
	char c;
	char tmp[STRING_LENGTH];
	Arraylist a = new_arraylist(l);

	int i = 0;
	while(fscanf(fp, "%c", &c) > 0){
		if(c == '\n'){
			tmp[i] = '\0';
			insert_arraylist((void*)(create_record(tmp)), a);
			i = 0;
		}
		else{
			tmp[i] = c;
			i++;
		}
	}

	fclose(fp);
	return (void*)a;
}
