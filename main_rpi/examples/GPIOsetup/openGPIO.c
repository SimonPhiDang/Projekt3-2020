#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int narg, char * argp[])
{
    size_t fd;
    int errsv = 0;
    char read_buf[2];

    printf("using file: /dev/orderCompleteGPIO\n");
    
    if((fd = open("/dev/orderCompleteGPIO", O_RDWR)) < 0) {
        errsv = errno;
        printf("ERROR: Error opening /dev/orderCompleteGPIO\n");
        return errsv;
    }


    printf("/dev/orderCompleteGPIO has been opened\n");

    read(fd, read_buf, sizeof(read_buf));
    printf("Reading from GPIO25: %s \n", read_buf);

    close(fd);
    
    return errsv;

}
