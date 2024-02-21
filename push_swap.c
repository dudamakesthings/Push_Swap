/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/21 12:09:31 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack *ft_sort(t_stack *stack_a)
{
	int	is_sorted;
	
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
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stack		*stack_a;

	i = 1;
	stack_a = NULL;
	if (argc == 1 || (argc == 2 && (argv[1][0] == false)))
		exit(true);
	while (i < argc)
	{
		ft_number_checker(argv[i]);
		i++;
	}
	if (argc == 2)
		stack_a = string_to_stack(stack_a, &argv[1]);
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
			stack_a = add_to_stack(stack_a, ft_atoi(argv[i++]));
	}
	// t_stack *current = stack_a;
	// int a = 0;
	// while(current)
	// {
		
	// 	printf("node %i: %i\n", a, current->number);
	// 	current = current->next;
	// 	a++;
	// }
	ft_check_duplicates(stack_a);
	stack_a = ft_sort(stack_a);
	print_numbers(stack_a);
	ft_free_stack(&stack_a);
}
