
#include "../include/display.h"
#include <iostream>
#include <unistd.h>

void Display::push_to_first_display(char temp[])
{
    int fd;
    char * myfifo = "/tmp/myfifo_one";

    /*Create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /*Write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, temp, sizeof("                    "));
    //close(fd);

    /*Remove the FIFO */
    
    //unlink(myfifo);
    usleep(4000);
}
void Display::push_to_second_display(char temp[])
{
    int fd;
    char * myfifo = "/tmp/myfifo_two";

    /*Create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /*Write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, temp, sizeof("                                  "));

    //close(fd);

    /*Remove the FIFO */
    
    //unlink(myfifo);
    usleep(4000);
}
