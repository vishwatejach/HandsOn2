#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
	int fd[2];
	char buffer[100];
	pid_t p;
	pipe(fd);
	p = fork();
	if(p>0)
	{
		write(1,"This is Parent\n",sizeof("This is Parent\n"));
		write(fd[1],"Hey Child!\nI'm Your Parent!\n",sizeof("Hey Child!\nI'm Your Parent!\n"));
	}
	else
	{
		write(1,"This is Child\n",sizeof("This is Child\n"));
		int n = read(fd[0],buffer,sizeof(buffer));
		write(1,buffer,n);
	}
}
