#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /*
        Accept two arguments 
        1. path to the file to be written
        2. content to be written to the file    
    
    */

    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file_path> <content>", argv[0]);
        return EXIT_FAILURE;
    }

    const char *file_path = argv[1];
    const char *content = argv[2];

    /* Open syslog using LOG_USER facility*/
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to open file %s for writing: %s", file_path, strerror(errno));
        closelog();
        return EXIT_FAILURE;
    }

    if (fputs(content, file) == EOF) {
        syslog(LOG_ERR, "Failed to write to file %s: %s", file_path, strerror(errno));
        fclose(file);
        closelog();
        return EXIT_FAILURE;
    }
    fclose(file);
    closelog();
    return 0;
}


