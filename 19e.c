/*
============================================================================
Name : 19e.c
Author : Chandanala Vishwateja
Description : Create a FIFO file by
d. mkfifo library function
Date: 15th Oct, 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int result = mkfifo("f1.fifo",S_IRWXU);
	if(result < 0)
	{
		perror("mkfifo");
		exit(1);
	}
	return 0;
}
