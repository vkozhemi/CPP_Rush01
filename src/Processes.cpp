#include "Processes.hpp"

Processes::Processes( void ) {}

Processes::Processes( int x, int y ) {

	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(x, y);
}

Processes::Processes( Processes const & r)
{
	*this = r;
}

Processes &Processes::operator=( Processes const & rhs) {

	if (&rhs != this)
	{
		this->_Processes = rhs._Processes;
		this->_Disk = rhs._Disk;
		this->_text_Processes = rhs._text_Processes;
		this->_text_Disk = rhs._text_Disk;
		this->_color = rhs._color;
		this->_font = rhs._font;
		this->_place_Processes = rhs._place_Processes;
		this->_place_Disk = rhs._place_Disk;
		this->_genRect = rhs._genRect;
	}
	return *this;
}

Processes::~Processes( void ) {

	if (this->_Processes)
		delete [] this->_Processes;
	if (this->_Disk)
		delete [] this->_Disk;
}

void Processes::setProcesses( void )
{
	FILE *file = popen("top -l 1| grep Processes | cut -d ' ' -f2 -f3 -f4 -f5 -f6 -f7 -f8 -f9", "r");
	//char res[100];
	this->_Processes = new char [100];
	fgets(_Processes, 100, file);
	strtok(_Processes, "\n");
	//_Processes = static_cast<std::string>(res);

	pclose(file);
	// return _Processes;
}

void Processes::setDisk( void )
{
	FILE *file = popen("top -l 1| grep Disks | cut -d ' ' -f2 -f3 -f4 -f5", "r");
	//char res[100];
	this->_Disk = new char [100];
	fgets(_Disk, 100, file);
	strtok(_Disk, "\n");
	//_Processes = static_cast<std::string>(res);

	pclose(file);
	// return _Processes;
}

void	Processes::initRect(int x, int y)
{
	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 90;
	_genRect.w = 420;

	_place_Processes.x = x + 10;
	_place_Processes.y = y + 25;
	_place_Processes.h = 20;
	_place_Processes.w = 400;

	_place_Disk.x = x + 30;
	_place_Disk.y = y + 50;
	_place_Disk.h = 20;
	_place_Disk.w = 400;

	return;
}

void	Processes::defineData(void)
{
	if (_text_Processes)
	{
		delete [] this->_Processes;
		SDL_FreeSurface(_text_Processes);
	}
	if (_text_Disk)
	{
		delete [] this->_Disk;
		SDL_FreeSurface(_text_Disk);
	}
	this->setProcesses();
	this->setDisk();
	if (!(_text_Processes = TTF_RenderText_Solid(this->_font, this->_Processes, this->_color)))
		throw std::out_of_range("Error: Text error!");
	if (!(_text_Disk = TTF_RenderText_Solid(this->_font, this->_Disk, this->_color)))
		throw std::out_of_range("Error: Text error!");
}

void	Processes::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

SDL_Surface	*Processes::getProcesses(void)
{
	return _text_Processes;
}

SDL_Surface	*Processes::getDisk(void)
{
	return _text_Disk;
}

SDL_Color		Processes::getColor(void)
{
	return(this->_color);
}
