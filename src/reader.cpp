#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

#define MAX_BUF 10000

int main()
{

	int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

	while(1){

	    /* open, read, and display the message from the FIFO */
	    fd = open(myfifo, O_RDONLY);

		if (fd > 0)
		{
			read(fd, buf, MAX_BUF);
			std::cout << buf << " ";
			std::cout.flush();
		}
	}
    

}