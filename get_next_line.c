/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:26:51 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/09 16:35:39 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store(char *buffer, ssize_t bytes_read, char **storage);
void	ft_add_store(char *remainder, char **storage, ssize_t b_read);

//TODO: handle EOF last line bytes_read = 0
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char *storage;
	char		*next_line;
	ssize_t		bytes_read;

	next_line = NULL;
	if (fd == -1)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//printf("DEBUG/buffer: %s\n", buffer);
		if (bytes_read < 0)
			return (NULL);
		next_line = ft_store(buffer, bytes_read, &storage);
		if (next_line)
			return (next_line);
	}
}

char	*ft_store(char *buffer, ssize_t bytes_read, char **storage)
{
	int			i;
	int			has_newline;
	char		*string_return;
	char		*string_remainder;
	char		*remainder;
	char		*old_storage;
	size_t		rem_len;

	string_remainder = NULL;
	i = 0;
	ft_add_store(buffer, storage, bytes_read);
	has_newline = ft_has_newline(*storage);
	if (has_newline)
	{
		while ((*storage)[i] && (*storage)[i] != '\n')
		i++;
		string_return = malloc(sizeof(char) * (i + 2));
		if (!string_return)
			return (NULL);
		ft_memcpy(string_return, *storage, i + 1);
		string_return[i + 1] = '\0';
		string_remainder = ft_strchr(*storage, '\n');
		old_storage = *storage;
		if (*(string_remainder + 1) != '\0')
		{
			rem_len = ft_strlen(string_remainder);
			remainder = malloc(sizeof(char) * rem_len + 1);
			if (!remainder)
				return (NULL);
			ft_memcpy(remainder, string_remainder + 1, rem_len + 1);
			free(old_storage);
			*storage = remainder;
		}
		else 
		{
			free(old_storage);
			*storage = NULL;
		}
		//printf("DEBUG/string_remainder: %s\n", string_remainder);
		//printf("DEBUG/storage: %s\n", *storage);
		return (string_return);
	}
	return (NULL);
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
	//printf("DEBUG/malloc len: %ld\n", b_read + storage_len);
	if (!new_storage)
		return ;
	if (*storage)
	{
		ft_memcpy(new_storage, *storage, storage_len);
		free(*storage);
	}
	ft_memcpy(new_storage + storage_len, remainder, b_read);
	new_storage[storage_len + b_read] = '\0';
	//printf("DEBUG/new storage: %s\n", new_storage);
	*storage = new_storage;
}
