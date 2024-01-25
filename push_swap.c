/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/01/25 16:45:57 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse(t_stack **head)
{
	t_stack *new_tail;
	t_stack *temp;

	if(*head == NULL)
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
void ft_rotate(t_stack **head)
{
	t_stack *first;
	t_stack *temp;

	if(*head == NULL)
		return ;
	first = *head;
	temp = *head;
	*head = (*head)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}
void ft_push(t_stack **stack_from, t_stack **stack_to)
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
void ft_swap(t_stack **head)
{
	t_stack *temp;

	if (*head == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}
void print_numbers(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while(temp != NULL)
	{
		ft_printf("%d\n", temp->number);
		temp = temp->next;
	}
}
int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2)
		return (0);
// checar input;
	t_stack *st_a;
	t_stack *st_b;

	st_a = NULL;
	st_b = NULL;
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
/////////////////////////////////////////////////////////////
	print_numbers(st_a);
	ft_printf("%s\n", "---");
	ft_rotate(&st_a);
	print_numbers(st_a);
	ft_printf("%s\n", "---");
	ft_reverse(&st_a);
	print_numbers(st_a);
	ft_printf("%s\n", "---");
	ft_swap(&st_a);
	print_numbers(st_a);
	ft_push(&st_a, &st_b);
	ft_printf("%s\n", "--- stack b");
	print_numbers(st_b);
	ft_printf("%s\n", "--- stack a");
	print_numbers(st_a);
}
