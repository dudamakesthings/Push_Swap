/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/20 17:58:52 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_find_max_number(t_stack *stack)
{
	int		max_number;
	t_stack	*temp;

	temp = stack;
	max_number = temp->number;
	while (temp)
	{
		if (max_number < temp->number)
			max_number = temp->number;
		temp = temp->next;
	}
	return (max_number);
	// ft_printf("%i\n", max_number);
}

int	ft_find_min_number(t_stack *stack)
{
	int		min_number;
	t_stack	*temp;

	temp = stack;
	min_number = temp->number;
	while (temp)
	{
		if (min_number > temp->number)
			min_number = temp->number;
		temp = temp->next;
	}
	return (min_number);
	// ft_printf("%i\n", min_number);
}

bool	ft_stack_ordered(t_stack *stack)
{
	int	max;
	int min;

	max = ft_find_max_number(stack);
	min = ft_find_min_number(stack);
	while (stack->next != NULL)
	{
	
		if (stack->number > stack->next->number && !(stack->number == max && stack->next->number == min))
			return	(false);
		stack = stack->next;
	}
	return (true);
}

void	ft_bubble_sorting(t_stack **stack)
{
	// printf("is sorted = %d\n", ft_stack_sorted(*stack));
	int i = 0;
	while (ft_stack_ordered(*stack) == false)
	{
		if ((*stack)->number > (*stack)->next->number)
		{
			ft_swap(stack, 'a');
		}
			ft_rotate(stack, 'a');
		i++;
	}
	while (ft_stack_sorted(*stack) == false)
		ft_rotate(stack, 'a');
}

t_stack	*string_to_stack(t_stack *stack_a, char *argv[])
{
	int		i;
	char	**array;
	int		nb;

	array = ft_split(*argv, ' ');
	i = 0;
	while (array[i])
	{
		nb = ft_atoi(array[i]);
		if (stack_a == NULL)
			stack_a = new_node(ft_atoi(array[i]));
		else
			stack_a = add_to_stack(stack_a, nb);
		i++;
	}
	ft_free_split(array);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			j;
	int			is_sorted;
	t_stack		*stack_b;
	t_stack		*stack_a;

	i = 1;
	j = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && (argv[1][0] == false)))
		exit(1);
	while (j < argc)
	{
		ft_number_checker(argv[j]);
		j++;
	}
	if (argc == 2)
		stack_a = string_to_stack(stack_a, &argv[1]);
	if (argc > 2)
	{
		if (stack_a == NULL)
			stack_a = new_node(ft_atoi(argv[i]));
		i++;
		while (i < argc)
		{
			stack_a = add_to_stack(stack_a, ft_atoi(argv[i]));
			i++;
		}
	}
	ft_check_duplicates(stack_a);
	is_sorted = ft_stack_sorted(stack_a);
	if (is_sorted == false)
	{
		if (node_counter(stack_a) == 2)
			ft_sorting_2_numbers(&stack_a, 'a');
		else if (node_counter(stack_a) == 3)
			ft_sorting_3_numbers(&stack_a, 'a');
		else
		ft_bubble_sorting(&stack_a);
	}
	print_numbers(stack_a);
	ft_free_stack(&stack_a);
	exit(0);
}
