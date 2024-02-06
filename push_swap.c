/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/06 17:34:48 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_bubble_sorting(t_stack *stack)
// {
// 	t_stack	*number_a;
// 	t_stack	*number_b;
// 	int nodes;
// 	int i;
// 	int j;
	
// 	i = 0;
// 	j = 0;
// 	number_a = stack;
// 	nodes = node_counter(stack);
// 	while (i < nodes - 1)
// 	{
// 		number_b = number_a->next;
// 		while (j < nodes - i - 1)
// 		{
// 			if ()
// 			number_b = number_b->next;
// 			j++;
// 		}
// 		number_a = number_a->next;
// 		i++;
// 	}
// }
t_stack	*string_to_stack(t_stack *stk_a, char **argv)
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
	free(array);
	return (stk_a);
}
int	main(int argc, char *argv[])
{
	int i;
	int j;
	int error;
	// char *str;

	// str = calloc(10, 1);
	// printf("%c", str[5]);
	// free(str);
	// return (0);

	i = 1;
	j = 1;
	if (argc < 2)
		exit(1);
	t_stack *st_a;
	// t_stack *st_b;

	st_a = NULL;
	// st_b = NULL;
	while (j < argc)
	{
		error = ft_number_checker(argv[j]);
		if (error == -1)
			exit(1);
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
	error = ft_check_duplicates(st_a);
	if (error == -1)
		exit(1);
/////////////////////////////////////////////////////////////
	ft_printf("%s\n", "---");
	print_numbers(st_a);
	ft_printf("counter nodes %d", node_counter(st_a));
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
	exit(0);
}
