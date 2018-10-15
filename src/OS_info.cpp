#include "OS_info.hpp"

void	OS_info::initRect(int x, int y)
{
	_genRect.x = x;
	_genRect.y = y;
	_genRect.h = 80;
	_genRect.w = 420;
	
	_place_productName.x = x + 150;
	_place_productName.y = y + 5;
	_place_productName.h = 20;
	_place_productName.w = 400;

	_place_productVersion.x = x + 160;
	_place_productVersion.y = y + 30;
	_place_productVersion.h = 20;
	_place_productVersion.w = 400;

	_place_buildVersion.x = x + 160;
	_place_buildVersion.y = y + 50;
	_place_buildVersion.h = 20;
	_place_buildVersion.w = 400;
	return;
}

OS_info::OS_info(void)
{
	this->initRect(10, 10);
	return;
}

OS_info::OS_info(int x, int y)
{
	_color.r = 255;
	_color.g = 255;
	_color.b = 255;
	this->initRect(x, y);
}

OS_info::OS_info(const OS_info &object)
{
	*this = object;
	return ;
}

OS_info& OS_info::operator=(OS_info const &obj)
{
	if (&obj != this)
	{
		this->_productName = obj._productName;
		this->_productVersion = obj._productVersion;
		this->_buildVersion = obj._buildVersion;
		this->_color = obj._color;
		this->_font = obj._font;
		this->_place_productName = obj._place_productName;
		this->_place_productVersion = obj._place_productVersion;
		this->_place_buildVersion = obj._place_buildVersion;
		this->_genRect = obj._genRect;
	}
	return (*this);
}

OS_info::~OS_info( void ) {

	if (this->_productName)
		delete [] this->_productName;
	if (this->_productVersion)
		delete [] this->_productVersion;
	if (this->_buildVersion)
		delete [] this->_buildVersion;
	return;
}

void OS_info::setProductName( void )
{
	FILE *file = popen("sw_vers -productName", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_productName = new char[10];
	fgets(_productName, 10, file);
	strtok(_productName, "\n");
	pclose(file);
}

void OS_info::setProductVersion( void )
{
	FILE* file = popen("sw_vers -productVersion", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_productVersion = new char[50 + 1];
	fgets(_productVersion, 50, file);
	strtok(_productVersion, "\n");
	pclose(file);
}

void OS_info::setBuildVersion( void )
{
	FILE* file = popen("sw_vers -buildVersion", "r");
	if (!file)
	{
		std::cerr << "Couldn't start command." << std::endl;
		return ;
	}
	this->_buildVersion = new char[50 + 1];
	fgets(_buildVersion, 50, file);
	strtok(_buildVersion, "\n");
	pclose(file);
}

void	OS_info::defineData(void)
{
	this->setProductName();
	this->setProductVersion();
	this->setBuildVersion();

	if (!(_text_productName = TTF_RenderText_Solid(this->_font, this->_productName, this->_color)))
		throw std::out_of_range("Error: Text error!");
	if (!(_text_productVersion = TTF_RenderText_Solid(this->_font, this->_productVersion, this->_color)))
		throw std::out_of_range("Error: Text error!");
	if (!(_text_buildVersion = TTF_RenderText_Solid(this->_font, this->_buildVersion, this->_color)))
		throw std::out_of_range("Error: Text error!");
}

void			OS_info::setFont(TTF_Font *font)
{
	this->_font = font;
	return;
}

SDL_Surface *OS_info::getProductName(void)
{
	return this->_text_productName;
}

SDL_Surface *OS_info::getProductVersion(void)
{
	return this->_text_productVersion;
}

SDL_Surface *OS_info::getBuildVersion(void)
{
	return this->_text_buildVersion;
}

SDL_Color		OS_info::getColor(void)
{
	return(this->_color);
}

char* OS_info::getProductName1() {

	return _productName;
}

char* OS_info::getProductVersion1() {

	return _productVersion;
}

char* OS_info::getBuildVersion1() {

	return _buildVersion;
}

void OS_info::setAll() {

	setBuildVersion();
	setProductName();
	setProductVersion();
}