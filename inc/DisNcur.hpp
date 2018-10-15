#ifndef DISNCUR_HPP
#define DISNCUR_HPP

#include <ncurses.h>
#include "DataTime.hpp"
#include "OS_info.hpp"
#include "Hostname.hpp"
#include "IMonitorDisplay.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "Network.hpp"

class DisNcur : public IMonitorDisplay {

public:

	DisNcur();
	DisNcur(DisNcur const & rhs);
//	DisNcur &operator=(DisNcur const & rhs);
	~DisNcur();

	void			pair_color();

	void			setDataObj(DataTime *objDT);
	void			setOSInfObj(OS_info *OSInfObj);
	void			setHostObj(Hostname *HostObj);
	void			setCpuObj(CPU *cpuObj);
	void			setRamObj(RAM *ramobj);
	void			setNetObj(Network *netobj);

	void			Draw();

	int	ft_control(void);

private:

	WINDOW			*_window;
	DataTime 		*_objDT;
	OS_info 		*_objOS;
	Hostname		*_objHost;
	CPU				*_cpuobj;
	RAM 			*_ramobj;
	Network			*_netobj;

};


#endif
