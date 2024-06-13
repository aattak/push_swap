/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:07:18 by aattak            #+#    #+#             */
/*   Updated: 2023/12/31 11:40:24 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buff_move(char *buffer, ssize_t b_len)
{
	ssize_t	i;

	i = 0;
	while (buffer[b_len])
		buffer[i++] = buffer[b_len++];
	buffer[i] = '\0';
}

ssize_t	ft_strlen_nl(char *s, int *nl)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (i && s[i - 1] == '\n')
		{
			*nl = 1;
			break ;
		}
	}
	return (i);
}

char	*ft_get_line(char *line, char *buffer, int *nl)
{
	ssize_t	l_len;
	ssize_t	b_len;
	ssize_t	c;
	ssize_t	i;
	char	*tmp;

	tmp = line;
	if (!line)
		l_len = 0;
	else
		l_len = ft_strlen_nl(line, nl);
	b_len = ft_strlen_nl(buffer, nl);
	line = (char *)malloc(l_len + b_len + 1);
	if (!line)
		return (free(tmp), NULL);
	c = -1;
	while (++c < l_len)
		line[c] = tmp[c];
	i = 0;
	while (i < b_len)
		line[c++] = buffer[i++];
	line[c] = '\0';
	ft_buff_move(buffer, b_len);
	return (free(tmp), line);
}
