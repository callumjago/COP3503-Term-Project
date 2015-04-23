#ifndef DISPLAY_H
#define DISPLAY_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Display {

    public:
    	Display(){
            int pass;

    		if (pass == 1)
    		{
    			this->myfifo = "/tmp/myfifo_one";
    			mkfifo(myfifo, 0666);
    		}
    		if (pass == 2)
    		{
    			this->myfifo = "/tmp/myfifo_two";
    			mkfifo(myfifo, 1000);
    		}

    /*Create the FIFO (named pipe) */
    		

    /*Write "Hi" to the FIFO */
    		this->fd = open(myfifo, O_WRONLY);
    	}

        void push_to_first_display(char temp[]);
        void push_to_second_display(char temp[]);

    private:

    	int fd;
    	char * myfifo;


};

#endif

