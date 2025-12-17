/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:52:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/17 06:30:22 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

// use BUFFER_SIZE to allocate memory
// do not use buffer[BUFFER_SIZE]
char	*ft_read_line(int fd, char **storage);
void	ft_append_storage(char *data, char **storage);
char	*ft_scan_storage(char match, char **storage);

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*return_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
		return_string = ft_read_line(fd, &storage);
	return (return_string);
}

// read the file info into a buffer
// use malloc so that variable array is not used
char	*ft_read_line(int fd, char **storage)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*return_string;

	// assign memory for buffer
	// SOMETHING IS VERY WRONG HERE
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE); 
	buffer[bytes_read] = '\0';

	printf("DEBUG/log: buffer: %s\n", buffer);
	printf("DEBUG/log: storage: %s\n", *storage);
	ft_append_storage(buffer, storage);
	printf("DEBUG/log: storage: %s\n", *storage);
	return_string = ft_scan_storage('\n', storage);
	printf("DEBUG/log: return string: %s\n", return_string);
	return (*storage);
}

void	ft_append_storage(char *data, char **storage)
{
	size_t	data_len;
	char	*new_storage;

	data_len = ft_strlen(data);
	if (!data)
		return (NULL);
	if (!*storage)
	{
		*storage = malloc(sizeof(char) * data_len + 1);
		if (!*storage)
			return ;
		ft_memcpy(*storage, data, data_len);
		(*storage)[data_len] = '\0';
	}
	else
	{
		new_storage = ft_strjoin(*storage, data);
		if (!new_storage)
			return ;
		free(*storage);
		*storage = new_storage;
	}
}

char	*ft_scan_storage(char match, char **storage)
{
	int	end;
	char	*found;

	end = 0;
	while ((*storage)[end])
	{
		if ((*storage)[end] == match)
			break;
		end++;
	}
	if ((*storage)[end] == '\0')
		return (NULL);
	found = malloc(sizeof(char) * (end + 1));
	ft_memcpy(found, *storage, end);
	found[end] = '\0';
	return (found);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("testfile.txt", O_RDONLY);
	str = get_next_line(fd);
	//printf("OUTPUT> %s\n", str);
	//return (0);
}
