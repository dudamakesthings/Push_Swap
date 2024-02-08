/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/08 12:09:03 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_3_numbers(t_stack **stack_a)
{
	int	min_number;
	t_stack	*temp;
	t_stack *current;

	current = *stack_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->number > temp->number)
			{
				min_number = temp->number;
				ft_printf("\n%d", min_number);
				if (min_number > current->number)
					min_number = current->number;
			}
			temp = temp->next;
		}
		// ft_printf("\n%d", current->number);
		current = current->next;
	}
	// ft_printf("\n%d", min_number);
}
void	ft_sorting_2_numbers(t_stack **stack_a)
{

	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		ft_swap(stack_a);
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
	while(array[i])
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
	int i;
	int j;

	i = 1;
	j = 1;
	if (argc < 2)
		exit(1);
	t_stack *st_a;
	t_stack *st_b;

	st_a = NULL;
	st_b = NULL;
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
/////////////////////////////////////////////////////////////
	ft_printf("%s\n", "---");
	// print_numbers(st_a);
	//ft_sorting_2_numbers(&st_a);
	ft_sorting_3_numbers(&st_a);
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
