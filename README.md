# 💬 Client-Server Chat Application

A real-time client-server chat application built using C and TCP socket programming. The application enables a client to connect to a server and exchange messages reliably over a network.

## 🚀 Features
- 💬 Real-time bidirectional communication
- ⚡ Concurrent client handling using pthreads
- 🔒 Reliable data transmission over TCP/IP
- ⚠️ Error handling and graceful client disconnection
- 🖥️ Runs on Linux (Ubuntu)

## 🛠️ Technologies Used
- C (Socket Programming)
- TCP/IP Protocol
- POSIX Threads (pthreads)
- GCC (Compilation)
- GDB (Debugging)
- Linux (Ubuntu)

## 📦 Installation
- Clone the repository:

  ```bash
   git clone https://github.com/SSwapnild31/chat-system-project.git
   ```
- change directory to chat-system-project

  ```bash
  cd chat-system-project
  ```
- Compile and create exe file called server

  ```bash
   cc server.c -o server
  ```
- Run the exe file with port number and ip address(127.0.0.1)  - any ip & port no

  ```bash
   ./server 2000 127.0.0.1
  ``` 
- Compile and create exe file called client

  ```bash
   cc client.c -o client
  ```
- Run the exe file with port number and ip address same as server
- In different terminal

  ```bash
   ./client 2000 127.0.0.1
  ```
  
## ⚙️ How It Works
- Server creates a `socket()`, `binds()` to a port, and `listen()` for incoming connections
- Multiple clients connect using TCP sockets
- Server uses pthreads to handle multiple clients concurrently as well as send/receive messages at same time
- Messages are sent and received using `send()` and `recv()` system calls

## 🧠 Learnings
- Hands-on experience with TCP socket programming
- Understanding of client-server architecture
- Thread management using pthreads
- Working with Linux system calls
- Debugging using GDB

## 📌 Future Improvements
- Add private messaging between clients
- Implement authentication system
- Use `select()` or `poll()` for I/O multiplexing
- Add logging and message history
- Improve scalability using epoll (Linux)

## 📸 Screenshots/Output
- Server

- Client 

## 🤝 Contributing
- Feel free to fork and improve the project!

## 📄 License
- This project is for learning purposes.
