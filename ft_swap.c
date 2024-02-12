/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 10:25:05 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/12 18:37:44 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head, char letter)
{
	t_stack *temp;

	if (*head == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	ft_printf("s%c", letter);
}