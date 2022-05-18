#!/bin/bash

printf "\033[0;36m############################### START ###############################\033[0m\n"
sudo docker start PRE_TPE
sudo docker exec -it PRE_TPE make -C /root/Toolchain clean
sudo docker exec -it PRE_TPE make -C /root clean
sudo docker exec -it PRE_TPE make -C /root/Toolchain all
sudo docker exec -it PRE_TPE make -C /root all
sudo docker stop PRE_TPE
printf "\033[0;36m############################### END ###############################\033[0m\n"
	
if [ $# -eq 1 ] && [ $1 == "run" ]
then
	cd /home/marco444/x64barebones
	sudo ./run.sh 
fi

if [ $# -eq 1 ] && [ $1 == "debug" ]
then
	cd /home/marco444/x64barebones
	sudo ./run.sh debug
fi