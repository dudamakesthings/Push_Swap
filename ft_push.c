/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 10:27:50 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/05 10:29:11 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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