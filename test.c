#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("testfile.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("OUTPUT/line: %s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}
