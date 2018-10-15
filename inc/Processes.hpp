#ifndef PROCESSES_HPP
# define PROCESSES_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
# include <sys/sysctl.h>
# include <sys/types.h>
# include <iostream>
# include <string>
#include "IMonitorModule.hpp"

class Processes : public IMonitorModule
{
public:
	Processes( void );
	Processes( int x, int y);
	Processes(Processes const &);
	Processes &operator=(Processes const &);
	~Processes( void );

	SDL_Surface		*getProcesses( void );
	SDL_Surface		*getDisk( void );
	SDL_Color		getColor(void);
	void			setFont(TTF_Font *font);
	void			initRect(int x, int y);
	void			defineData(void);

	//std::string getProcesses( void );
	//const char  *getProcesses( void ) const;
	void 		setProcesses( void );
	void 		setDisk( void );
	
	SDL_Rect		_place_Processes;
	SDL_Rect		_place_Disk;
	SDL_Rect		_genRect;


private:
	//std::string _Processes;
	char *_Processes;
	char *_Disk;

	SDL_Surface		*_text_Processes;
	SDL_Surface		*_text_Disk;
	SDL_Color		_color;
	TTF_Font		*_font;
};

#endif