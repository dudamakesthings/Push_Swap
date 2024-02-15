/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 17:37:04 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/15 13:16:10 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"

typedef struct s_stack
{
	int				number;
	int				final_index;
	int				current_position;
	int				push_price;
	bool			cheapest;
	bool			above_medium;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Input Checkers
void	ft_number_checker(char *arg);
void	ft_check_duplicates(t_stack *stack);
int		ft_stack_sorted(t_stack *stack_a);

// Print List
void	print_numbers(t_stack *stack);

// Linked List
t_stack	*new_node(int number);
t_stack	*add_to_stack(t_stack *previous_number, int new_number);
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

#endif