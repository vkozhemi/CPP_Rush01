#ifndef OS_INFO_HPP
# define OS_INFO_HPP

# include <sys/sysctl.h>
# include <sys/types.h>
# include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <exception>
# include <string>
#include "IMonitorModule.hpp"

class OS_info : public IMonitorModule
{
public:
	OS_info( void );
	OS_info(int x, int y);
	OS_info(OS_info const &);
	OS_info &operator=(OS_info const &);
	~OS_info( void );

	SDL_Surface *getProductName( void );
	SDL_Surface *getProductVersion( void );
	SDL_Surface *getBuildVersion( void );

	// SDL_Surface		*getProductName(void);
	// SDL_Surface		*getProductVersion(void);
	// SDL_Surface		*getBuildVersion(void);
	SDL_Color		getColor(void);

	void setProductName( void );
	void setProductVersion( void );
	void setBuildVersion( void );

	void			defineData(void);
	void			initRect(int x, int y);
	void			setFont(TTF_Font *font);

	char*			getProductName1();
	char*			getProductVersion1();
	char*			getBuildVersion1();
	void			setAll();


	SDL_Rect		_place_productName;
	SDL_Rect		_place_productVersion;
	SDL_Rect		_place_buildVersion;
	SDL_Rect		_genRect;
	
private:
	char *_productName;
	char *_productVersion;
	char *_buildVersion;

	SDL_Surface		*_text_productName;
	SDL_Surface		*_text_productVersion;
	SDL_Surface		*_text_buildVersion;
	SDL_Color		_color;
	TTF_Font		*_font;
	
};



#endif