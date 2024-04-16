/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:43:58 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/16 13:22:27 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	little_sort(t_element *stack, int argc)
{
	if (argc == 3 && stack->value > stack->prev->value)
	{
		swap(&stack, 'a');
		exit(EXIT_SUCCESS);	
	}
	if(argc == 4)
	{
		three_int_sort(stack);
		exit(EXIT_SUCCESS);	
	}
	else if(argc == 6)
	{
		five_int_sort(stack);
		exit(EXIT_SUCCESS);	
	}
}
void	three_int_sort(t_element *stack)
{
	int a = stack->value;
	int b = stack->next->value;
	int c = stack->prev->value;

	if (a < b && b < c)
		return ;
	else if (a > b && c > a)
		swap(&stack, 'a');
	else if (a > c && c > b)
		rotate(&stack, 'a');
	else if (a < b && a > c)
			reverse_rotate(&stack, 'a');
	else if (a > b && b > c)
	{
		swap(&stack, 'a');
		reverse_rotate(&stack, 'a');
	}
	else if (a < b && a < c)
	{
		swap(&stack, 'a');
		rotate(&stack, 'a');
	}
}

void	five_int_sort(t_element *stack_a)
{
	t_element *stack_b;

	stack_b = NULL;

	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	three_int_sort(stack_a);
	push(&stack_b, &stack_a, 'a');
	push(&stack_b, &stack_a, 'a');
}
