#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF 1024

int main()
{
    int fd1,fd2,r,w;
    char buf[BUF];
    fd1 = open("source.txt",O_RDONLY);
    if(fd1 == -1)
    {
        perror("error opening file1\n");
        exit(EXIT_FAILURE);
    }
    
    r=read(fd1,&buf,BUF);
    if(r==-1)
    {
        perror("error opening file2\n");
        exit(EXIT_FAILURE);
    }
    

fd2=open("destination.txt",O_WRONLY|O_CREAT,S_IRWXG|S_IRUSR|S_IWUSR|S_IXOTH);
 if(fd2==-1)
    {
        perror("Error 3\n");
        exit(EXIT_FAILURE);
    }
    w=write(fd2,&buf,r);
    if(w==-1)
    {
         perror("error 4\n");
        exit(EXIT_FAILURE);
    }
    close(fd1);
    close(fd2);
    return 0;
}