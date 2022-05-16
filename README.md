# Kernel

This project is a basic kernel for Intel 64 bits architecture designed to manage keyboard interruptions, a couple of intel exceptions (both through an IDT table), timer tick interruptions to allow for context switching and display a shell to interact with the user.

The main goal of the project is in the design, clearly defining a kernel and user space, managing the interaction between the two through systems calls (defined by ourselves in the IDT table) and thus mimicking the actual design of modern preemptive operating systems. As well as being able to conmute between tasks thus allowing the user to run tasks simultaneously.

