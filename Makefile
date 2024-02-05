# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: edribeir <edribeir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/12 16:04:57 by edribeir      #+#    #+#                  #
#    Updated: 2024/02/05 13:32:55 by edribeir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = Libft/libft.a

LIBFTDIR = Libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -f

SOURCE = push_swap.c \
		stack_functions.c \
		ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse.c \
		

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(LIBFTDIR)
clean: 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 