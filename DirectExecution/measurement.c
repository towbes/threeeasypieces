#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h> // Removes error about implicit declaration for read() in C99
#include <fcntl.h> // Removes error about implicit declaration for open()

int main(void){
    
    int i; //Used to count counting loop
    int n; //used to count READ 0 bytes
    struct timeval btv; // Store start time
    struct timeval atv; // Store after time

    time_t curtime;
    time_t beforetime;
    time_t timeused;

    //Open a file for reading
    int fd = open("readfile.txt", O_RDONLY);

    for (i = 0; i < 10; i++) {
        gettimeofday(&btv, NULL);
        beforetime=btv.tv_sec + btv.tv_usec;
        //Perform 1000 null byte read to test cost of System call
        for (n = 0; n < 10000; n++) {
            //Read 0 bytes from readfile.txt
            read(fd,NULL,0);
        }
        //Get and print the current time in seconds + microseconds
        gettimeofday(&atv, NULL);
        curtime=atv.tv_sec + atv.tv_usec;
        //Calculate time cost
        timeused = curtime - beforetime;
        printf("Time used: %ld microseconds\n", timeused);
    }


    return 0;
}
