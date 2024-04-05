/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/04 12:19:48 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
#include "./../include/push_swap.h"

void	swap(t_element **tail, char instruction)
{
	int	temp;
	
	if(*tail == NULL || (*tail)->next == *tail)
	return ;
	
	temp = (*tail)->prev->value;
	(*tail)->prev->value = (*tail)->value;
	(*tail)->value = temp;
	printf("s%c\n", instruction);
}


void	rotate(t_element **tail, char instruction)
{
	if(*tail == NULL || (*tail)->next == *tail)
	return ;
	*tail = (*tail)->next;
	printf("r%c\n", instruction);
}

