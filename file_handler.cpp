#include "file_handler.h"

char* read_whole_file(FILE* f) {
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	assert(size > 0);
	fseek(f, 0, SEEK_SET);

	char* buff = (char*) malloc(size+1);
	int i = 0;
	u32 c;
	while ( ( c = fgetc(f) ) != EOF )
		buff[i++] = c;
	buff[i] = '\0';

	return buff;
}
