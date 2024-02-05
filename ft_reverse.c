/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 10:31:54 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/05 11:25:35 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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