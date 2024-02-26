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

int	find_bits(int max_number)
{
	int	max_bits;

	max_bits = 0;
	while (max_number > 0)
	{
		max_number >>= 1;
		max_bits++;
	}
	return(max_bits);
}

// t_stack	*ft_get_next_max(t_stack *stack_a)
// {
// 	t_stack	*temp;
// 	t_stack	*max_number;
// 	bool	max_exist;

// 	max_number = NULL;
// 	max_exist = false;
// 	temp = stack_a;
// 	if (temp != NULL)
// 	{
// 		while(temp != NULL)
// 		{
// 			if ((temp->index == false) && (max_exist == false || temp->number > max_number->number))
// 			{
// 				max_number = temp;
// 				max_exist = true;
// 			}
// 			temp = temp->next;
// 		}	
// 	}
// 	// print_numbers(min_number);
// 	// ft_printf("\n--------\n");
// 	return (max_number);
// }

// t_stack	*ft_get_next_min(t_stack *stack_a)
// {
// 	t_stack	*temp;
// 	t_stack	*min_number;
// 	bool	min_exist;

// 	min_number = NULL;
// 	min_exist = false;
// 	temp = stack_a;
// 	if (temp)
// 	{
// 		while(temp != NULL)
// 		{
// 			if ((temp->index == false) && (min_exist == false || temp->number < min_number->number))
// 			{
// 				min_number = temp;
// 				min_exist = true;
// 			}
// 			temp = temp->next;
// 		}	
// 	}
// 	// print_numbers(min_number);
// 	// ft_printf("\n--------\n");
// 	return (min_number);
// }

// void	ft_set_index_to_stack(t_stack *stack_a)
// {
// 	t_stack	*temp;
// 	int		index;

// 	index = 0;
// 	temp = ft_get_next_min(stack_a);
// 	// 	print_numbers(temp);
// 	// ft_printf("\n print temp--------\n");
// 	// ft_printf("\n print temp->number = %i--------\n", temp->number);
// 	while (temp != NULL)
// 	{
// 		temp->index = index++;
// 		temp = ft_get_next_min(stack_a);
// 	// 		print_numbers(temp);
// 	// ft_printf("\n print temp  **--------\n");
// 	// 	printf("esse eh o index do maior nodo = %i ----\n", index);
// 	// 		ft_printf("\n print temp->number = %i--------\n", temp->number);
// 	}
// }


void	ft_set_index_to_stack(t_stack *stack_a, int size_stack)
{
	t_stack	*max_number;
	t_stack	*temp;

	while(size_stack > 0)
	{
		max_number = NULL;
		temp = stack_a;
		while (temp != NULL)
		{
			if ((temp->index == false) && ((max_number == NULL)
				|| temp->number > max_number->number))
					max_number = temp;
			temp = temp->next;
		}
		if (max_number != NULL)
			max_number->index = size_stack;
		// ft_printf ("esse eh o index = %i\n -----", max_number->index);
		size_stack--;
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

t_stack *ft_sort(t_stack *stack_a)
{
	int	is_sorted;
	t_stack *stack_b;

	stack_b = NULL;
	ft_set_index_to_stack(stack_a, node_counter(stack_a));
	is_sorted = ft_stack_sorted(stack_a);
	if (is_sorted == false)
	{
		if (node_counter(stack_a) == 2)
			ft_sorting_2_numbers(&stack_a, 'a');
		else if (node_counter(stack_a) == 3)
			ft_sorting_3_numbers(&stack_a, 'a');
		else if (node_counter(stack_a) <= 5)
			ft_sorting_4_5_numbers(&stack_a, &stack_b);
		else
			ft_radix_sorting(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_b);
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
		ft_number_checker(argv[i++]);
	if (argc == 2)
		stack_a = string_to_stack(stack_a, &argv[1]);
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
			stack_a = add_to_stack(stack_a, ft_atoi(argv[i++]));
	}
	ft_check_duplicates(stack_a);
	stack_a = ft_sort(stack_a);
	print_numbers(stack_a);
	ft_free_stack(&stack_a);
}

	// t_stack *current = stack_a;
	// int a = 0;
	// while(current)
	// {
		
	// 	printf("node %i: %i\n", a, current->number);
	// 	current = current->next;
	// 	a++;
	// }
