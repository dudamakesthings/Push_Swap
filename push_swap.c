/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/14 15:22:20 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_number(t_stack **stack)
{
	int		max_number;
	t_stack	*temp;

	temp = (*stack);
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

int	ft_find_min_number(t_stack **stack)
{
	int		min_number;
	t_stack	*temp;

	temp = (*stack);
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

// void	ft_sorting_3_numbers(t_stack **stack_a)
// {
// 	// int	min_number;
// 	t_stack	*temp;
// 	t_stack *current;
// 	current = *stack_a;
// 	while (current != NULL)
// 	{
// 		temp = current->next;
// 		while (temp != NULL)
// 		{
// 			if (current->number > temp->number)
// 			{
// 				ft_swap(stack_a);
// 				// min_number = temp->number;
// 				// // ft_printf("\n%d", min_number);
// 				// if (min_number > current->number)
// 				// 	min_number = current->number;
// 			}
// 			temp = temp->next;
// 		}
// 		// ft_printf("\n%d", current->number);
// 		current = current->next;
// 	}
// 	// ft_printf("\n%d", min_number);
// }
// void	ft_sorting_5_numbers(t_stack **stack_a, t_stack **stack_b)
// {

// }

void	ft_sorting_4_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int		small;
	t_stack	*temp;

	temp = (*stack_a);
	small = ft_find_min_number(stack_a);
	ft_printf("small:%i\n", small);
	if (temp->number != small)
	{
		ft_push(&temp, stack_b, 'a');
		temp = temp->next;
	}
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
	int			error;
	t_stack		*stack_b;
	t_stack		*stack_a;

	i = 1;
	j = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
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
		// if (st_b == NULL)
		// 	st_b = new_node(ft_atoi(argv[i]));
		i++;
		while (i < argc)
		{
			stack_a = add_to_stack(stack_a, ft_atoi(argv[i]));
			i++;
		}
	}
	ft_check_duplicates(stack_a);
	print_numbers(stack_a);
	ft_printf("----------");
	ft_printf("\nstack a\n");
	
	error = ft_stack_sorted(stack_a);
	if (error == 0)
	{
		// ft_sorting_2_numbers(&stack_a, 'a');
		ft_sorting_3_numbers(&stack_a, 'a');
		// ft_sorting_4_numbers(&stack_a, &stack_b);
	}
	// print_numbers(stack_a);
	ft_printf("----------");
	ft_printf("\nstack b\n");
	print_numbers(stack_b);
	ft_free_stack(&stack_a);
	exit(0);
}
