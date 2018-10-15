/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataTime.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 09:19:22 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/14 09:19:26 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataTime.hpp"

void	DataTime::initRect(int x, int y)
{
	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 60;
	_genRect.w = 420;
	_place_data.x = x + 140;
	_place_data.y = y + 5;
	_place_data.h = 70;
	_place_data.w = 70;
	_place_time.x = x + 140;
	_place_time.y = y + 30;
	_place_time.h = 70;
	_place_time.w = 70;
	_text_data = NULL;
	_text_time = NULL;
	return;
}

DataTime::DataTime(void)
{
	return;
}

DataTime::DataTime(int x, int y)
{
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(x, y);
}

DataTime::DataTime(const DataTime &object)
{
	*this = object;
	return ;
}

DataTime& DataTime::operator=(DataTime const &obj)
{
	if (&obj != this)
	{
		this->_time = obj._time;
		this->_data = obj._data;
		this->_text_data = obj._text_data;
		this->_text_time = obj._text_time;
		this->_color = obj._color;
		this->_font = obj._font;
		this->_place_data = obj._place_data;
		this->_place_time = obj._place_time;
		this->_genRect = obj._genRect;
	}
	return (*this);
}

void	DataTime::defineDataStr(void)
{
	std::time_t	current = std::time(0);
	std::tm	*time_struct = localtime(&current);
	std::string		data;
	std::string		time;
	int				hour;
	int				min;

	data += std::to_string(time_struct->tm_year + 1900) + "-"
			+ std::to_string(time_struct->tm_mon + 1) + "-" + std::to_string(time_struct->tm_mday);
	data += "  ";
	if ((hour = time_struct->tm_hour) < 10)
		time += std::to_string(0) + std::to_string(time_struct->tm_hour);
	else
		time += std::to_string(time_struct->tm_hour);

	if ((min = time_struct->tm_min) < 10)
		time +=  " : " + std::to_string(0) + std::to_string(time_struct->tm_min);
	else
		time += " : " + std::to_string(time_struct->tm_min);
	if ((min = time_struct->tm_sec) < 10)
		time +=  " : " + std::to_string(0) + std::to_string(time_struct->tm_sec);
	else
		time += " : " + std::to_string(time_struct->tm_sec);
	this->_data = new char[data.length() + 1];
	std::strcpy(this->_data, data.c_str());
	this->_time = new char[time.length() + 1];
	std::strcpy(this->_time, time.c_str());
}

void	DataTime::defineData(void)
{
	std::time_t	current = std::time(0);
	std::tm	*time_struct = localtime(&current);
	std::string		data;
	std::string		time;
	int				hour;
	int				min;

	if (_text_data)
	{
		delete [] this->_data;
		SDL_FreeSurface(_text_data);
	}
	if (_text_time)
	{
		delete [] this->_time;
		SDL_FreeSurface(_text_time);
	}
	data += std::to_string(time_struct->tm_year + 1900) + "-"
	+ std::to_string(time_struct->tm_mon + 1) + "-" + std::to_string(time_struct->tm_mday);
	data += "  ";
	if ((hour = time_struct->tm_hour) < 10)
		time += std::to_string(0) + std::to_string(time_struct->tm_hour);
	else
		time += std::to_string(time_struct->tm_hour);

	if ((min = time_struct->tm_min) < 10)
		time +=  " : " + std::to_string(0) + std::to_string(time_struct->tm_min);
	else
		time += " : " + std::to_string(time_struct->tm_min);
	if ((min = time_struct->tm_sec) < 10)
		time +=  " : " + std::to_string(0) + std::to_string(time_struct->tm_sec);
	else
		time += " : " + std::to_string(time_struct->tm_sec);
	this->_data = new char[data.length() + 1];
	std::strcpy(this->_data, data.c_str());
	this->_time = new char[time.length() + 1];
	std::strcpy(this->_time, time.c_str());
	
	if (!(_text_data = TTF_RenderText_Solid(this->_font, this->_data, this->_color)))
		throw std::out_of_range("Error: Text error!");
	if (!(_text_time = TTF_RenderText_Solid(this->_font, this->_time, this->_color)))
		throw std::out_of_range("Error: Text error!");
}

void			DataTime::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

DataTime::~DataTime(void)
{
	if (this->_data)
		delete [] this->_data;
	if (this->_time)
		delete [] this->_time;
}

SDL_Surface		*DataTime::getTextData(void)
{
	return(this->_text_data);
}

SDL_Surface		*DataTime::getTextTime(void)
{
	return(this->_text_time);
}

SDL_Color		DataTime::getColor(void)
{
	return(this->_color);
}

char* DataTime::getTime() {

	return _time;
}

char* DataTime::getData() {

	return _data;
}
