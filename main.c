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
	int		fd;
	int		i;
	char	*line;

	if (argc == 1)
	{
		printf("File name missing.\n");
		return (0);
	}
	i = 1;
	line = NULL;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{	
			printf("\n======================*** File %s opened ***=======================\n\n", argv[i]);
			
			if ((ret = get_next_line(fd, &line)) == -1)
			{
				printf("Cannot read from file descriptor %d\n", fd);
				exit(EXIT_FAILURE);
			}
			printf("%d | %s\n", ret, *line);
			free(line);
			line = NULL;
			if (!close(fd))
				printf("\n======================*** File %s closed ***=======================\n", argv[i]);
			else
				printf("\n Error Closing File\n");
		}
		printf("Cannot Open file %s\n", argv[i]);
		i++;
	}
	return (0);	
}

