/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:13:27 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 16:34:18 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

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

char	*hex_to_bin(char *hex)
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
