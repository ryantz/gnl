/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:52:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/11 18:09:09 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

// use BUFFER_SIZE to allocate memory
// do not use buffer[BUFFER_SIZE]
char	*ft_read_line(int fd, char **storage);
int		ft_newline_strlen(char *input);
void	ft_append_storage(char *data, char **storage);

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
	char	*string_return;
	char	*string_remainder;
	int		newline_len;

	// assign memory for buffer
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE); 
	buffer[bytes_read] = '\0';

	// scan buffer for newline or terminating?
	// if scanned newline, pass chunk to return
	newline_len = ft_newline_strlen(buffer);
	if (newline_len == 0)
		return (ft_strdup("\n"));
	if (newline_len > 0)
	{
		string_return = malloc(sizeof(char) * newline_len + 1);
		if (!string_return)
			return (NULL);
		ft_memcpy(string_return, buffer, newline_len + 1);
		if (buffer[newline_len] != '\0')
		{
			string_remainder = ft_strdup((ft_strchr(buffer, '\n') + 1));
			if (!string_remainder)
				return (NULL);
			ft_append_storage(string_remainder, storage);
			free(string_remainder);
		}
		return (string_return);
	}
	else
		ft_append_storage(buffer, storage);
	return (NULL);
}

int		ft_newline_strlen(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// pass storage by reference to alter
void	ft_append_storage(char *data, char **storage)
{
	size_t	data_len;
	size_t	storage_len;
	char	*new_storage;

	data_len = ft_strlen(data);
	storage_len = ft_strlen(*storage);
	if (storage_len == 0)
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

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("testfile.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("OUTPUT> %s\n", str);
	//str = get_next_line(fd);
	//printf("OUTPUT> %s\n", str);
	//return (0);
}
