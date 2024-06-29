/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:52:55 by aattak            #+#    #+#             */
/*   Updated: 2024/06/15 22:05:07 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	check_sign(char c, size_t *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoil(const char *str)
{
	int		sign;
	long	nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	sign = check_sign(str[i], &i);
	if (str[i] < '0' || str[i] > '9')
		return (((long)INT_MAX) + 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - 48;
		if ((nbr > INT_MAX && sign == 1) || (nbr > (long)(INT_MAX) + 1
			&& sign == -1))
			return (nbr);
		i++;
	}
	if (str[i])
		return (((long)INT_MAX) + 1);
	return (nbr * (long)sign);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && dstsize > i + 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}
