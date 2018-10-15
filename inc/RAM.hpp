#ifndef RAM_HPP
# define RAM_HPP

#include <sys/sysctl.h>
#include <sys/types.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <exception>
#include <string>
#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
public:
	RAM( void );
	RAM(int x, int y);
	RAM(RAM const &obj);
	RAM &operator=(RAM const &obj);
	~RAM( void );

	SDL_Surface *getTot(void) const;
	SDL_Surface *getUsed(void) const;

	int getTot1(void);
	char *getUsed1(void) const;
	void setAll(void);

	
	void setTot( void );
	void setUsed( void );

	void			defineData(void);
	void			defineDataStat(void);
	void			initRect(int x, int y);
	SDL_Color		getColor(void);
	void			setFont(TTF_Font *font);
	SDL_Rect		_place_Used;
	SDL_Rect		_place_Tot;
	SDL_Rect		_genRect;

private:

	size_t			_Tot;
	char 			*_Used;
	SDL_Surface		*_text_Used;
	SDL_Surface		*_text_Tot;
	SDL_Color		_color;
	TTF_Font		*_font;
};

#endif