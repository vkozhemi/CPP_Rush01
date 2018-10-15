#include "RAM.hpp"

RAM::RAM()
{
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(0, 0);
}

RAM::RAM(int x, int y) {

	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(x, y);
}

RAM::RAM(RAM const &obj) {

	*this= obj;
}

RAM& RAM::operator=(RAM const &obj) {

	if (&obj != this) {
		this->_color = obj._color;
		this->_font = obj._font;
		this->_place_Used = obj._place_Used;
		this->_place_Tot = obj._place_Tot;
		this->_text_Used = obj._text_Used;
		this->_text_Tot = obj._text_Tot;
		this->_genRect = obj._genRect;
		this->_Tot = obj._Tot;
		this->_Used = obj._Used;
	}
	return *this;
}

RAM::~RAM( void ) {}

void RAM::setUsed( void )
{
	FILE *file = popen("top -l 1 -s 0 | grep PhysMem | cut -d ' ' -f2", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_Used = new char[50];
	fgets(_Used, 50, file);
	strtok(_Used, "\n");
	pclose(file);
}

void RAM::initRect(int x, int y) {

	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 80;
	_genRect.w = 420;
	_place_Used.x = x + 165;
	_place_Used.y = y + 40;
	_place_Used.h = 80;
	_place_Used.w = 100;
	_place_Tot.x = x + 170;
	_place_Tot.y = y + 10;
	_place_Tot.h = 80;
	_place_Tot.w = 100;
	this->_text_Used = NULL;
	this->_text_Tot = NULL;
	return;
}

void RAM::setTot( void )
{
	size_t oldlenp = sizeof(size_t);
	sysctlbyname("hw.memsize", &_Tot, &oldlenp, NULL, 0);
	_Tot = _Tot/1000000;
}

void	RAM::defineData(void)
{
	if (this->_text_Used)
	{
		delete [] this->_Used;
		SDL_FreeSurface(_text_Used);
	}
	this->setUsed();
	if (!(this->_text_Used = TTF_RenderText_Solid(this->_font, this->_Used, this->_color)))
		throw std::out_of_range("Error: Text error!");
}

void	RAM::defineDataStat(void) {

	this->setTot();
	const char *tmp = (std::to_string(static_cast<int>(_Tot))).c_str();
	if (!(_text_Tot = TTF_RenderText_Solid(this->_font, tmp, this->_color)))
		throw std::out_of_range("Error: Text error!");
	return;

}

SDL_Surface *RAM::getTot(void) const
{
	return _text_Tot;
}

SDL_Surface *RAM::getUsed(void) const
{
	return _text_Used;
}

void			RAM::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

SDL_Color		RAM::getColor(void)
{
	return(this->_color);
}

int RAM::getTot1(void)
{
	return(static_cast<int>(this->_Tot));
}

char *RAM::getUsed1(void) const
{
	return(this->_Used);
}

void RAM::setAll() {

	setTot();
	setUsed();
}

