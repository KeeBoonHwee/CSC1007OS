cmd_/home/pi/linux/CSC1007OS/week2/modules.order := {   echo /home/pi/linux/CSC1007OS/week2/chardev.ko; :; } | awk '!x[$$0]++' - > /home/pi/linux/CSC1007OS/week2/modules.order
