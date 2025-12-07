/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:26:51 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/08 07:49:19 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store(char *buffer, ssize_t bytes_read, char **storage);
void	ft_add_store(char *remainder, char **storage, ssize_t b_read);

//test
char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	static char *storage;
	char	*next_line;
	ssize_t	bytes_read;

	storage = NULL;
	next_line = NULL;
	if (fd == -1)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		ft_add_store(buffer, &storage, bytes_read);
		next_line = ft_store(buffer, bytes_read, &storage);
		if (next_line)
			return (next_line);
	}
}

char	*ft_store(char *buffer, ssize_t bytes_read, char **storage)
{
	int			i;
	char		*string_return;
	char		*string_remainder;

	string_remainder = ft_strchr(*storage, '\n');
	i = 0;
	if (string_remainder)
	{
		while (buffer[i] && buffer[i] != '\n')
			i++;
		string_return  = malloc(sizeof(char) * (i + 2));
		if (!string_return)
			return (NULL);
		ft_memcpy(string_return, buffer, i + 1);
		ft_add_store(string_remainder + 1, storage, bytes_read);
		return (string_return);
	}
	else
	{
		ft_add_store(buffer, storage, bytes_read);
		while ((*storage)[i] && (*storage)[i] != '\n')
			i++;
		string_return = malloc(sizeof(char) * (i + 2));
		if (!string_return)
			return (NULL);
		ft_memcpy(string_return, storage, i + 1);
		string_return[i + 1] = '\0';
		return (string_return);
	}
}

// pass by reference
void	ft_add_store(char *remainder, char **storage, ssize_t b_read)
{
	char	*new_storage;
	size_t	storage_len;
	
	storage_len = 0;
	if (*storage)
		storage_len = ft_strlen(*storage);
	new_storage = malloc(sizeof(char) * (storage_len + b_read + 1));
	if (!new_storage)
		return ;
	if (*storage)
	{
		ft_memcpy(new_storage, *storage, storage_len);
		free(*storage);
	}
	ft_memcpy(new_storage + storage_len, remainder, b_read);
	new_storage[storage_len + b_read] = '\0';
	*storage = new_storage;
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("testfile.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
}
