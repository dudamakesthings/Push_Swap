/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 17:37:04 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/27 11:35:23 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Input Checkers
void	ft_number_checker(char *arg);
void	ft_check_duplicates(t_stack *stack);
bool	ft_stack_sorted(t_stack *stack_a);

// Print List
void	print_numbers(t_stack *stack);

// Linked List
t_stack	*new_node(int number);
t_stack	*add_to_stack(t_stack *previous_number, int number);
int		node_counter(t_stack *stack);

// Rules Functions
void	ft_swap(t_stack **head, char letter);
void	ft_push(t_stack **stack_from, t_stack **stack_to, char letter);
void	ft_rotate(t_stack **head, char letter);
void	ft_reverse(t_stack **head, char letter);

// Free Functions
void	ft_free_stack(t_stack **stack);
void	ft_free_split(char **array);

// Sorting Functions
void	ft_sorting_2_numbers(t_stack **stack, char letter);
void	ft_sorting_3_numbers(t_stack **stack, char letter);
void	ft_sorting_4_numbers (t_stack **stack_a, t_stack **stack_b);
void	ft_sorting_5_numbers (t_stack **stack_a, t_stack **stack_b);
void	ft_radix_sorting(t_stack **stack_a, t_stack **stack_b);

// Numbers
int		find_bits(int max_number);
int		ft_find_max_number(t_stack *stack);

#endif