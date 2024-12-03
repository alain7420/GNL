# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alain <alain@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:04:09 by adrapeau          #+#    #+#              #
#    Updated: 2024/11/30 18:44:20 by alain            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		get_next_line.a
SRC =       get_next_line_utils.c get_next_line.c

CC =		cc
CFLAGS =    -Wall -Wextra -Werror -g3
OBJ =       $(SRC:.c=.o)

all:        $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):    $(OBJ)
			ar rcs $(NAME) $(OBJ)	
			
clean:
			rm -f $(OBJ)

fclean:     clean
			rm -f $(NAME)

re:         fclean all

.PHONY: all clean fclean re
