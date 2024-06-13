/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:03:27 by aattak            #+#    #+#             */
/*   Updated: 2023/12/31 11:40:36 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);
char	*ft_get_line(char *line, char *buffer, int *nl);
void	ft_buff_move(char *buffer, ssize_t b_len);
ssize_t	ft_strlen_nl(char *s, int *nl);

#endif
