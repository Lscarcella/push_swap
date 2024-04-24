/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:39:11 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/24 17:32:30 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int find_largest_bit(t_element **stack_a, int stack_len)
{
	t_element *current;
    int bit_len;
    int nombre_max;
	int i;
	
	i = 0;
	nombre_max = 0;
	bit_len = 0;

   	current = *stack_a;

    while (i < stack_len)
	{
        if (current->simplified_value > nombre_max)
            nombre_max = current->simplified_value;
        current = current->next;
		i++;
    }
    while (nombre_max > 0)
	{
        nombre_max >>= 1;
        bit_len++;
    }
    return (bit_len - 1);
}


void radix_sort(t_element **stack_a, int stack_len)
{
	t_element *stack_b = NULL;
	int bit = 0;
	int last_bit = find_largest_bit(stack_a, stack_len);

	while (bit <= last_bit)
	{
		int i = stack_len;
		while (i > 0)
		{
			if (((*stack_a)->simplified_value >> bit) % 2 == 0)
				push(stack_a, &stack_b, 'b');
			else
				rotate(stack_a, 'a');
			i--;
		}

		while (stack_b != NULL)
			push(&stack_b, stack_a, 'a');

		bit++;
	}
}



