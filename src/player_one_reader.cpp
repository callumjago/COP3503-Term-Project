#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

#define MAX_BUF 10000

int main()
{
	int fd;
    char * myfifo = "/tmp/myfifo_one";
    char buf[MAX_BUF];

	while(1){
	    /* Open, read, and display the message from the FIFO */
	    fd = open(myfifo, O_RDONLY);
		read(fd, buf, MAX_BUF);
		std::cout << buf << " ";
		std::cout.flush();
	}
    

}