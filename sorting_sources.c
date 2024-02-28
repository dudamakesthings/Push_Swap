/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_sources.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 10:32:12 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/28 15:05:25 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	max_number;
	int	max_bits;
	int	i;
	int	j;

	max_number = ft_find_max_number(*stack_a);
	max_bits = find_bits(max_number);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_number)
		{
			if (((*stack_a)->index >> i) & 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push(stack_a, stack_b, 'b');
			j++;
		}
		while (*stack_b != NULL)
			ft_push(stack_b, stack_a, 'a');
		i++;
	}
}

void	ft_sorting_5_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_nodes;

	nb_nodes = node_counter(*stack_a);
	while (nb_nodes)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
		nb_nodes--;
	}
	ft_sorting_3_numbers(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_swap(stack_a, 'a');
}

void	ft_sorting_4_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	nodes;

	nodes = node_counter(*stack_a);
	while (nodes)
	{
		if ((*stack_a)->index == 0)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
		nodes--;
	}
	ft_sorting_3_numbers(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
}

void	ft_sorting_3_numbers(t_stack **stack, char letter)
{
	int		number_a;
	int		number_b;
	int		number_c;
	t_stack	*temp;

	temp = (*stack);
	number_a = (temp)->number;
	number_b = (temp)->next->number;
	number_c = (temp)->next->next->number;
	if (number_a > number_b && number_a < number_c)
		ft_swap(stack, letter);
	else if (number_a > number_c && number_b < number_c)
		ft_rotate(stack, letter);
	else if (number_a > number_c && number_b > number_c && number_a < number_b)
		ft_reverse(stack, letter);
	else if (number_a > number_c && number_b > number_c && number_a > number_b)
	{
		ft_rotate(stack, letter);
		ft_swap(stack, letter);
	}
	else if (number_a < number_c && number_b > number_c && number_a < number_b)
	{
		ft_reverse(stack, letter);
		ft_swap(stack, letter);
	}
}

void	ft_sorting_2_numbers(t_stack **stack, char letter)
{
	if ((*stack)->number > (*stack)->next->number)
	{
		ft_swap(stack, letter);
	}
}
