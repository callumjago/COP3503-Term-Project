
#include "../include/display.h"
#include <iostream>

int Display::push_to_display(char temp[])
{
    int fd;
    char * myfifo = "/tmp/myfifo";

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, temp, sizeof("aaaaaaa"));
    //close(fd);

    /* remove the FIFO */
    //unlink(myfifo);

    return 0;
}
