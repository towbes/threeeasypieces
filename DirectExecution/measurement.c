#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int main(void){
    
    int i;
    struct timeval tv;

    time_t curtime;

    for (i = 0; i < 10; i++) {
        gettimeofday(&tv, NULL);
        curtime=tv.tv_usec
        printf("System time is: %f\n", q);
    }

    return 0;
}
