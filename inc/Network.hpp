#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
# include <sys/sysctl.h>
# include <sys/types.h>
# include <iostream>
# include <string>
#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
public:
	Network( void );
	Network( int x, int y);
	Network(Network const &);
	Network &operator=(Network const &);
	~Network( void );

	
	SDL_Surface		*getNetwork( void );
	SDL_Color		getColor(void);
	void			setFont(TTF_Font *font);
	void			initRect(int x, int y);
	void			defineData(void);


	void 			setNetwork( void );
	char*			getNetwork1();

	SDL_Rect		_place_Network;
	SDL_Rect		_genRect;

private:
	char _netWork[100];

	SDL_Surface		*_text_netWork;
	SDL_Color		_color;
	TTF_Font		*_font;
};



#endif