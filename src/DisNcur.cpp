#include "DisNcur.hpp"
#include "DataTime.hpp"
#include <iostream>
#include <unistd.h>

DisNcur::DisNcur() {

	int		max_x;
	int		max_y;

	initscr();
	noecho();
	curs_set(0);
	start_color();
	cbreak();
	timeout(1);
	keypad(stdscr, TRUE);
	refresh();
	getmaxyx(stdscr, max_y, max_x);
	_window = newwin(35, 150, 0, 0);
	box(_window, 0 ,0 );
}

int	DisNcur::ft_control(void)
{
	int			in_char;

	in_char = getch();
	if(in_char == 'q')
			return(1);
	return (0);
}

void DisNcur::Draw() {
	//_objDT->defineData();
	
 while(1)
 	{
		this->_objOS->setAll();
		this->_objDT->defineDataStr();
		this->_objHost->setAll();
		this->_cpuobj->setAll();
		this->_ramobj->setAll();
//		this->_netobj->setNetwork();

		// std::cout << this->_objDT->getTime() << std::endl;
		// std::cout << _objDT->getTime() << std::endl;

		mvwprintw(_window, 7, 10, 	"Hostname: %s", this->_objHost->getHostName1());
		mvwprintw(_window, 8, 10, 	"Username: %s", this->_objHost->getUserName1());
		mvwprintw(_window, 10, 10, 	"Time: %s", this->_objDT->getTime());
		mvwprintw(_window, 11, 10, 	"Date: %s", this->_objDT->getData());
		mvwprintw(_window, 13, 10, 	"Product name: %s", this->_objOS->getProductName1());
		mvwprintw(_window, 14, 10, 	"Version: %s", this->_objOS->getProductVersion1());
		mvwprintw(_window, 15, 10, 	"Build version: %s", this->_objOS->getBuildVersion1());
		mvwprintw(_window, 17, 10, 	"Brand: %s", this->_cpuobj->getBrand1());
		mvwprintw(_window, 18, 10, 	"CPU: %s", this->_cpuobj->getCpu1());
		mvwprintw(_window, 19, 10, 	"CORES: %d", this->_cpuobj->getNcpu1());
		mvwprintw(_window, 21, 10, 	"Used: %s", this->_ramobj->getUsed1());
		mvwprintw(_window, 22, 10, 	"Total: %d", this->_ramobj->getTot1());
//		mvwprintw(_window, 24, 10, 	"Network: %s", this->_netobj->getNetwork1());


		 if (ft_control() == 1)
			 break;
		wrefresh(_window);
		usleep(18000);
	}
	//std::cout << _objDT->getTime() << std::endl;
}

DisNcur::DisNcur(DisNcur const &rhs) {

	*this = rhs;
}

//DisNcur& DisNcur::operator=(DisNcur const &rhs) {
//
//}

DisNcur::~DisNcur() {


}


void		DisNcur::setDataObj(DataTime *objDT)
{
	this->_objDT = objDT;
	return;
}

void DisNcur::setOSInfObj(OS_info *OSInfObj) {

	this->_objOS = OSInfObj;
	return ;
}

void DisNcur::setHostObj(Hostname *HostObj) {

	this->_objHost = HostObj;
}

void DisNcur::setCpuObj(CPU *cpuObj) {

	this->_cpuobj = cpuObj;
}

void DisNcur::setRamObj(RAM *ramobj) {

	this->_ramobj = ramobj;
}


void DisNcur::pair_color() {

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
}