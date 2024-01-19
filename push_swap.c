/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 15:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/01/19 17:07:50 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	// if (argc < 2)
	// 	return (0);
// checar input;
	t_stack *a;
	t_stack *b;
	t_stack *tmp;
	int		i;

	i = 0;
	a = new_node(5);
	tmp = a;
	while (i < 10)
	{
		tmp->next = new_node(i);
		tmp = tmp->next;
		i++;
	}

	tmp = a;
	while (1)
	{
		printf("num: %d\n", tmp->number);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	

}
