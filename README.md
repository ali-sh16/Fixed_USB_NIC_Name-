**USB-to-Ethernet** NIC has a random MAC address and random device name which keeps changing every time you restart the system , so we can not implement many technologies such as DHCP , network bonding , static IP and etc... . In this project , I programmed a simple application that makes a fixed device name even if the system is rebooted. 

This software  detects  the network cards in the system, stores their names in an array, deletes the unconcerned cards from the array, then stores the relevant network card name in a separate variable and uses terminal commands (network management software) in order to change the network card name to a predefined name and makes this software, which was programmed in the C++ language, to work automatically when the system boots .

This is a simple  flowchart that shows who the program is working :

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/36cb395164057f4eec163f0b74bda8f6fe70e445283df957.png)

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/32b43e441533fe992e9948e967e34180291a58ac0bfca831.png)

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/49f0156ec8fb1855a15641e6f15f419f2fad768543dac291.png)

To install this software :

1.  create a directory named ‘usb\_eth1’ in the root directory . Use the following commands :   
    `cd /`  
    `sudo mkdir usb_eth1`

sds
