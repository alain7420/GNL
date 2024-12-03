/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrapeau <adrapeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:54:31 by adrapeau          #+#    #+#             */
/*   Updated: 2024/12/03 15:09:54 by adrapeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		k;
	char	*res;

	//fd = 0;
	fd = open("test_20_lignes_classiques.txt", O_RDONLY);
	k = 1;
	while (k <= 20)
	{
		res = get_next_line(fd);
		printf("%s\n", res);
		if (k != 18)
			free(res);
		res = NULL;
		k++;
	}
	return (0);
}
