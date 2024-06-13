/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:00:57 by aattak            #+#    #+#             */
/*   Updated: 2024/01/01 13:56:11 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			nl;
	ssize_t		r_len;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	nl = 0;
	r_len = 1;
	while (r_len)
	{
		if (buffer[0])
			line = ft_get_line(line, buffer, &nl);
		if (nl)
			return (line);
		r_len = read(fd, buffer, BUFFER_SIZE);
		if (r_len == -1)
			return (free(line), NULL);
		buffer[r_len] = '\0';
	}
	return (line);
}
