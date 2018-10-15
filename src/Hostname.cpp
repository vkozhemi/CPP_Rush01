#include "Hostname.hpp"

Hostname::Hostname()
{
	return ;
}

Hostname::Hostname(int x, int y)
{
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(x, y);
}

Hostname::Hostname(Hostname const &rhs) {

	*this = rhs;
	return ;
}

Hostname& Hostname::operator=(Hostname const &obj) {

	if (&obj != this)
	{
		this->_hostName = obj._hostName;
		this->_userName = obj._userName;
		this->_text_userName = obj._text_userName;
		this->_text_hostName = obj._text_hostName;
		this->_color = obj._color;
		this->_font = obj._font;
		this->_place_userName = obj._place_userName;
		this->_place_hostName = obj._place_hostName;
		this->_genRect = obj._genRect;
	}
	return *this;
}

Hostname::~Hostname(void) {

	if (this->_hostName)
		delete [] this->_hostName;
	if (this->_userName)
		delete [] this->_userName;
}

void Hostname::setHostname( void )
{
	FILE *file = popen("hostname", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_hostName = new char [50];
	fgets(_hostName, 50, file);
	strtok(_hostName, "\n");
	pclose(file);
}

void Hostname::setUsername( void )
{
	FILE* file = popen("whoami", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_userName = new char [50];
	fgets(_userName, 50, file);
	strtok(_userName, "\n");
	pclose(file);
}

void	Hostname::initRect(int x, int y)
{
	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 60;
	_genRect.w = 420;

	_place_hostName.x = x + 120;
	_place_hostName.y = y + 5;
	_place_hostName.h = 20;
	_place_hostName.w = 400;

	_place_userName.x = x + 150;
	_place_userName.y = y + 25;
	_place_userName.h = 20;
	_place_userName.w = 400;
	return;
}

void	Hostname::defineData(void)
{
	if (_text_hostName)
	{
		delete [] this->_hostName;
		SDL_FreeSurface(_text_hostName);
	}
	if (_text_userName)
	{
		delete [] this->_userName;
		SDL_FreeSurface(_text_userName);
	}
	this->setHostname();
	this->setUsername();
	if (!(_text_hostName = TTF_RenderText_Solid(this->_font, this->_hostName, this->_color)))
		throw std::out_of_range("Error: Text error!");
	if (!(_text_userName = TTF_RenderText_Solid(this->_font, this->_userName, this->_color)))
		throw std::out_of_range("Error: Text error!");
}

void			Hostname::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

SDL_Surface	*Hostname::getHostname(void)
{
	return _text_hostName;
}

SDL_Surface *Hostname::getUsername(void)
{
	return _text_userName;
}

SDL_Color		Hostname::getColor(void)
{
	return(this->_color);
}

void Hostname::setAll() {

	setHostname();
	setUsername();
}

char* Hostname::getHostName1() {

	return _hostName;
}

char* Hostname::getUserName1() {

	return _userName;
}