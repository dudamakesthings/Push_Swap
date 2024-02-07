/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 13:43:21 by edribeir      #+#    #+#                 */
/*   Updated: 2024/02/07 14:23:24 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;

	head = *stack;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
	free(head);
}

void	ft_free_split(char **array)
{
	int	i;
	
	i = 0;
	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}