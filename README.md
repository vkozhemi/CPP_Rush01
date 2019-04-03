# ft_gkrellm

GKrellM is a very nice system monitor.

## Installation

`git clone https://github.com/vkozhemi/CPP_Rush01.git`
`cd CPP_Rush01`
`make`

## Run

Standard mode : 

`./ft_ft_gkrellm SDL`
`./ft_ft_gkrellm shell`

## Design
The software design part is almost entirely at your discretion. However, you MUST create and use at least the two following interfaces :

	• IMonitorModule, which describes the behavior of one or your monitor’s "modules". IMonitorModule is an abstraction to the available modules. Implementing this interface allows a class to behave like a module of the monitor, and allows the monitor to handle every modules in an unified way. This, students. This is Object Oriented Programming.
	• IMonitorDisplay, which describes the behavior of a display mode. IMonitorDisplay is an abstraction between the two available displays. Thus, at least two class should implement this interface : the class that handles the shell UI and the one that han- dles the graphical UI.


## Module
	• Hostname/username module 
	• OS info module
	• Date/time module
	• CPU module (Model, clock speed, number of cores, activity, ...) 
	• RAM module
	• Network throughput module

## ncurses
![Image alt](https://github.com/vkozhemi/CPP_Rush01/raw/master/img/1.png)

## SDL
<img src="https://github.com/vkozhemi/CPP_Rush01/raw/master/img/2.png" width="300">
