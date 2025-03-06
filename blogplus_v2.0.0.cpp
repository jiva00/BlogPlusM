#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

bool running = false;
bool autoRunning = false;

void ClickAtPosition(int x, int y) {
    SetCursorPos(x, y);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void ClickFourTimes() {
    ClickAtPosition(900, 670);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    ClickAtPosition(1380, 715);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    ClickAtPosition(1342, 792);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    ClickAtPosition(888, 605);
}

void RefreshPage() {
    keybd_event(VK_F5, 0, KEYEVENTF_SCANCODE, 0);
    keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
}

void ListenForKeyPress() {
    while (true) {
        if (GetAsyncKeyState(VK_F5) & 0x8000) {
            if (!running) {
                running = true;
                std::cout << "F5 입력 감지. 클릭 실행.\n";
            }
            RefreshPage();
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
            ClickFourTimes();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void AutoClicker() {
    while (autoRunning) {
        ClickAtPosition(700, 230);
        ClickAtPosition(900, 670);
        ClickAtPosition(1380, 715);
        ClickAtPosition(1342, 792);
        ClickAtPosition(888, 605);
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

void AutoModeListener() {
    while (true) {
        if (GetAsyncKeyState(VK_F9) & 0x8000) {
            if (!autoRunning) {
                autoRunning = true;
                std::cout << "F9 입력 감지. 자동 클릭 시작.\n";
                std::thread autoClickerThread(AutoClicker);
                autoClickerThread.detach();
            }
        }
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            if (autoRunning) {
                autoRunning = false;
                std::cout << "F10 입력 감지. 자동 클릭 종료.\n";
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::cout << "블로그 플러스 매크로 2.0.0ver 입니다.\n"
        << "제작자 : 준벗\n\n"
        << "해상도 1920*1080, 2560*1440만 지원합니다.\n"
        << "블로그플러스 등록 계정 1개와 2개만 지원합니다.\n\n"
        << "스크롤을 위로 끝까지 올리고 북마크를 꺼야 정상 작동합니다.\n\n"
        << "2.0.0ver는 1080p해상도의 1개계정 수동과 자동만 작동합니다.\n\n"
        << "희망하는 메뉴를 선택해주세요.\n"
        << "A : 수동모드\n"
        << "B : 자동모드\n";
    char mode;
    std::cin >> mode;

    if (mode == 'A' || mode == 'a') {
        std::cout << "\n수동모드입니다.\n사용자의 이용환경을 선택해주세요.\nA. 1920*1080\nB. 2560*1440\n";
        char resolution;
        std::cin >> resolution;
        if (resolution == 'A' || resolution == 'a') {
            std::cout << "\n수동모드 1920*1080을 선택하셨습니다.\n사용자의 계정은 몇개 인가요?\nA. 1개\nB. 2개\n";
            char account;
            std::cin >> account;
            if (account == 'A' || account == 'a') {
                std::cout << "\n수동모드 1080p 계정 1개의 매크로를 시작합니다.\nF5를 누르면 4번의 클릭을 자동으로 합니다.\n";
                std::thread listenerThread(ListenForKeyPress);
                listenerThread.join();
            }
            else {
                std::cout << "아직 구현되어있지 않습니다.\n";
            }
        }
        else {
            std::cout << "아직 구현되어있지 않습니다.\n";
        }
    }
    else if (mode == 'B' || mode == 'b') {
        std::cout << "\n자동모드입니다.\n사용자의 이용환경을 선택해주세요.\nA. 1920*1080\nB. 2560*1440\n";
        char resolution;
        std::cin >> resolution;
        if (resolution == 'A' || resolution == 'a') {
            std::cout << "\n자동모드 1920*1080을 선택하셨습니다.\n사용자의 계정은 몇개 인가요?\nA. 1개\nB. 2개\n";
            char account;
            std::cin >> account;
            if (account == 'A' || account == 'a') {
                std::cout << "\n자동모드 1080p 계정 1개의 매크로를 시작합니다.\nF9를 누르면 작동 시작. F10을 누르면 작동 종료.\n";
                std::thread autoModeThread(AutoModeListener);
                autoModeThread.join();
            }
            else {
                std::cout << "아직 구현되어있지 않습니다.\n";
            }
        }
        else {
            std::cout << "아직 구현되어있지 않습니다.\n";
        }
    }
    else {
        std::cout << "잘못된 입력입니다.\n";
    }
    return 0;
}
