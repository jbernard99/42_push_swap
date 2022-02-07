/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:12:02 by jbernard          #+#    #+#             */
/*   Updated: 2022/02/04 23:26:09 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		len_str;
	int		i;

	len_str = ft_strlen(str);
	ptr = malloc(len_str + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (len_str--)
		ptr[i++] = *str++;
	ptr[i] = 0;
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*ptr;
	int		slen;

	slen = ft_strlen(s);
	if (!s || slen <= start || !len)
		return (ft_strdup(""));
	if (len >= slen - start)
		len = slen - start;
	ptr = malloc(++len);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len);
	return (ptr);
}

int	get_word_count(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			++cnt;
			while (*str && *str != c)
				++str;
		}
		else
			++str;
	}
	return (cnt);
}

int	len_until_char(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	int		i;
	int		nb_words;

	if (!s)
		return (0);
	nb_words = get_word_count(s, c);
	ptr = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < nb_words)
	{
		while (*s == c && *s)
			s++;
		ptr[i] = ft_substr(s, 0, len_until_char(s, c));
		s += len_until_char(s, c);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
