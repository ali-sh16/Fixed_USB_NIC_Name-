#include <iostream>
#include <ifaddrs.h>

int main() {

     // this part of code use to detect all interfaces on orange pi 3 and put there names in array
    struct ifaddrs *addrs;
    getifaddrs(&addrs);
	std::string interface[7];
	int j=0;
    for (struct ifaddrs *addr = addrs; addr != nullptr; addr = addr->ifa_next) {
        if (addr->ifa_addr && addr->ifa_addr->sa_family == AF_PACKET){
            	interface[j]= addr->ifa_name;
		        j++;
        }
    }

    // this loop use to check if eth1 interface in existing or not (yes=end program)
    for (int i = 0; i < 7; i++) {
            if(interface[i]=="eth1"){
                abort();   
            }
        }

    //this part for delete unwanted interfaces
    for(int i=0;i<7;i++) {
        if(interface[i]=="lo" || interface[i]=="eth0" || interface[i]=="wlan0" || interface[i]=="bond1" ) {
            interface[i]="";
        }
    }

    // to put the name of the interface in a specified variable
    std::string indecated_interface;
    for(int i=0;i<7;i++) {
        if(interface[i]!="") {
           indecated_interface=interface[i];
        }
    }

    //This part is used to convert string into a char for execution in the terminal
    std::string com1="ip link set "+indecated_interface+" down";
    std::string com2="ip link set "+indecated_interface+" name eth1";
    std::string com3="ip link set eth1  up";
    const char *command1 = com1.c_str();
    const char *command2 = com2.c_str();
    const char *command3 = com3.c_str();
    
    //Executing commands in a Linux terminal
    system(command1);
    system(command2);
    system(command3);

    freeifaddrs(addrs);
    return 0;
}
