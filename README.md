**USB-to-Ethernet** NIC has a random MAC address and random device name which keeps changing every time you restart the system , so we can not implement many technologies such as DHCP , network bonding , static IP and etc... . In this project , I programmed a simple application that makes a fixed device name even if the system is rebooted. 

This software  detects  the network cards in the system, stores their names in an array, deletes the unconcerned cards from the array, then stores the relevant network card name in a separate variable and uses terminal commands (network management software) in order to change the network card name to a predefined name and makes this software, which was programmed in the C++ language, to work automatically when the system boots .

This is a simple  flowchart that shows who the program is working :

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/36cb395164057f4eec163f0b74bda8f6fe70e445283df957.png)

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/32b43e441533fe992e9948e967e34180291a58ac0bfca831.png)

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/49f0156ec8fb1855a15641e6f15f419f2fad768543dac291.png)

> this software use to change the name of USB\_NIC automatically  to “eth1” without having to manually modify it each time the system boots , This makes it easier to save the bond file settings and not change them all the time .

**Requirements :**

1.  Root privileges .
2.  Basic knowledge of Linux command line .
3.  USB network interface card of any brand .
4.  Orange pi 3 LTS .
5.  Ubuntu server 22 .

**To install this software :**

1.  create a directory named ‘usb\_eth1’ in the root directory .  
    Use the following commands :   
    `cd /`  
    `sudo mkdir usb_eth1`
2.  create a new file that named ‘interfaces.c’ in the ‘usb\_eth1’ directory .   
    Use the following commands :  
    `cd /usb_eth1`  
    `sudo touch interfaces.c`
3.  edit the file and paste the code of this project, then save it .  
    Use the following commands :  
    `sudo nano ./interfaces.c`  
    ctrl + o and chose yes to save, then press ctrl + x to exit .
4.  compilation ‘interfaces.c’ file .  
    Use the following commands :  
    `sudo g++ interfaces.c`
5.  change the permission of ‘a.out’ file to make it execution .  
    Use the following commands :  
    `sudo chmood 777 ./a.out`
6.  make ‘a.out’ run automatically  when the system is startup .  
    Use the following commands :  
    `sudo crontab -e`  
    press 'Enter' to use Nano editor , Scroll down and put the following line :  
    `@reboot /usb_eth1/a.out`  
    ctrl + o and chose yes to save, then press ctrl + x to exit .
7.  restart the system .  
     

Testing :

When the system restarts, run the following command :  
`sudo ifconfig`  
All the interfaces in the system will appear, and you will see one of them named " eth1 ", knowing that the project has been completely successful .
