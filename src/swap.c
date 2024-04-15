/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:46:44 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/12 12:02:04 by lscarcel         ###   ########.fr       */
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
	
	temp = (*top_of_stack)->next->value;
	(*top_of_stack)->next->value = (*top_of_stack)->value;
	(*top_of_stack)->value = temp;
	printf("s%c\n", instruction);
}



// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

void	rotate(t_element **top_of_stack, char instruction)
{
	*top_of_stack = (*top_of_stack)->next;
	printf("r%c\n", instruction);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.


void	reverse_rotate(t_element **top_of_stack, char instruction)
{
	*top_of_stack = (*top_of_stack)->prev;
	printf("rr%c\n", instruction);
}

// pa (push a) : Prend le premier élément au sommet de src et le met sur dst.
// Ne fait rien si dst est vide.
// void	push(t_element **src, t_element **dst, char instruction)
// {
// 	t_element	*node;

// 	if (*src == NULL)
// 		return ;
// 	node = *src;
// 	if (node->next == node)
// 		*src = NULL;
// 	else
// 	{
// 		*src = node->next;
// 		(*src)->prev = node->prev;
// 		(*src)->prev->next = *src;
// 	}
// 	if (*dst == NULL)
// 	{
// 		node->next = node;
// 		node->prev = node;
// 		*dst = node;
// 	}
// 	else
// 		dst_not_null(dst, node);
// 	printf("p%c\n", instruction);
// }

// // put node at the top of dst.
// void	dst_not_empty(t_element **dst, t_element *node)
// {
// 		node->next = *dst;
// 		node->prev = (*dst)->prev;
// 		(*dst)->prev->next = node;
// 		(*dst)->prev = node;
// 		*dst = node;
// }
