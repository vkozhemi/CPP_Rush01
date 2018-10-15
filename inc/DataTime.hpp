/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataTime.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 00:04:56 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/14 00:04:58 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATIME_HPP
#define DATATIME_HPP
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <exception>
#include <iostream>
#include <time.h>
#include "IMonitorModule.hpp"

class DataTime : public IMonitorModule
{
	public:
		DataTime(void);
		DataTime(int x, int y);
		~DataTime(void);
		DataTime(const DataTime &object);
		DataTime& operator=(DataTime const &obj);

		void			defineData(void);
		SDL_Surface		*getTextData(void);
		SDL_Surface		*getTextTime(void);
		SDL_Color		getColor(void);
		void			setFont(TTF_Font *font);
		void			initRect(int x, int y);
		void			defineDataStr(void);
		char * 			getTime(void);
		char * 			getData(void);


	SDL_Rect		_place_data;
		SDL_Rect		_place_time;
		SDL_Rect		_genRect;
	
	private:
		char			*_time;
		char			*_data;
		SDL_Surface		*_text_data;
		SDL_Surface		*_text_time;
		SDL_Color		_color;
		TTF_Font		*_font;
};

#endif