/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrapeau <adrapeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:19:06 by adrapeau          #+#    #+#             */
/*   Updated: 2024/12/03 15:42:14 by adrapeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 38
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

typedef struct s_list
{
	int				i;
	int				j;
	unsigned int	ent1;
	unsigned int	ent2;
	char			*temp;
	char			*tmp1;
	int				tmp2;
	char			*hexa2;
	const char		*str;
}					t_list;

size_t			ft_strlen(const char *str);
char			*ft_strjoin(const char *str1, const char *str2);
void			ft_bzero(void *s, size_t n);
char			*get_next_line(int fd);
int				ft_strchr_pos(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_full_left_side_str(int fd, char *left_side);
char			*ft_left_side_str(char *str_res);
char			*ft_right_str(char *str_res);
char			*ft_substr(const char *s, unsigned int start, size_t len);

#endif