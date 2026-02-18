#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Link with Winsock library

using namespace std;

int main()
{
	// Initialize Winsock
	WSADATA wsaData;
	int wsaInit = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (wsaInit != 0) {
		cerr << "Failed to initialize Winsock. Error Code: " << wsaInit << endl;
		return -1;
	}

	// Creating socket
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET) {
		cerr << "Socket creation failed. Error: " << WSAGetLastError() << endl;
		WSACleanup();
		return -1;
	}

	// Specifying the address
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	// Binding socket
	if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
		cerr << "Bind failed. Error: " << WSAGetLastError() << endl;
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}

	// Listening to the assigned socket
	if (listen(serverSocket, 5) == SOCKET_ERROR) {
		cerr << "Listen failed. Error: " << WSAGetLastError() << endl;
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}
	cout << "Server is listening on port 8080..." << endl;
	// Accepting connection request
	SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
	if (clientSocket == INVALID_SOCKET) {
		cerr << "Failed to accept connection. Error: " << WSAGetLastError() << endl;
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}

	// Receiving data
	char buffer[1024] = { 0 };
	int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
	if (bytesRead > 0) cout << "Message from client: " << string(buffer, 0, bytesRead) << endl;
	

	// Closing the client and server sockets
	closesocket(clientSocket);
	closesocket(serverSocket);

	// Cleanup Winsock
	WSACleanup();

	cin.get();

	return 0;
}