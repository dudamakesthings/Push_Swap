/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checkers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 11:28:49 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/06 16:26:27 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_stack *stack)
{
	t_stack *current;
	t_stack *temp;

	current = stack;
	while(current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->number == temp->number)
			{
				ft_printf("Error\n");
				// TODO: free sta stb
				return (-1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_number_checker(char *arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		if (arguments[i] == ' ' )
			i++;
		if (arguments[i] == '-' | arguments[i] == '+')
			i++;
		else if (ft_isdigit(arguments[i]) != 1)
		{
			ft_printf("%s\n", "Error");
			return (-1);
		}
		else if (ft_atol(&arguments[i]) > INT_MAX || ft_atol(&arguments[i]) < INT_MIN)
		{
			ft_printf("%s\n", "Error");
			return (-1);
		}
		i++;
	}
	return (1);
}
