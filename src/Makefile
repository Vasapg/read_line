# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:51:49 by vsanz-ar          #+#    #+#              #
#    Updated: 2023/02/04 17:30:32 by vsanz-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------GNL MAKE VARS------------------------------------------------
NAME = get_next_line.a
FILES = get_next_line.c get_next_line_utils.c 
CFLAGS = -Wall -Wextra -Werror -g -D BUFF_SIZE=1
CC = gcc
RM = rm -f
FOBJ = ${FILES:.c=.o}
#----------------------------------------GNL MAKE RULES------------------------------------------------

all: ${NAME}

${NAME}: ${FOBJ} 
	ar -rcs ${NAME} ${LIBOB} ${FOBJ}
	${CC} test.c -o test.out ${NAME}

clean:
	${RM} ${FOBJ} ${BOBJ} test.out

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean re fclean bonus libft 
