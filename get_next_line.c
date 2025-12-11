/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:52:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/11 09:49:44 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

// use BUFFER_SIZE to allocate memory
// do not use buffer[BUFFER_SIZE]
char	*ft_read_into_buffer(int fd);
void	ft_append_storage(char **storage, char *remainder);
int		ft_newline_check(char *chunk);

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

// read the file info into a buffer
// use malloc so that variable array is not used
char	*ft_read_into_buffer(int fd)
{
	ssize_t	bytes_read;
	char	*buffer;

	bytes_read = read(fd, buffer, BUFFER_SIZE); 
	buffer = malloc(sizeof(char) * (bytes_read + 1));
	return (buffer);
}

// pass storage by reference to alter
void	ft_append_storage(char **storage, char *remainder)
{
}

// check for newline
int		ft_newline_check(char *chunk)
{
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
