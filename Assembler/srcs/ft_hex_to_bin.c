/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:26:32 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 09:27:23 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

char	*rec_h2b(int num, char *ans)
{
	char	*tmp;

	if (!num)
		return (ans);
	if (num % 2)
		tmp = ft_strjoin("1", ans);
	else
		tmp = ft_strjoin("0", ans);
	free(ans);
	ans = ft_strdup(tmp);
	free(tmp);
	return (rec_h2b(num / 2, ans));
}

char	*ft_hex_to_bin(char *hex)
{
	char	*ans;
	int		num;
	char	*beg;

	num = ft_atoi_base(hex, 16);
	beg = ft_strnew(0);
	ans = ft_strdup(rec_h2b(num, beg));
	while (ft_strlen(ans) % 4)
	{
		free(beg);
		beg = ft_strjoin("0", ans);
		free(ans);
		ans = ft_strdup(beg);
	}
	free(beg);
	return (ans);
}
