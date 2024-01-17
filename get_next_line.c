/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:34:12 by haouky            #+#    #+#             */
/*   Updated: 2024/01/17 13:06:16 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chek(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*splt(t_list *lst, int i)
{
	int		cnt;
	char	*s;
	t_list	*head;

	i = 0;
	head = lst;
	cnt = 0;
	while (lst)
	{
		cnt += ft_strlen(lst->content);
		lst = lst->next;
	}
	s = malloc(cnt + 1);
	if (!s)
		return (0);
	cnt = 0;
	while (head)
	{
		while ((head->content)[i])
			s[cnt++] = (head->content)[i++];
		i = 0;
		head = head->next;
	}
	s[cnt] = 0;
	return (s);
}

char	*get(int fd, t_var *v, char *tmp, char *s)
{
	t_list	*head;

	head = 0;
	if (chek(tmp) < 0)
	{
		while ((chek(s) < 0))
		{
			v->i = read(fd, s, BUFFER_SIZE);
			if (v->i <= 0)
				break ;
			s[v->i] = 0;
			(add_backlst(&head, s));
		}
		free(s);
		tmp = ft_strjoin(tmp, splt(head, fd));
		ft_lstclear(&head);
	}
	v->i = chek(tmp);
	if (v->i < 0)
	{
		v->line = sub(tmp, 0, ft_strlen(tmp));
		v->save = 0;
	}
	else
	{
		v->line = sub(tmp, 0, v->i + 1);
		v->save = sub(tmp, v->i + 1, ft_strlen(tmp));
	}
	free(tmp);
	return (v->line);
}

char	*get_next_line(int fd)
{
	t_var		v;
	char		*s;
	static char	*tmp;

	s = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, s, 0) < 0)
	{
		free(tmp);
		tmp = 0;
		return (0);
	}
	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (0);
	s[0] = 0;
	v.line = get(fd, &v, tmp, s);
	tmp = v.save;
	if (!v.save)
		free(v.save);
	return (v.line);
}
