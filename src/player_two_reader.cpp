#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

#define MAX_BUF 1024

int main()
{
	int fd;
    char * myfifo = "/tmp/myfifo_two";
    char buf[MAX_BUF];
    fd = open(myfifo, O_RDONLY);
    int number;

	while(1){
	    /* Open, read, and display the message from the FIFO */
		number = read(fd, buf, 2*MAX_BUF);
		if (number > 0)
		{
			std::cout << buf << " ";
			std::cout.flush();
			memset(&buf[0], 0, sizeof(MAX_BUF));
			fd = open(myfifo, O_RDONLY);
		}
		
	}
    

}