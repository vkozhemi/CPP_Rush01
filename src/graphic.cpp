/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:20:48 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/14 16:20:49 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		graphic(int x, int y, int height, std::vector<int> data_vector)
{
	std::vector<int >::iterator it = _info.begin();
	std::vector<int >::iterator ite = _info.end();
	int		dx;

	while(it != ite)
	{
		dy = height * (*it) + y;
		dx = x + 10;
		while (dy > y)
		{
			while (x < dx)
			{
				ft_putpixel(x, y, this->_screen, this->_color);
				x++;
			}
			dy--;
		}
	}
}
