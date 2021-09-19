#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
	FILE *fptr;
	struct stat fileInfo;
	
	if (stat("test.bin", &fileInfo) != 0) {
		fptr = fopen("test.bin", "wb");
	
		for (int i = 0; i < 5; i++) {
			int n = i * i;
			fwrite(&n, sizeof(int), 1, fptr);
		}
		fclose(fptr);
	} else {
		fptr = fopen("test.bin", "rb");

		int size = fileInfo.st_size / sizeof(int);
		for (int i = 0; i < size; i++) {
			int n = -1;
			fread(&n, sizeof(int), 1, fptr);
			printf("%d\n", n);
		}
	}
	
	return (0);
}
