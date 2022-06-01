# Kernel

This project is a basic kernel for Intel 64 bits architecture designed as an interactive shell that allows to run commands simultaneously in split screen. 

The main goal of the project is in the design, clearly defining a kernel and user space, managing the interaction between kernel/hardware and kernel/user through interruptions, and implementing an schedluer to manage context switching and thus running commands simultaneously.


## User Manual

### Instalation:

```console
# define
sudo apt-get update
sudo apt install qemu docker
sudo apt install nasm
sudo apt install qemu
sudo apt install gcc
sudo apt install make

sudo apt-get install docker.io
sudo groupadd docker
sudo usermod -aG docker $USER
docker run hello-world
sudo chmod 666 /var/run/docker.sock
docker run -v ${PWD}:/root --security-opt seccomp:unconfined -ti agodio/itba-so:1.0

```
