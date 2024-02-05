/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 10:29:38 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/05 10:31:02 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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