/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:29:51 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/05 12:08:20 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open file.\n");
		return (-1);
	}
	next_line = get_next_line(fd);
	printf("%s\n", next_line);
	free(next_line);
	return (0);
}
