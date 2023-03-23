/*Implementation of CAT command*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argv,char *argc[])
{
	int ret,lret1,lret2,fd,i;
	char *buf;
	if(argv>1)
	{
		for(i=1;i<argv;i++)
		{
			fd=0;
			fd=open(argc[i],O_RDONLY);
			if(fd<0)
			{
				printf("cat: %s: No such file or directory\n",argc[i]);
				continue;
			}
			lret1=lseek(fd,0,SEEK_END);
			if(lret1<0)
			{
				printf("Failed to access the file\n");
				exit(1);
			}
			buf=(char *)malloc(lret1*sizeof(char));
			if(buf==NULL)
			{
				printf("Failed to allocate the memory in the heap\n");
				exit(2);
			}
			lret2=lseek(fd,0,SEEK_SET);
			if(lret2<0)
			{
				printf("Failed to access the file\n");
				exit(1);
			}
			ret=read(fd,buf,lret1);
			if(ret<0)
			{
				printf("Failed to read the file\n");
				exit(1);
			}
			printf("%s",buf);
			free(buf);
			close(fd);
		}
	}
	else
		while(1);
}
