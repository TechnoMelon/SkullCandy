#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
int fd1[2], nbytes=1,fd2[2],a=0;
pid_t pid;
char readbuffer[80],string[80];
char ch='a',ch1='\n';
FILE *ptr;
pipe(fd1);
pipe(fd2);
if((pid = fork()) == -1)
{
perror("fork");
exit(1);
}
if((pid =fork())== 0)
{
close(fd1[1]);
read(fd1[0], readbuffer, sizeof(readbuffer));
ptr=fopen(readbuffer,"r");
close(fd1[0]);
close(fd2[0]);
while(a!=-1)
{
a=fscanf(ptr,"%c",&ch);
write(fd2[1], &ch, sizeof(ch));
}
close(fd2[1]);
exit(0);
}
else
{
close(fd1[0]);
printf("!!!!!!!Parent process is here!!!!!!!!\n" );
scanf("%s",string);
write(fd1[1], string, (strlen(string)+1));
close(fd1[1]);
close(fd2[1]);
while(nbytes!=0)
{
printf("%c",ch1);
nbytes = read(fd2[0], &ch1, sizeof(ch1));
}
close(fd2[0]);
}
return(0);
}
