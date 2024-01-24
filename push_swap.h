/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 17:37:04 by edribeir      #+#    #+#                 */
/*   Updated: 2024/01/24 19:08:41 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
//# include "./Libft/get_next_line.h"

typedef struct s_stack
{
	int	number;
	struct s_stack *next;
} t_stack;

t_stack	*new_node(int number);
t_stack	*add_number_front(t_stack *actual_number, int new_number);

#endif