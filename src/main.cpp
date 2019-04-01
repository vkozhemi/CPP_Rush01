/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:14:30 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/10/13 16:14:34 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"
#include "OS_info.hpp"
#include "DataTime.hpp"
#include "Hostname.hpp"
#include "Network.hpp"
#include "RAM.hpp"
#include "Processes.hpp"
#include "DisNcur.hpp"

#define		WIDTH	500
#define		HEIGHT	1000

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		
		if (std::strcmp(argv[1], "SDL") == 0)
		{
			Display		MyDisplay(WIDTH, HEIGHT);
			DataTime	DTObj(50, 10);
			OS_info		OSInfObj(50, 80);
			Hostname	HostObj(50, 170);
			CPU			CPUObj(50, 250);
			RAM			RAMObj(50, 460);
			Network		NetworkObj(50, 550);
			Processes	ProcObj(50, 640);

			
			DTObj.setFont(MyDisplay.getFont());
			OSInfObj.setFont(MyDisplay.getFont());
			HostObj.setFont(MyDisplay.getFont());
			CPUObj.setFont(MyDisplay.getFont());
			RAMObj.setFont(MyDisplay.getFont());
			NetworkObj.setFont(MyDisplay.getFont());
			ProcObj.setFont(MyDisplay.getFont());


			MyDisplay.setDataObj(&DTObj);
			MyDisplay.setDataOs(&OSInfObj);
			MyDisplay.setHost(&HostObj);
			MyDisplay.setCPU(&CPUObj);
			MyDisplay.setRAM(&RAMObj);
			MyDisplay.setNetwork(&NetworkObj);
			MyDisplay.setProcesses(&ProcObj);

			MyDisplay.updateWindow();
			SDL_Quit();
		}
		else if (std::strcmp(argv[1], "shell") == 0)
		{
		
			DataTime		DTObj(50, 10);
			 OS_info		OSInfObj(50, 80);
			 Hostname	HostObj(50, 170);
			 CPU		CpuObj(50, 170);
			 RAM		ramobj(50, 170);
			 Network	netobj(50, 170);

			DisNcur nc;
			nc.setDataObj(&DTObj);
			nc.setOSInfObj(&OSInfObj);
			nc.setHostObj(&HostObj);
			nc.setCpuObj(&CpuObj);
			nc.setRamObj(&ramobj);
	
			nc.Draw();
			getch();
		}
	}
	else
		std::cout << "Usage  ./ft_gkrellm [SDL] or [shell]" << std::endl;
	return (0);
}
