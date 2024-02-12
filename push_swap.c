/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/12 18:45:06 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_sorting_4_numbers(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	number_d;
// 	t_stack	*temp;

// 	//TO DO
// }

void	ft_find_min_number(t_stack **stack)
{
	int	min_number;
	t_stack	*temp;

	temp = (*stack);
	min_number = temp->number;
	while (temp)
	{
		if (min_number > temp->number)
			min_number = temp->number;
		temp = temp->next;
	}
}

void	ft_sorting_3_numbers(t_stack **stack_a)
{
	int		number_a;
	int		number_b;
	int		number_c;
	t_stack	*temp;

	temp = (*stack_a);
	number_a = (temp)->number;
	number_b = (temp)->next->number;
	number_c = (temp)->next->next->number;
	if (number_a > number_b && number_a < number_c)
		ft_swap(stack_a, 'a');
	else if (number_a > number_c && number_b < number_c)
		ft_rotate(stack_a, 'a');
	else if (number_a > number_c && number_b > number_c && number_a < number_b)
		ft_reverse(stack_a, 'a');
	else if (number_a > number_c && number_b > number_c && number_a > number_b)
	{
		ft_rotate(stack_a, 'a');
		ft_swap(stack_a, 'a');
	}
	else if (number_a < number_c && number_b > number_c && number_a < number_b)
	{
		ft_reverse(stack_a, 'a');
		ft_swap(stack_a, 'a');
	}
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
void	ft_sorting_2_numbers(t_stack **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		ft_swap(stack_a, 'a');
		ft_printf("sa");
	}
}

t_stack	*string_to_stack(t_stack *stk_a, char *argv[])
{
	int		i;
	char	**array;
	int		nb;

	array = ft_split(*argv, ' ');
	i = 0;
	while (array[i])
	{
		nb = ft_atoi(array[i]);
		if (stk_a == NULL)
			stk_a = new_node(ft_atoi(array[i]));
		else
			stk_a = add_to_stack(stk_a, nb);
		i++;
	}
	ft_free_split(array);
	return (stk_a);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			j;
	int			error;
	t_stack		*st_b;
	t_stack		*st_a;

	i = 1;
	j = 1;
	st_a = NULL;
	st_b = NULL;
	if (argc < 2)
		exit(1);
	while (j < argc)
	{
		ft_number_checker(argv[j]);
		j++;
	}
	if (argc == 2)
		st_a = string_to_stack(st_a, &argv[1]);
	if (argc > 2)
	{
		if (st_a == NULL)
			st_a = new_node(ft_atoi(argv[i]));
		// if (st_b == NULL)
		// 	st_b = new_node(ft_atoi(argv[i]));
		i++;
		while (i < argc)
		{
			st_a = add_to_stack(st_a, ft_atoi(argv[i]));
			i++;
		}
	}
	ft_check_duplicates(st_a);
	// print_numbers(st_a);
	
	error = ft_stack_sorted(st_a);
	if (error == 0)
	{
		// ft_sorting_2_numbers(&st_a);
		ft_sorting_3_numbers(&st_a);
	}

/////////////////////////////////////////////////////////////
	// ft_printf("%s\n", "---");
	// print_numbers(st_a);
	// ft_sorting_2_numbers(&st_a);
	// ft_sorting_3_numbers(&st_a, &st_b);
	// ft_printf("%s\n", "---");
	// print_numbers(st_a);
	// ft_printf("%s\n", "---");
	// ft_rotate(&st_b);
	// ft_printf("counter nodes %d", node_counter(st_a));
	// ft_printf("%s\n", "---");
	// ft_rotate(&st_a);
	// print_numbers(st_a);
	// ft_printf("%s\n", "---");
	// ft_reverse(&st_a);
	// print_numbers(st_a);
	// ft_printf("%s\n", "---");
	// ft_swap(&st_a);
	// print_numbers(st_a);
	// ft_push(&st_a, &st_b);
	// ft_printf("%s\n", "--- stack b");
	// print_numbers(st_b);
	// ft_printf("%s\n", "--- stack a");
	// print_numbers(st_a);
	// ft_push(&st_a, &st_b);
	// ft_printf("%s\n", "--- stack b");
	// print_numbers(st_b);
	// ft_printf("%s\n", "--- stack a");
	// print_numbers(st_a);
	ft_free_stack(&st_a);
	exit(0);
}
