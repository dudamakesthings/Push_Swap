/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 13:22:50 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/04 11:15:11 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_numbers(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = 0;
	while (temp != NULL)
	{
		printf("node: %d: %d	index: %d\n", i, temp->number, temp->index);
		i++;
		temp = temp->next;
	}
}

int	ft_find_max_index(t_stack *stack)
{
	int		max_index;
	t_stack	*temp;

	max_index = -1;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}

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

t_stack	*new_node(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		ft_free_stack(&new_node);
		exit(true);
	}
	new_node->number = number;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*add_to_stack(t_stack *previous_number, int number)
{
	t_stack	*current;

	if (previous_number == NULL)
	{
		previous_number = new_node(number);
		return (previous_number);
	}
	current = previous_number;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node(number);
	return (previous_number);
}
