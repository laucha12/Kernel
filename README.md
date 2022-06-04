# Kernel

This project is a basic kernel for Intel 64 bits architecture designed as an interactive shell that allows to run commands simultaneously in split screen. 

The main goal of the project is in the design, clearly defining a kernel and user space, managing the interaction between kernel/hardware and kernel/user through interruptions, and implementing an schedluer to manage context switching and thus running commands simultaneously.

## Environment setup

1- Install the following packages before building the Toolchain and Kernel:
```
sudo apt install nasm
sudo apt install qemu
sudo apt install gcc
sudo apt install make
sudo apt install qemu-system
```

2- Build the Toolchain

Execute the following commands on the x64BareBones project directory:
```
user@linux:$ cd Toolchain
user@linux:$ make all
```

3- Build the Kernel

From the x64BareBones project directory run:

```
user@linux:$ make all
```

4- Run the kernel

From the x64BareBones project directory run:

```
user@linux:$ ./run.sh
```
