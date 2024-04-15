#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file %s\n", argv[1]);
		return (1);
	}
	while ((line = get_next_line(fd)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
