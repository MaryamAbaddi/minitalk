# Overview
minitalk is a C project that implements a simple client-server communication system using UNIX signals.
The goal of this project is to send messages from a client to a server process by encoding characters into binary signals.
This project strengthens understanding of:
-UNIX signals (SIGUSR1, SIGUSR2)
-Inter-process communication (IPC)
-Bitwise operations
-Process IDs (PID)
-Low-level system programming in C

# Objectives
-Build a server program that receives messages via signals.
-Build a client program that sends messages to the server.
-Encode characters into bits and transmit them using signals.
-Handle synchronization between client and server.
-Ensure reliable message transmission.

# Resources
The following resources were used during the development of this project:
-The C Programming Language (K&R)
-42 Network Documentation
-Linux man pages (man signal, man kill)

# How It Works
-The server starts and prints its Process ID (PID).
-The client takes the server PID and a message as arguments.
-Each character of the message is converted into binary.
-Bits are sent one by one using UNIX signals:
SIGUSR1 represents bit 1
SIGUSR2 represents bit 0
The server reconstructs the characters and prints the message.

# Use of AI in This Project
AI tools were used as supportive learning resources, not as direct sources of solutions.
-AI was used to:
-Explain how UNIX signals and bitwise operations work.
-Help analyze edge cases and synchronization issues.
-Improve documentation and code readability.
-All core implementations were written manually to ensure a deep understanding of system programming concepts.

# Usage
-Compile the project
make
-Run the server
./server
-Run the client
./client <server_pid> "Hello from minitalk!"

# Skills Gained
-Inter-process communication (IPC)
-UNIX signals and process management
-Bitwise operations and encoding
-Low-level C programming
-Debugging concurrent behavior
-Writing modular and maintainable code


