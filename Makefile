# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 15:36:13 by razasharuku       #+#    #+#              #
#    Updated: 2023/03/06 12:20:28 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = gnl.a
SRCS = get_next_line.c \
		get_next_line_utils.c \

SRCS_B = ft_lstlast.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstnew.c \


OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

ALL_OBJS = ${OBJS}

ifdef bonus_flag
	ALL_OBJS+=${OBJS_B}
endif

all:	$(NAME)

$(NAME):	${ALL_OBJS}
		ar -r ${NAME} ${ALL_OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS} ${OBJS_B}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus:
	make bonus_flag=1
.PHONY: all clean fclean re
