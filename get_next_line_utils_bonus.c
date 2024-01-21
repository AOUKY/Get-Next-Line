/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:46:15 by haouky            #+#    #+#             */
/*   Updated: 2024/01/21 09:19:41 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*sub(char const *s, unsigned int st, size_t l)
{
	size_t	i;
	char	*c;

	i = 0;
	if (s == 0)
		return (0);
	if (!s[0])
		return (0);
	while (s[st + i] != 0 && i < l)
		i++;
	c = malloc(i + 1);
	if (c == 0)
		return (0);
	i = 0;
	while (s[st + i] != 0 && i < l)
	{
		c[i] = s[st + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l;
	char	*s;
	int		i;

	i = 0;
	l = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s = malloc(l);
	if (!s)
		return (0);
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	l = 0;
	while (s2 && s2[l])
		s[i++] = s2[l++];
	s[i] = 0;
	free(s1);
	return (s);
}
