/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lozkuro <lozkuro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/05 14:49:54 by lozkuro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
#include "./../include/push_swap.h"

void	swap(t_element **top_of_stack, char instruction)
{
	int	temp;
	
	if(*top_of_stack == NULL || (*top_of_stack)->next == *top_of_stack)
	return ;
	
	temp = (*top_of_stack)->prev->value;
	(*top_of_stack)->prev->value = (*top_of_stack)->value;
	(*top_of_stack)->value = temp;
	printf("s%c\n", instruction);
}

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

void	rotate(t_element **top_of_stack, char instruction)
{
	*top_of_stack = (*top_of_stack)->prev;
	printf("r%c\n", instruction);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.


void	reverse_rotate(t_element **top_of_stack, char instruction)
{
	*top_of_stack = (*top_of_stack)->next;
	printf("rr%c\n", instruction);
}