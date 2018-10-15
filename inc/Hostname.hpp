#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
# include <sys/sysctl.h>
# include <sys/types.h>
# include <iostream>
# include <string>
#include "IMonitorModule.hpp"

class Hostname : public IMonitorModule
{
public:
	Hostname( void );
	Hostname(int x, int y);
	Hostname(Hostname const &rhs);
	Hostname &operator=(Hostname const &obj);
	~Hostname( void );

	SDL_Surface		*getHostname( void );
	SDL_Surface		*getUsername( void );
	SDL_Color		getColor(void);
	void			setFont(TTF_Font *font);
	void			initRect(int x, int y);
	void			defineData(void);
	void			setAll();
	char*			getHostName1();
	char*			getUserName1();


	void setHostname( void );
	void setUsername( void );

	SDL_Rect		_place_hostName;
	SDL_Rect		_place_userName;
	SDL_Rect		_genRect;
	
private:
	char 			*_hostName;
	char 			*_userName;
	SDL_Surface		*_text_hostName;
	SDL_Surface		*_text_userName;
	SDL_Color		_color;
	TTF_Font		*_font;
	
};



#endif