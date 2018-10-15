/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:29:35 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/13 16:29:36 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

void			Display::init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if(!(this->_window = SDL_CreateWindow("ft_gkrellm", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, this->_width, this->_height, SDL_WINDOW_SHOWN)))
		throw std::out_of_range("Error: Init error!");
	if (!(this->_screen = SDL_GetWindowSurface(_window)) || TTF_Init() < 0)
		throw std::out_of_range("Error: Init error!");
	if (!(this->_font = TTF_OpenFont("OpenSans.ttf", 18)))
		throw std::out_of_range("Error: There is not such font!");
	SDL_memset(this->_screen->pixels, 0, this->_screen->h * this->_screen->pitch);
	
	if (!(this->_cover = SDL_LoadBMP("cover.bmp")) || !(this->_Cover1 = SDL_LoadBMP("1.bmp"))
		|| !(this->_Cover2 = SDL_LoadBMP("2.bmp")) || !(this->_Cover3 = SDL_LoadBMP("3.bmp"))
		|| !(this->_Cover4 = SDL_LoadBMP("4.bmp")))
		throw std::out_of_range("Error: There is not such image!");
	this->_color_main.r = 150;
	this->_color_main.g = 150;
	this->_color_main.b = 150;
	this->_color_ad.r = 171;
	this->_color_ad.g = 91;
	this->_color_ad.b = 82;
	this->_kb_state = SDL_GetKeyboardState(NULL);
	this->_program_run = 1;
	this->_s = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
	return;
}

Display::Display(void) : _width(500), _height(500) 
{
	this->init();
	return;
}

Display::Display(int width, int height) : _width(width), _height(height)
{
	this->init();
	return;
}

void		Display::setDataObj(DataTime *objDT)
{
	this->_objDT = objDT;
	return;
}

void		Display::setDataOs(OS_info *objOS)
{
	this->_objOS = objOS;
	return;
}

void		Display::setHost(Hostname *objHost)
{
	this->_objHost = objHost;
	return;
}

void			Display::setCPU(CPU *objCPU)
{
	this->_objCPU = objCPU;
	return;
}

void			Display::setRAM(RAM *objRAM)
{
	this->_objRAM = objRAM;
	return;
}

void			Display::setNetwork(Network *objNetwork)
{
	this->_objNetwork = objNetwork;
	return;
}

void			Display::setProcesses(Processes *objProcesses)
{
	this->_objProcesses = objProcesses;
	return;	
}

TTF_Font		*Display::Display::getFont(void)
{
	return (this->_font);
}

Display::Display(const Display &object)
{
	*this = object;
	return;
}

Display::~Display(void)
{
	// SDL_FreeSurface(this->_screen);
	// SDL_DestroyWindow(this->_window);
	// TTF_CloseFont(this->_font);
	return;
}

Display & Display::operator=(Display const &obj)
{
	if (&obj != this)
	{
		if (this->_screen)
			SDL_FreeSurface(this->_screen);
		this->_screen = obj._screen;
		this->_width = obj._width;
		this->_height = obj._height;
	}
	return (*this);
}

SDL_Window		*Display::getWindow(void)
{
	return(this->_window);
}

void			Display::AddText(SDL_Surface *text, SDL_Rect place)
{
	SDL_BlitSurface(text, NULL, this->_screen, &place);
	return;
}

void			Display::CreateText(char *str, int x, int y)
{
	SDL_Rect		place;
	SDL_Surface		*surf;

	place.x = x;
	place.y = y;
	place.h = 20;
	place.w = 50;
	if (!(surf = TTF_RenderText_Solid(this->_font, str, this->_color_main)))
		throw std::out_of_range("Error: Text error!");
	this->AddText(surf, place);
	SDL_FreeSurface(surf);
	return;
}

void			Display::Rendertextinfo(void)
{
	char		str_user[] = "User name: ";
	char		str_host[] = "Host name: ";
	char		str_data[] = "Data: ";
	char		str_time[] = "Time: ";
	char		str_os[] = "OS Info ";
	char		str_cor[] = "Nbr cores: ";
	char		str_tr[] = "Total RAM: ";
	char		str_ur[] = "Used RAM: ";
	char		str_ptr[] = "Packets/Traffic";
	char		str_proc[] = "Processes/Disk";

	CreateText(str_time, 60, 15);
	CreateText(str_data, 60, 40);
	CreateText(str_user, 60, 195);
	CreateText(str_host, 60, 175);
	CreateText(str_os, 60, 85);
	CreateText(str_cor, 60, 315);
	CreateText(str_tr, 60, 470);
	CreateText(str_ur, 60, 500);
	CreateText(str_ptr, 175, 560);
	CreateText(str_proc, 175, 640);

	return;
}

void			Display::updateWindow(void)
{
	int		i = 0;
	_objHost->defineData();
	_objOS->defineData();
	_objCPU->defineDataStat();
	_objRAM->defineDataStat();
	while(this->_program_run)
	{
		ft_print_img(this->_cover, 0, 0);
		SDL_FillRect(this->_screen, &(_objDT->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		_objDT->defineData();
		AddText(_objDT->getTextData(), _objDT->_place_data);
		AddText(_objDT->getTextTime(), _objDT->_place_time);

		SDL_FillRect(this->_screen, &(_objOS->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objOS->getProductName(), _objOS->_place_productName);
		AddText(_objOS->getProductVersion(), _objOS->_place_productVersion);
		AddText(_objOS->getBuildVersion(), _objOS->_place_buildVersion);

		SDL_FillRect(this->_screen, &(_objHost->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objHost->getHostname(), _objHost->_place_hostName);
		AddText(_objHost->getUsername(), _objHost->_place_userName);
		
		SDL_FillRect(this->_screen, &(_objHost->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objHost->getHostname(), _objHost->_place_hostName);
		AddText(_objHost->getUsername(), _objHost->_place_userName);

		_objCPU->defineData();
		SDL_FillRect(this->_screen, &(_objCPU->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objCPU->getCPU(), _objCPU->_place_CPU);
		AddText(_objCPU->getNcpu(), _objCPU->_place_Ncpu);
		AddText(_objCPU->getBrand(), _objCPU->_place_Brand);
		this->graphic(80, 430, _objCPU->getVector());
		
		_objRAM->defineData();
		SDL_FillRect(this->_screen, &(_objRAM->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objRAM->getTot(), _objRAM->_place_Tot);
		AddText(_objRAM->getUsed(), _objRAM->_place_Used);

		_objNetwork->defineData();
		SDL_FillRect(this->_screen, &(_objNetwork->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objNetwork->getNetwork(), _objNetwork->_place_Network);

		_objProcesses->defineData();
		SDL_FillRect(this->_screen, &(_objProcesses->_genRect), SDL_MapRGB(_s->format, 69, 70, 64));
		AddText(_objProcesses->getProcesses(), _objProcesses->_place_Processes);
		AddText(_objProcesses->getDisk(), _objProcesses->_place_Disk);



		this->Rendertextinfo();

		if (i % 2 == 0)
			ft_print_anim(this->_Cover1, 200, 700);
		else if (i % 5 == 0)
			ft_print_anim(this->_Cover2, 200, 700);
		else if (i % 7 == 0)
			ft_print_anim(this->_Cover3, 200, 700);
		else
			ft_print_anim(this->_Cover4, 200, 700);

		while (SDL_PollEvent(&this->_event))
		{
			if (this->_event.type == SDL_QUIT)
				this->_program_run = 0;
			else if (this->_event.type == SDL_KEYDOWN)
			{
				if (this->_kb_state[SDL_SCANCODE_ESCAPE])
					this->_program_run = 0;
				// if (this->_kb_state[SDL_SCANCODE_T])
				// 	this->run_terminal();
			}

		}
		SDL_UpdateWindowSurface(this->_window);
		i++;
	}
	return;
}

void	Display::ft_putpixel(int x, int y, SDL_Surface *screen, SDL_Color color)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char*)screen->pixels;
	i = x * screen->format->BytesPerPixel + y * screen->pitch;
	if (x < this->_width && y < this->_height)
	{
		str[i] = (int)color.b;
		str[++i] = (int)color.g;
		str[++i] = (int)color.r;
	}
}

SDL_Color		Display::ft_color_from_texture(int t_x, int t_y, SDL_Surface *text)
{
	int				i;
	unsigned char	*str;
	SDL_Color		color;

	str = (unsigned char*)text->pixels;
	i = t_x * text->format->BytesPerPixel + t_y * text->pitch;
	color.b = (double)str[i];
	color.g = (double)str[++i];
	color.r = (double)str[++i];
	return (color);
}	

void		Display::ft_print_img(SDL_Surface *img, int dx, int dy)
{
	SDL_Color	color;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < this->_width && x < img->w)
	{
		y = 0;
		while (y < this->_height && y < img->h)
		{
			color = ft_color_from_texture(x, y, img);
			ft_putpixel(x + dx, y + dy, this->_screen, color);
			y++;
		}
		x++;
	}
}

void		Display::ft_print_anim(SDL_Surface *img, int dx, int dy)
{
	SDL_Color	color;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < this->_width && x < img->w)
	{
		y = 0;
		while (y < this->_height && y < img->h)
		{
			color = ft_color_from_texture(x, y, img);
			if (color.r == 255 && color.g == 255 && color.b == 255)
				y++;
			else
			{
				ft_putpixel(x + dx, y + dy, this->_screen, color);
				y++;
			}
		}
		x++;
	}
}

void		Display::graphic(int x, int y, std::vector<int>	data_vector)
{
	std::vector<int>::iterator it = data_vector.begin();
	std::vector<int >::iterator ite = data_vector.end();
	int		dx;
	int		dy;
	int		tmp_y;

	tmp_y = y;
	while(it != ite)
	{
		dx = x + 10;
		while (x < dx)
		{
			y = tmp_y;
			dy = -*it + tmp_y;
			while (y > dy)
			{
				ft_putpixel(x, y, this->_screen, this->_color_ad);
				y--;
			}
			x++;
		}
		x += 12;
		it++;	
	}	
}

