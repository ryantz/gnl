/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:52:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/10 10:33:31 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

// use BUFFER_SIZE to allocate memory
// do not use buffer[BUFFER_SIZE]
char *ft_read_into_buffer(int fd);

char	*get_next_line(fd)
{
	//static char	*storage;
	char	*return_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
		return_string = ft_read_into_buffer(fd);
	return (return_string);
}

char	*ft_read_into_buffer(int fd)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	bytes_read = read(fd, buffer, BUFFER_SIZE); 
	return (buffer);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("testfile.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("OUTPUT> %s\n", str);
	str = get_next_line(fd);
	printf("OUTPUT> %s\n", str);
	lreturn (0);
}
