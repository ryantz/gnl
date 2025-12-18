#include "get_next_line.h"

int	main(void)
{
	char *str;
	int	fd;

	fd = open("testfile.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
	    printf("OUTPUT> %s\n", str);
	    free(str);
	}
	close(fd);
	return (0);
}
