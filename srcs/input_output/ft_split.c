/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:20:40 by aattak            #+#    #+#             */
/*   Updated: 2024/06/11 20:48:49 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	ft_count_words(char const *s)
{
	size_t	i;
	size_t	count;

	if (!(s[0]))
		return (0);
	count = 0;
	if (s[0] != 32)
		count = 1;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == 32 && s[i] != 32)
			count++;
		i++;
	}
	return (count);
}

static size_t	word_len(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 32 && s[i] != '\0')
		i++;
	return (i);
}

static char	*malloc_nd_fill(char const *s, size_t *i)
{
	size_t	len;
	char	*split;

	while (s[*i] == 32)
		(*i)++;
	len = word_len(&s[*i]);
	split = (char *)malloc(len + 1);
	if (!split)
		return (NULL);
	ft_strlcpy(split, &s[*i], len + 1);
	while (s[*i] != 32 && s[*i] != '\0')
		(*i)++;
	return (split);
}

void	free_split(char **split, size_t n_words)
{
	if (n_words)
	{
		while (n_words--)
		{
			free(split[n_words]);
			if (n_words == 0)
				break ;
		}
	}
	if (split)
		free(split);
}

char	**ft_split(char const *s, size_t *n_words)
{
	size_t	i;
	size_t	j;
	char	**split;

	if (!s)
		return (NULL);
	*n_words = ft_count_words(s);
	split = (char **)malloc(((*n_words) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < *n_words)
	{
		split[j] = malloc_nd_fill(s, &i);
		if (!(split[j]))
		{
			free_split(split, j);
			return (NULL);
		}
		j++;
	}
	split[(*n_words)] = NULL;
	return (split);
}
