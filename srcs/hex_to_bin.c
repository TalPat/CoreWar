/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:13:27 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 13:55:07 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

char	*rec_hb(int num, char *ans)
{
	char	*tmp;

	if (!num)
		return (ans);
	if (num % 2)
		tmp = ft_strjoin("1", ans);
	else
		tmp = ft_strjoin("0", ans);
	return (rec_hb(num / 2, tmp));
}

char	*hex_to_bin(char *hex)
{
	char	*ans;
	int		num;

	num = ft_atoi_base(hex, 16);
	ans = rec_hb(num, "");
	while (ft_strlen(ans) % 4)
		ans = ft_strjoin("0", ans);
	return (ans);
}
