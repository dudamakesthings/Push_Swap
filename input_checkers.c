/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checkers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 11:28:49 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/27 17:15:42 by edribeir      ########   odam.nl         */
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

bool	ft_number_checker(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	ft_input_checker(int argc, char *argv[])
{
	int				i;
	long long int	tmp_number;
	char			**array_num;

	i = 0;
	if (argc == 2)
		array_num = ft_split(argv[1], ' ');
	else
		array_num = argv + 1;
	while (array_num[i])
	{
		tmp_number = ft_atol(array_num[i]);
		if ((tmp_number < INT_MIN || tmp_number > INT_MAX) || 
				ft_number_checker(array_num[i]) != true)
		{
			ft_printf("Error\n");
			exit (true);
		}
		i++;
	}
	if (argc == 2)
		ft_free_split(array_num);
}
