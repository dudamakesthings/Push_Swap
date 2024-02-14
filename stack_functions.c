/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 13:22:50 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/14 12:02:58 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_counter(t_stack *stack)
{
	t_stack		*temp;
	int			counter;

	counter = 0;
	temp = stack;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}

void	print_numbers(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->number);
		temp = temp->next;
	}
}

t_stack	*new_node(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		ft_free_stack(&new_node);
		exit(1);
	}
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*add_to_stack(t_stack *previous_number, int new_number)
{
	t_stack	*current_number;
	t_stack	*temp;

	temp = previous_number;
	current_number = new_node(new_number);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = current_number;
	return (previous_number);
}
