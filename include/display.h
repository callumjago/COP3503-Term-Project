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
        void push_to_first_display(char temp[]);
        void push_to_second_display(char temp[]);

    private:

};

#endif

