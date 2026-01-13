/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:13:16 by equentin          #+#    #+#             */
/*   Updated: 2026/01/13 18:35:28 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_bit_at(int value, int bit_pos)
{
	int r;

	r = 0;
	while (value > 0 && bit_pos-- >= 0)
	{
		r = value % 2;
		value /= 2;
	}
	if (value == 0 && bit_pos >= 0)
		return (0);
	return (r);
}
