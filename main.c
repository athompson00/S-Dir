#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main (int argc, char *argv[]) {
  printf("Enter Directory Path: ");
  char directory[1000] = ".";

	if (argc == 1) {
		fgets(directory, sizeof(directory), stdin);
		directory[strlen(directory) - 1] = '\0';
	} else {
		strcpy(directory, argv[1]);
	}

  struct DIR *displaying = opendir(directory);

	long s = 0;

	if (displaying < s) {
		printf("Directory Could Not Be Opened: %s\n", strerror(errno));
		return 0;
	}

	struct dirent *fd;

	printf("------- Examining Directory: [%s] -------\n", directory);

	while ((fd = readdir(displaying)) != NULL) {

		int check = fd->d_type;

		if (check == 4) {
			printf("[DIRECTORY] ");
		}	else {
			printf("[FILE] ");
		}

		struct stat stats;
		stat(fd->d_name, &stats);
		s += stats.st_size;
		printf(": %s\n", fd->d_name);
	}
	printf("TOTAL DIRECTORY SIZE: %ld bytes\n", s);
}
