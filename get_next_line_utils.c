/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrapeau <adrapeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:29 by adrapeau          #+#    #+#             */
/*   Updated: 2024/12/03 15:41:52 by adrapeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*result;

	i = 0;
	while (src[i] != '\0')
		i++;
	result = (char *)malloc((i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return ((char *)res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int	ft_strchr_pos(const char *s, int c)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s);
	c = c % 256;
	if (l == 0)
		return (-1);
	while (i <= l)
	{
		if (s[i] == c)
//			return ((char *)s + i);
			return (i);
		i++;
	}
//	return ((void *)0);
	return (-1);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*strcat;
	int		i;
	int		lres1;
	int		lres2;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	lres1 = ft_strlen(str1);
	lres2 = ft_strlen(str2);
	strcat = malloc(lres1 + lres2 + 1);
	if (strcat == NULL)
		return (NULL);
	while (i < lres1)
	{
		strcat[i] = str1[i];
		i++;
	}
	while (i < lres1 + lres2)
	{
		strcat[i] = str2[i - lres1];
		i++;
	}
	strcat[lres1 + lres2] = '\0';
	return (strcat);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
