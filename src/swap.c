/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/16 10:26:47 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
#include "./../include/push_swap.h"

void	swap(t_element **stack, char instruction)
{
	int	temp;
	
	if(*stack == NULL || (*stack)->next == *stack)
	return ;
	
	temp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = temp;
	printf("s%c\n", instruction);
}



// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

void	rotate(t_element **stack, char instruction)
{
	*stack = (*stack)->next;
	printf("r%c\n", instruction);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.


void	reverse_rotate(t_element **stack, char instruction)
{
	*stack = (*stack)->prev;
	printf("rr%c\n", instruction);
}

// pa (push a) : Prend le premier élément au sommet de src et le met sur dst.
// Ne fait rien si dst est vide.
void	push(t_element **src, t_element **dst, char instruction)
{
	t_element	*node;

	if (*src == NULL)
		return ;
	node = *src;
	if (node->next == node)
		*src = NULL;
	else
	{
		*src = node->next;
		(*src)->prev = node->prev;
		(*src)->prev->next = *src;
	}
	if (*dst == NULL)
	{
		node->next = node;
		node->prev = node;
		*dst = node;
	}
	else
		dst_not_empty(dst, node);
	printf("p%c\n", instruction);
}

// put node at the top of dst.
void	dst_not_empty(t_element **dst, t_element *node)
{
		node->next = *dst;
		node->prev = (*dst)->prev;
		(*dst)->prev->next = node;
		(*dst)->prev = node;
		*dst = node;
}
