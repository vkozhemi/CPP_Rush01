#include "Network.hpp"

Network::Network( void )
{
	// setNetwork();
}

Network::Network(int x, int y)
{
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(x, y);
}

Network::Network( Network const & src)
{
	*this = src;
}

Network &Network::operator=( Network const & rhs) 
{
	if (&rhs != this)
	{
//		this->_netWork = rhs._netWork;
		this->_text_netWork = rhs._text_netWork;
		this->_color = rhs._color;
		this->_font = rhs._font;
		this->_place_Network = rhs._place_Network;
		this->_genRect = rhs._genRect;
	}
	return *this;
}

Network::~Network( void ) {

//	if (this->_netWork)
//		delete [] this->_netWork;
}

void Network::setNetwork( void )
{
	FILE *file = popen("top -l 1| grep Network | cut -d ' ' -f3 -f4 -f5 -f6", "r");
//	this->_netWork = new char [100];
	fgets(_netWork, 100, file);
	strtok(_netWork, "\n");
	pclose(file);
}

void	Network::initRect(int x, int y)
{
	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 80;
	_genRect.w = 420;

	_place_Network.x = x + 50;
	_place_Network.y = y + 40;
	_place_Network.h = 20;
	_place_Network.w = 400;

	return;
}

void	Network::defineData(void)
{
	if (_text_netWork)
	{
//		delete [] this->_netWork;
		SDL_FreeSurface(_text_netWork);
	}
	this->setNetwork();
	if (!(_text_netWork = TTF_RenderText_Solid(this->_font, this->_netWork, this->_color)))
		throw std::out_of_range("Error: Text error!");
}

void			Network::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

SDL_Surface	*Network::getNetwork (void)
{
	return (this->_text_netWork);
}

SDL_Color	Network::getColor(void)
{
	return(this->_color);
}

char* Network::getNetwork1() {

	return _netWork;
}
