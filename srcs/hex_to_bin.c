/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:13:27 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 11:31:25 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char    *hex_to_bin(char *hex)
{
    char binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	char *hexref = "0123456789abcdef";
    char *ptr;
    int i = 0;
    int j = 0;
    char *ans = NULL;

    while (*(hex + i))
    {
        //ptr = ft_strchr(hexref, *(hex + i));
        while (*(hexref + j) != *(hex + i))
            j++;
        ans = ft_strjoin(ans, binary[j]);
        i++;
    }
    return (ans);
}

int main(void)
{
    char *ans;
    char *hex = "FF";
    ans = hex_to_bin(hex);
    ft_putstr(ans);
}