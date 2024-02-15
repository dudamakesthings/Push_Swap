/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pw.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 12:56:06 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/15 14:52:33 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_node(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	append_to_stack(t_stack **stack_a, int number)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack_a == NULL)
		return ;
	node = malloc(1 * sizeof(t_stack));
	if (node == NULL)
		return ;
	node->number = number;
	node->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack_a);
		last_node->next = node;
		node->prev = last_node;
	}
}
int	error_repetition(t_stack *stack_a, int number)
{
	t_stack *temp;

	temp = stack_a;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->number == number)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	stack_init(t_stack **stack_a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		// if (number > INT_MAX || number < INT_MIN)
		// 	error_n_free(stack_a, argv);
		// if (error_repetition(*stack_a, (int)number))
		// 	error_n_free(stack_a, argv);
		append_to_stack(stack_a, (int)number);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_init(&stack_a, argv + 1);
	}
	else if (argc > 2)
		stack_init(&stack_a, argv);
	if (argc == 2)
		ft_free_split(argv);
	print_numbers(stack_a);
}