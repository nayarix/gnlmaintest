#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		get_next_line(int const fd, char **line);

int		main(int argc, char **argv)
{
	int		ret;
	int		fd1;
	int		fd2;
	char	*line;

	if (argc == 1)
	{
		printf("File name missing.\n");
		return (0);
	}
	line = NULL;
	if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 != -1)
			printf("\n======================*** File \"%s\" opened ***=======================\n\n", argv[1]);
		else
			printf("Cannot Open file %s\n", argv[1]);
		fd2 = open(argv[2], O_RDONLY);
		if (fd2 != -1)
			printf("\n======================*** File \"%s\" opened ***=======================\n\n", argv[2]);
		else
			printf("Cannot Open file %s\n", argv[2]);
		ret = get_next_line(fd1, &line);
		if (ret == 1)
			printf("line1 : %s\n", line);
		ret = get_next_line(fd2, &line);
		if (ret == 1)
			printf("line1 : %s\n", line);
		ret = get_next_line(fd1, &line);
		if (ret == 1)
			printf("line2 : %s\n", line);
		ret = get_next_line(fd2, &line);
		if (ret == 1)
			printf("line2 : %s\n", line);
		ret = get_next_line(fd1, &line);
		if (ret == 1)
			printf("line3 : %s\n", line);
		ret = get_next_line(fd2, &line);
		if (ret == 1)
			printf("line3 : %s\n", line);
		close(fd1);
		if (!close(fd1))
				printf("\n======================*** File %s closed ***=======================\n", argv[1]);
			else
				printf("\n Error Closing File\n");
		if (!close(fd2))
				printf("\n======================*** File %s closed ***=======================\n", argv[2]);
			else
				printf("\n Error Closing File\n");
	return (0);	
}

