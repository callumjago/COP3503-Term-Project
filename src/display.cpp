
#include "../include/display.h"
#include <iostream>
#include <unistd.h>

void Display::push_to_first_display(char temp[])
{
    write(fd, temp, sizeof("                                 "));
   // close(fd);

    /*Remove the FIFO */
    
    //unlink(myfifo);
    usleep(6000);
   // memset(&temp[0], 0, sizeof(100));
}
void Display::push_to_second_display(char temp[])
{
    write(fd, temp, sizeof("                                  "));

   // close(fd);

    /*Remove the FIFO */
    
    //unlink(myfifo);
    usleep(6000);
    //memset(&temp[0], 0, sizeof(100));
}
