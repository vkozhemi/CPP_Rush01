#include "CPU.hpp"

CPU::CPU()
{
	this->_color.r = 255;
	this->_color.g = 255;
	this->_color.b = 255;
	this->initRect(0, 0);
}

CPU::CPU(int x, int y) {

	this->_color.r = 255;
	this->_color.g = 255;
	this->_color.b = 255;
	this->initRect(x, y);
}

CPU::CPU(CPU const &obj) {

	*this = obj;
	return ;
}

CPU& CPU::operator=(CPU const &obj) {

	if (this != &obj)
	{
		this->_Ncpu = obj._Ncpu;
		this->_CPU = obj._CPU;
		this->_text_CPU = obj._text_CPU;
		this->_text_Brand = obj._text_Brand;
		this->_text_Ncpu = obj._text_Ncpu;
		this->_color = obj._color;
		this->_font = obj._font;
		this->_place_CPU = obj._place_CPU;
		this->_place_Brand = obj._place_Brand;
		this->_place_Ncpu = obj._place_Ncpu;
		this->_genRect = obj._genRect;
	}
	return (*this);
}

CPU::~CPU( void ) {

	if (this->_CPU)
		delete [] this->_CPU;
}

void CPU::setCPU( void )
{
	FILE *file = popen("top -l 1| grep CPU", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_CPU = new char[50];
	fgets(_CPU, 50, file);
	strtok(_CPU, "\n");
	pclose(file);
}

void CPU::setNcpu( void )
{
	size_t oldlenp = sizeof(int);
	sysctlbyname("hw.ncpu", &_Ncpu, &oldlenp, NULL, 0);
}

void CPU::setBrand( void )
{
	size_t oldlenp = 100;
	sysctlbyname("machdep.cpu.brand_string", &this->_Brand, &oldlenp, NULL, 0);
	
}

void CPU::updateInfo() {

	static int   k = 0;
	int			num;
	char * test;
	FILE *file = popen("top -l 1| grep CPU | cut -d ' ' -f7", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	test = new char[50];
	fgets(test, 50, file);
	pclose(file);
	num = std::stoi(test);
	if (_info.size() < 15)
		_info.push_back(100 - num);
	else
	{
		std::vector<int >::iterator it = _info.begin();
		for (int i = 0; i < k; i++)
			it++;
		*it = 100 - num;
		k++;
		if (k == 15)
			k = 0;
	}
}

void	CPU::defineData(void)
{
	if (this->_text_CPU)
	{
		delete [] this->_CPU;
		SDL_FreeSurface(this->_text_CPU);
	}
	this->setCPU();
	if (!(this->_text_CPU = TTF_RenderText_Solid(this->_font, this->_CPU, this->_color)))
		throw std::out_of_range("Error: Text error!");
	this->updateInfo();
}

void	CPU::defineDataStat(void) {

	this->setBrand();
	this->setNcpu();
	const char *tmp = (std::to_string(_Ncpu)).c_str();
	if (!(_text_Ncpu = TTF_RenderText_Solid(this->_font, tmp, this->_color)))
		throw std::out_of_range("Error: Text error!");
	if (!(this->_text_Brand = TTF_RenderText_Solid(this->_font, this->_Brand, this->_color)))
		throw std::out_of_range("Error: Text error!");
	return;
}

void CPU::initRect(int x, int y) {

	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 200;
	_genRect.w = 420;
	_place_CPU.x = x + 10;
	_place_CPU.y = y + 5;
	_place_CPU.h = 80;
	_place_CPU.w = 400;
	_place_Ncpu.x = x + 200;
	_place_Ncpu.y = y + 65;
	_place_Ncpu.h = 80;
	_place_Ncpu.w = 400;
	_place_Brand.x = x + 60;
	_place_Brand.y = y + 35;
	_place_Brand.h = 80;
	_place_Brand.w = 400;
	_text_CPU = NULL;
	_text_Ncpu = NULL;
	_text_Brand = NULL;
	return;
}

SDL_Surface *CPU::getCPU(void)
{
	return _text_CPU;
}

void			CPU::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

SDL_Color		CPU::getColor(void)
{
	return(this->_color);
}

SDL_Surface *CPU::getNcpu(void)
{
	return this->_text_Ncpu;
}

SDL_Surface *CPU::getBrand(void)
{
	return this->_text_Brand;
}

std::vector<int>	CPU::getVector(void)
{
	return(this->_info);
}

void CPU::setAll() {

	setBrand();
	setCPU();
	setNcpu();
}

char* CPU::getBrand1() {

	return _Brand;
}

char* CPU::getCpu1() {

	return _CPU;
}

int CPU::getNcpu1() {

	return _Ncpu;
}

