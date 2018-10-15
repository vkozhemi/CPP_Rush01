/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:53:10 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/13 23:53:11 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule
{
	virtual void			defineData(void) = 0;
	virtual SDL_Color		getColor(void) = 0;
	virtual void			setFont(TTF_Font *font) = 0;
	virtual	void			initRect(int x, int y) = 0;
};

#endif
