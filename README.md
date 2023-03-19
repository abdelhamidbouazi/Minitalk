# Minitalk

Minitalk is a simple client-server program in C, using UNIX signals for inter-process communication. The server receives a message from the client and displays it. Both the client and server can run on the same machine or different machines on a network. This project is a part of the curriculum at 42.

## Installation

1. Clone the repository: `git clone https://github.com/<username>/minitalk.git`
2. Change directory: `cd minitalk`
3. Compile the executable: `make`

## Usage



### Server

./server

### Client

./client [server_pid] [message]


Replace `[server_pid]` with the process ID of the server, which is displayed when the server is started. Replace `[message]` with the message you want to send.

## Example

1. Start the server: `./server`
2. In another terminal, send a message: `./client [server_pid] Hello, Minitalk!`
