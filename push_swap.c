/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/01/30 16:52:31 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_verification(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		ft_printf("%s\n", arguments[i]);
		// if(ft_isdigit(*arguments[i]) == 1)
		// {
		// 	ft_printf("%s\n", "ERROR, Wrong Input");
		// 	// return (-1);
		// }
		i++;
	}
	// return (1);
}

t_stack	*string_to_stack(t_stack *stk_a, char **argv)
{
	int		i;
	char **array;
	int nb;
	
	
	array = ft_split(*argv, ' ');
	i = 0;
	while(array[i])
	{
		// if (input_verification(&array[i]) == -1)
		// 	break ;
		nb = ft_atoi(array[i]);
		if (stk_a == NULL)
			stk_a = new_node(ft_atoi(array[i]));
		else
			stk_a = add_to_stack(stk_a, nb);
		i++;
	}
	free(array);
	return (stk_a);
	// i = 0;
	// if (argc == 2)
	// 	argv = ft_split(argv[1], ' ');
	// else
	// 	i = 1;
	// while (i < argc)
	// {
	// 	tmp = atoi(argv[i]);
	// 	if(ft_isdigit(tmp) == 1)
	// 	{
	// 		ft_printf("%s\n", "ERROR");
	// 		return ;
	// 	}
	// 	i++;
	// }
}

void	ft_reverse(t_stack **head)
{
	t_stack *new_tail;
	t_stack *temp;

	if (*head == NULL)
		return ;
	temp = *head;
	while (temp->next != NULL)
	{
		new_tail = temp;
		temp = temp->next;
	}
	temp->next = *head;
	new_tail->next = NULL;
	*head = temp;
}
void	ft_rotate(t_stack **head)
{
	t_stack *first;
	t_stack *temp;

	if (*head == NULL)
		return ;
	first = *head;
	temp = *head;
	*head = (*head)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}
void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack *temp;

	if (*stack_from == NULL)
		return ;

	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
		*stack_to = temp;
	else
	{
		temp->next = *stack_to;
		*stack_to = temp;
	}
}
void	ft_swap(t_stack **head)
{
	t_stack *temp;

	if (*head == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}
void	print_numbers(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while(temp != NULL)
	{
		ft_printf("%d\n", temp->number);
		temp = temp->next;
	}
	// need to free allocation for temp?
}
int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	t_stack *st_a;
	t_stack *st_b;

	st_a = NULL;
	st_b = NULL;
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
			input_verification(&argv[i]);
			st_a = add_to_stack(st_a, ft_atoi(argv[i]));
			i++;
		}
	}
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
}
