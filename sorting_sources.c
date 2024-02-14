/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_sources.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 10:32:12 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/14 12:04:13 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
