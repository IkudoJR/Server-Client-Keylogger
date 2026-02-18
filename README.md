# Server-Client-Keylogger
Server-Client Keylogger that logs and saves pressed keys into a file then send the data to the server

## ⚠️ Legal Disclaimer
**This project is for Educational Purposes only.**
Unauthorized use of this tool on any system without explicit permission is illegal.

## Project Overview
Initially developed as a simple local keylogger, the project was expanded to include a **Server-Client architecture**. This allows a remote "attacker" (Server) to receive captured telemetry from a "victim" (Client) over a network connection

## Technical Logic
The system consists of two primary modules:
1. **The Client (Victim):** A hidden software that connects to the server and sends the collected logs.
2. **The Server (Attacker):** A listener that waits for the client to establish a connection and push the collected logs.
3. **The Keylogger:** A stealthy background process that hooks keyboard input and buffers data to a local log file.

after creating the software it felt too simple and basic.
At the same time i learned how to make a server-client.
So, I thought of applying that to the software.

The idea is that the keylogger works hidden in the background
and the server wait for the client to connect and send the log file.
In this situation the attacker is the server and the victim is the client.

Video explanations:
1. At the start of the video, I show that the log file is empty, and that the keylogger is not running.
2. Then I ran the keylogger that can only be seen in the task manager.
3. Then I opened the text file and wrote “Text ” and [ctrl] s to save.
4. Showed that the log file is updated then opened the server-client.
5. The client connected to the server and sent the log-file content.
