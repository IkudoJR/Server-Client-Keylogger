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

## Demonstration Workflow
The following steps are shown in the demonstration video:
1.  **Baseline Check:** Verification that the local log file is empty and the process is not yet active.
2.  **Execution:** Launching the keylogger; it operates silently with no GUI, visible only in the System Task Manager.
3.  **Data Capture:** Actively writing "Text" and [ctrl] s to trigger a logging event.
4.  **Verification:** Confirming the log file has been updated with the captured keystrokes.
5.  **Exfiltration:** Launching the Server-Client interface. The client automatically connects to the server and transmits the log content successfully.
