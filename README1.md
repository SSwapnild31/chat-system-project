## 📁 Project Structure
    chat-app/
    │── client.c # Client-side implementation (connects to server, sends/receives messages)
    │── server.c # Server-side implementation (handles multiple message routing)
    │── header.h # Common header file (structures, constants, function declarations)
---

## 📄 File Description

### 🔹 client.c
- Creates a `socket()` and `connect()` to the server
- `send()` messages to the server
- `recv()` messages from the server
- Handles user input/output
- `close()` to close the socket
  
### 🔹 server.c
- `create()`, `bind()`, and `listen()` on a socket
- `accept()` multiple client connections
- `pthread_t()` to handle concurrent clients and bidirectional messages
- `send()` to send message to the client
- `recv()` to send message to the client
- `close()` to close the socket

### 🔹 header.h
- Contains shared structures (e.g., client info, message format)
- Defines constants (port number, buffer size)
- Includes required libraries and function prototypes

---
