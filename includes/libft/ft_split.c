/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:03:00 by abeaudet          #+#    #+#             */
/*   Updated: 2022/10/28 14:38:05 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != a && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == a)
			j = 0;
		str++;
	}
	return (i);
}

static char	*word_up(const char *str, int debut, int fin)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((fin - debut + 1) * sizeof(char));
	if (!word)
		return (0);
	while (debut < fin)
	{
		word[i] = str[debut];
		i++;
		debut++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		ind;
	char	**split;

	if (!s)
		return (0);
	split = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	j = 0;
	ind = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && ind < 0)
			ind = i;
		else if ((s[i] == c || i == ft_strlen(s)) && ind >= 0)
		{
			split[j++] = word_up(s, ind, i);
			ind = -1;
		}
	}
	split[j] = 0;
	return (split);
}
