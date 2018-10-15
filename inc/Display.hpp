/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:29:46 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/13 16:29:47 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <exception>
#include "DataTime.hpp"
#include "OS_info.hpp"
#include "Hostname.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "Network.hpp"
#include "Processes.hpp"
#include <vector>

class Display
{
	private:
		SDL_Window		*_window;
		SDL_Surface		*_screen;
		SDL_Surface		*_s;
		SDL_Surface		*_cover;
		int				_width;
		int				_height;
		TTF_Font		*_font;
		SDL_Color		_color_main;
		SDL_Color		_color_ad;
		const Uint8		*_kb_state;
		SDL_Event 		_event;
		int				_program_run;
		DataTime 		*_objDT;
		OS_info 		*_objOS;
		Hostname		*_objHost;
		CPU				*_objCPU;
		RAM				*_objRAM;
		Network			*_objNetwork;
		Processes		*_objProcesses;

		SDL_Surface		*_Cover1;
		SDL_Surface		*_Cover2;
		SDL_Surface		*_Cover3;
		SDL_Surface		*_Cover4;

	public:
		Display(void);
		Display(int width, int height);
		~Display(void);
		Display(const Display &object);
		Display& operator=(Display const &obj);

		SDL_Window		*getWindow(void);
		void			init(void);
		void			updateWindow(void);
		void			AddText(SDL_Surface *text, SDL_Rect place);
		TTF_Font		*getFont(void);
		void			setDataObj(DataTime *objDT);
		void			setDataOs(OS_info *objOS);
		void			setHost(Hostname *objHost);
		void			setCPU(CPU *objCPU);
		void			setRAM(RAM *objRAM);
		void			setNetwork(Network *objNetwork);
		void			setProcesses(Processes *objProcesses);
		void			ft_putpixel(int x, int y, SDL_Surface *screen, SDL_Color color);
		SDL_Color		ft_color_from_texture(int t_x, int t_y, SDL_Surface *text);
		void			ft_print_img(SDL_Surface *img, int dx, int dy);
		void			ft_print_anim(SDL_Surface *img, int dx, int dy);

		void			Rendertextinfo(void);
		void			CreateText(char *str, int x, int y);
		void			graphic(int x, int y, std::vector<int> data_vector);

};

#endif

