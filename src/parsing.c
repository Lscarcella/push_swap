/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscarcel <lscarcel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:20 by lscarcel          #+#    #+#             */
/*   Updated: 2024/04/02 16:04:26 by lscarcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	init_struct(t_element *element)
{
	ft_memset(&element, 0, sizeof(element));
}
void	check_and_store_arg(t_element *element, char **argv)
{
	check_arg(argv);
	store_arg(element, argv);
}
void check_arg(char **argv)
{
	int i;
	int j;

	j = 1;
	while(argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if(argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			if(argv[j][i] < '0' || argv[j][i] > '9' )
			{
				printf(COLOR_RED"Error\n"TEXT_RESET);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

void store_arg(t_element *element, char **argv)
{
	int i;

	i = 0;
	t_element* head = NULL;
	t_element* current = NULL;
    while (argv[i])
    {
        t_element* new_element = (t_element*)malloc(sizeof(t_element));
        if (!new_element)
            exit(EXIT_FAILURE);
        new_element->value = ft_atol(argv[i]); 
        if (!head)
        {
            head = new_element;
            current = new_element;
        }
        else
        {
            current->next = new_element;
            current = new_element;
        }
        i++;
    }
    *element = *head;
}
