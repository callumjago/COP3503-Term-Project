#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

#define MAX_BUF 50

int main()
{
	int fd;
    char * myfifo = "/tmp/myfifo_one";
    char buf[MAX_BUF];
    fd = open(myfifo, O_RDONLY);

	while(1){
	    /* Open, read, and display the message from the FIFO */
		read(fd, buf, MAX_BUF);
		std::cout << buf << " ";
		std::cout.flush();

	}
    

}