#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *command_line;
    char *command = "curl ";
    char *redirection = " > ";
    int result;

    if (argc < 3) {
        printf("ERROR: please use syntax:\n   url2file URL file");
        return 0;
    }

    command_line = malloc(strlen(command) + strlen(argv[1]) + strlen(redirection) + strlen(argv[2]) + 1);
    sprintf(command_line, "%s%s%s%s", command, argv[1], redirection, argv[2]);

    if (command_line == NULL) {
        printf("ERROR: insufficient memory!");
        return 0;
    }

    result = system(command_line);
    free(command_line);

    if (result != 0) {
        printf("ERROR: download failed with code %i!", result);
    } else {
        printf("Done!");
    }

    return 0;
}
