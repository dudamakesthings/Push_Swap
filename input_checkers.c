/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checkers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 11:28:49 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/27 10:43:17 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_stack_sorted(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp->next != NULL && temp)
	{
		if (temp->index > temp->next->index)
			return (false);
		temp = temp->next;
	}
	return (true);
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
				exit (true);
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
		if ((arg[i] == '-') | (arg[i] == '+'))
			i++;
		else if (ft_isdigit(arg[i]) != true)
		{
			ft_printf("Error\n");
			exit (true);
		}
		else if (ft_atol(&arg[i]) > INT_MAX || ft_atol(&arg[i]) < INT_MIN)
		{
			ft_printf("Error\n");
			exit (true);
		}
		i++;
	}
}
