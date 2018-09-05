/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:35:16 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 09:22:40 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cw.h"

char	*decode_byte(char *in)
{
	char	binary[16][5];
	char	*hex;
	char	*out;
	int		i;
	int		j;

	if (ft_strlen(in) == 2)
	{
		char binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
		hex = "0123456789abcdef";
		out = (char *)malloc(sizeof(char) * 9);
		i = 0;
		while (i < 8)
		{
			j = 0;
			while (j < 17)
			{
				if (in[i] == hex[j])
				{
					out[i] = binary[j];
					i += 4;
				}
				j++;
			}
		}
		out[9] = '\0';
	}
	return (out);
}

int main(){}