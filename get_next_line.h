/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:35:49 by haouky            #+#    #+#             */
/*   Updated: 2024/01/18 17:50:18 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct lists
{
	int				i;
	char			*line;
	char			*save;
}					t_var;
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstclear(t_list **lst);
char				*ft_strjoin(char *s1, char *s2);
void				add_backlst(t_list **lst, char *s);
char				*sub(char const *s, unsigned int st, size_t l);
char				*get_next_line(int fd);
size_t				ft_strlen(const char *str);

#endif