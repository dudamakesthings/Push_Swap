/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 17:37:04 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/07 14:22:50 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"

typedef struct s_stack
{
	int	number;
	struct s_stack *next;
} t_stack;

// Input Checkers
void	ft_number_checker(char *arguments);
void	ft_check_duplicates(t_stack *stack);

// Print List
void	print_numbers(t_stack *stack);

// Linked List
t_stack	*new_node(int number);
t_stack	*add_to_stack(t_stack *previous_number, int new_number);
int		node_counter(t_stack *stack);

// Rules Functions
void	ft_swap(t_stack **head);
void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	ft_rotate(t_stack **head);
void	ft_reverse(t_stack **head);

// Free Functions
void	ft_free_stack(t_stack **stack);
void	ft_free_split(char **array);

#endif