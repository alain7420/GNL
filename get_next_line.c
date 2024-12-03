/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrapeau <adrapeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:29 by adrapeau          #+#    #+#             */
/*   Updated: 2024/12/03 15:26:34 by adrapeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_full_left_side_str(int fd, char *left_side)
{
	char	*buffer;
	int		read_bytes;
	char	*temp;
	
	left_side = malloc(sizeof(char));
	if(!left_side)
		return (NULL);
	buffer = malloc(( BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr_pos(left_side, '\n') == -1 && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0 && buffer[0] == '\0')
		{
			free(left_side);
			free(buffer);
			return (NULL);
		}
		if (read_bytes == -1)
		{
			free(left_side);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(left_side, buffer);
		free (left_side);
		left_side = temp;
	}
	free(buffer);
	return (left_side);
}
char	*ft_left_side_str(char *str_res)
{
	int		i;
	char	*temp;
	
	temp = malloc(sizeof(char));
	i = ft_strchr_pos(str_res, '\n');
	if (i == -1)
		return (temp = str_res, temp);
	temp = ft_substr(str_res, 0, i);
	temp[i + 1] = '\0';
	return(temp);
}

char	*ft_right_str(char *str_res)
{
	int		i;
	char	*temp;
	
	i = ft_strchr_pos(str_res, '\n');
	temp = malloc(sizeof(char));
	if (i > 0)
		temp = ft_substr(str_res, i + 1, ft_strlen(str_res)- i);
	// else
	// 	temp[0] = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*str_res;
	static char		*temp_res = "";
	char			*test;
	
	
	test = "";
	str_res = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	if (ft_strchr_pos(temp_res, '\n') == -1)
	{
		str_res = ft_full_left_side_str(fd, str_res);
		if (str_res == test)
			return (NULL);
		temp_res = ft_strjoin(temp_res, str_res);
	}
	if(!temp_res)
		return (NULL);
	str_res = ft_left_side_str(temp_res);
	temp_res = ft_right_str(temp_res);
	return (str_res); 
}
