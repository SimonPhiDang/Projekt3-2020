#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int narg, char * argp[])
{
    size_t fd;
    int errsv = 0;
    char read_buf[2];
    char write_buf[2];

    printf("using file: %s\n", argp[1]);
    
    if((fd = open(argp[1], O_RDWR)) < 0) {
        errsv = errno;
        printf("ERROR: Error opening %s\n", argp[1]);
        return errsv;
    }


    printf("%s has been opened\n", argp[1]);

    read(fd, read_buf, sizeof(read_buf));
    printf("Reading from LED3: %s \n", read_buf);
    write(fd, argp[2] , 2);
    printf("Writing to LED3: %s \n", argp[2]);
    read(fd, read_buf, sizeof(read_buf));
    printf("Reading from LED3: %s \n", read_buf);
    
    close(fd);
    
    printf("%s has been closed\n", argp[1]);
    
    return errsv;

}
