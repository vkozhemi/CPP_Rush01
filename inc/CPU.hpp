#ifndef CPU_HPP
# define CPU_HPP

# include <sys/sysctl.h>
# include <sys/types.h>
# include <iostream>
# include <string>
#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class CPU
{
public:
	CPU( void );
	CPU(int x, int y);
	CPU(CPU const &obj);
	CPU &operator=(CPU const &obj);
	~CPU( void );

	SDL_Surface *getCPU( void );
	SDL_Surface *getNcpu( void );
	SDL_Surface *getBrand( void );

	void setCPU( void );
	void setNcpu( void );
	void setBrand( void );
//	void setMemsize( void );
//	void setModel( void );
//	const char *getModel( void ) const;
//	const char *getMemsize( void ) const;
	void			updateInfo();

	void			initRect(int x, int y);
	SDL_Color		getColor(void);
	void			setFont(TTF_Font *font);
	void			defineData(void);
	void			defineDataStat(void);
	std::vector<int> getVector(void);


	char*			getCpu1();
	char*			getBrand1();
	int 			getNcpu1();
	void 			setAll();


	SDL_Rect		_place_CPU;
	SDL_Rect		_place_Ncpu;
	SDL_Rect		_place_Brand;
	SDL_Rect		_genRect;

	
private:
	char				*_CPU;
//	char				*_Model[100];
	int					_Ncpu;
	char 				_Brand[50];
	std::vector<int >	_info;

	SDL_Surface			*_text_CPU;
	SDL_Surface			*_text_Ncpu;
	SDL_Surface			*_text_Brand;

	SDL_Color		_color;
	TTF_Font		*_font;


};



#endif