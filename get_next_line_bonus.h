/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:42:42 by haouky            #+#    #+#             */
/*   Updated: 2024/01/21 09:23:17 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct lists
{
	int		i;
	char	*line;
	char	*save;
}			t_var;

char		*ft_strjoin(char *s1, char *s2);
char		*sub(char const *s, unsigned int st, size_t l);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
int			chek(char *s);
int			ft_read(int fd, char *s, int i);
char		*get(int fd, t_var *v, char *tmp, char *s);

#endif
