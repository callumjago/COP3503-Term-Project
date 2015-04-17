
#include "../include/display.h"
#include <iostream>
#include <unistd.h>

int Display::push_to_display(char temp[])
{
    int fd;
    char * myfifo = "/tmp/myfifo";

    /*Create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /*Write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, temp, sizeof("aaaaaaa"));
    //close(fd);

    /*Remove the FIFO */
    
    //unlink(myfifo);
    usleep(5000);
    return 0;
}
