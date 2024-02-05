/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/05 15:56:42 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_stack *stack)
{
	t_stack *current;
	t_stack *temp;

	current = stack;
	while(current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->number == temp->number)
			{
				ft_printf("Error\n");
				// TODO: free sta stb
				return (-1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}

int	input_verification(char *arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		if (arguments[i] == ' ' | arguments[i] == '-' | arguments[i] == '+')
				i++;
		if (ft_isdigit(arguments[i]) != 1)
		{
			ft_printf("%s\n", "Error");
			return (-1);
		}
		else if (ft_atol(&arguments[i]) == INT_MAX || ft_atol(&arguments[i]) == INT_MIN)
		{
			ft_printf("%s\n", "Error");
			return (-1);
		}
		i++;
	}
	return (1);
}
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
int	main(int argc, char **argv)
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
		error = input_verification(argv[j]);
		if (error == -1)
			exit(1);
		j++;
	}
	if (argc == 2)
		st_a = string_to_stack(st_a, &argv[1]);
	else if (argc > 2)
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
	ft_printf("%s\n", "---");
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
