#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd;
	char str[20];

	fd = open("/dev/node",O_RDWR);
	if(fd<0)
	{
		printf("File open error,fd : %d\n",fd);
		return -1;
	}

	printf("Enter string : ");
	gets(str);
	
	printf("str : %s\n",str);
	write(fd,str,strlen(str));

	close(fd);
return 0;
}
