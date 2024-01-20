/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:46:15 by haouky            #+#    #+#             */
/*   Updated: 2024/01/19 18:49:28 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	add_backlst(t_list **lst, char *s)
{
	t_list	*head;
	t_list	*ne;
	int		i;

	i = -1;
	head = *lst;
	ne = malloc(sizeof(t_list));
	if (ne == 0)
		return (ft_lstclear(lst));
	ne->content = malloc(ft_strlen(s) + 1);
	if (ne->content == 0)
		return (ft_lstclear(lst));
	while (s[++i])
		(ne->content)[i] = s[i];
	(ne->content)[i] = 0;
	ne->next = 0;
	if (*lst == 0)
		*lst = ne;
	else
	{
		while (head->next)
			head = head->next;
		head->next = ne;
	}
}

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
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	l = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s = malloc(l);
	if (!s)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	l = 0;
	while (s2[l])
		s[i++] = s2[l++];
	s[i] = 0;
	free(s1);
	free(s2);
	return (s);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*nd;
	t_list	*last_node;

	if (!lst)
		return ;
	last_node = *lst;
	while (last_node)
	{
		nd = last_node;
		last_node = last_node->next;
		free(nd->content);
		free(nd);
	}
	*lst = 0;
}
