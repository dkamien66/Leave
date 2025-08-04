#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * When this executable program is run with a file, it removes all other files except the current executable, the c file, and the given file.
 */
int main(int argc, char *argv[])
{
	// check arg count
	if (argc != 2)
	{
		printf("Filename to keep is needed!");
		exit(EXIT_FAILURE);
	}

	// Get the other file names by utilizing system call and redirection
	int result = system("ls > output.txt");
	if (result == -1)
	{
		printf("Error with ls system call!");
		exit(EXIT_FAILURE);
	}

	// Save the given filename for future use
	char file_to_keep[30] = ""; // Initialize array, or else it will be garbage values
	strcat(file_to_keep, argv[1]);
	strcat(file_to_keep, "\n");

	// Open output file and set up reading
	FILE *ifp = fopen("output.txt", "r");
	if (ifp == NULL)
	{
		printf("Couldn't open output.txt");
		exit(EXIT_FAILURE);
	}

	char buffer[30] = "";

	while (fgets(buffer, sizeof(buffer), ifp) != NULL)
	{
		// if filename is the one to keep, the source code, or the executable, don't remove
		if (strcmp(file_to_keep, buffer) == 0 || strcmp("leave\n", buffer) == 0 || strcmp("leave.c\n", buffer) == 0) {
			continue;
		} else {
			// Create system call to remove file
			char command[30] = "rm ";
			strcat(command, buffer);
			int removal = system(command);
			if (removal == -1) {
				printf("Error with removing file!");
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(ifp);
	return 0;
}
