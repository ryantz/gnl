/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:29:51 by ryatan            #+#    #+#             */
/*   Updated: 2025/12/09 09:10:01 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
