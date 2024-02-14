/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checkers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 11:28:49 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/14 12:11:09 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->number;
	while (stack_a)
	{
		if (i > stack_a->number)
			return (0);
		i = stack_a->number;
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->number == temp->number)
			{
				ft_printf("Error\n");
				ft_free_stack(&stack);
				exit (1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

void	ft_number_checker(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		if (arg[i] == '-' | arg[i] == '+')
			i++;
		else if (ft_isdigit(arg[i]) != 1)
		{
			ft_printf("Error\n");
			exit (1);
		}
		else if (ft_atol(&arg[i]) > INT_MAX || ft_atol(&arg[i]) < INT_MIN)
		{
			ft_printf("Error\n");
			exit (1);
		}
		i++;
	}
}
