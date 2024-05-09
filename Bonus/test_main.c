#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd[2];
	char	*line;

	fd[0] = open("./test1.txt", O_RDONLY);
	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);

	fd[1] = open("./test2.txt", O_RDONLY);
	line = get_next_line(fd[1]);
	printf("%s", line);
	free(line);

	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);

	line = get_next_line(fd[1]);
	printf("%s", line);
	free(line);

	line = get_next_line(fd[0]);
	printf("%s", line);
	free(line);

	// system("leaks a.out");
	return (0);
}
