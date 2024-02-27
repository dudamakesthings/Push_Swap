/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 13:22:50 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/27 10:46:29 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_find_max_number(t_stack *stack)
// {
// 	int		max_number;
// 	t_stack	*temp;

// 	temp = stack;
// 	max_number = temp->number;
// 	while (temp)
// 	{
// 		if (max_number < temp->number)
// 			max_number = temp->number;
// 		temp = temp->next;
// 	}
// 	return (max_number);
// }
void	print_numbers(t_stack *stack)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current != NULL)
	{
		printf("node: %d: %d	index: %d\n", i, current->number, current->index);
		i++;
		current = current->next;
	}
}

int	ft_find_max_number(t_stack *stack)
{
	int		max_number;
	t_stack	*temp;

	max_number = INT_MIN;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->index > max_number)
			max_number = temp->index;
		temp = temp->next;
	}
	return (max_number);
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

// t_stack	*add_to_stack(t_stack *previous_number, int new_number)
// {
// 	// t_stack	*current_number;
// 	t_stack	*current;

// 	if (previous_number == NULL)
// 	{
// 		previous_number = new_node(new_number);
// 		// return (previous_number);
// 	}
// 	// temp = previous_number;
// 	// current_number = new_node(new_number);
// 	current = previous_number;
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = new_node(new_number);
// 	// current->next = current_number;
// 	return (previous_number);
// }
