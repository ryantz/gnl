#include "get_next_line.h"

int	main(int argc, char **argv)
{
	if (argc <= 0)
		return (1);
	else
	{
		char *testfile;
		char *str;
		int	fd;

		testfile = argv[1];
		fd = open(testfile, O_RDONLY);
		while ((str = get_next_line(fd)))
		{
			printf("OUTPUT> %s\n", str);
			free(str);
		}
		close(fd);
		return (0);
	}
}
