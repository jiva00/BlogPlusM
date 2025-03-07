#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

bool autoRunning = false;

void ClickAtPosition(int x, int y) {
    SetCursorPos(x, y);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void AutoClicker1() {
    while (autoRunning) {
        ClickAtPosition(720, 220);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(900, 690);
        ClickAtPosition(900, 690);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1370, 720);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1370, 780);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(900, 620);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker2() {
    while (autoRunning) {
        ClickAtPosition(800, 250);
        ClickAtPosition(950, 700);
        ClickAtPosition(1400, 750);
        ClickAtPosition(1400, 800);
        ClickAtPosition(950, 650);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker3() {
    while (autoRunning) {
        ClickAtPosition(1000, 300);
        ClickAtPosition(1100, 750);
        ClickAtPosition(1600, 800);
        ClickAtPosition(1600, 850);
        ClickAtPosition(1100, 700);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker4() {
    while (autoRunning) {
        ClickAtPosition(1050, 350);
        ClickAtPosition(1150, 800);
        ClickAtPosition(1650, 850);
        ClickAtPosition(1650, 900);
        ClickAtPosition(1150, 750);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoModeListener(char mode) {
    while (true) {
        if (GetAsyncKeyState(VK_F9) & 0x8000) {
            if (!autoRunning) {
                autoRunning = true;
                std::cout << "F9 입력 감지. 자동 클릭 시작.\n";
                std::thread autoClickerThread;

                if (mode == 'A' || mode == 'a') autoClickerThread = std::thread(AutoClicker1);
                else if (mode == 'B' || mode == 'b') autoClickerThread = std::thread(AutoClicker2);
                else if (mode == 'C' || mode == 'c') autoClickerThread = std::thread(AutoClicker3);
                else if (mode == 'D' || mode == 'd') autoClickerThread = std::thread(AutoClicker4);

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
    std::cout << "블로그 플러스 매크로 2.1.0ver 입니다.\n"
        << "제작자 : 준벗\n\n"
        << "해상도 1920*1080, 2560*1440만 지원합니다.\n"
        << "블로그플러스 등록 계정 1개와 2개만 지원합니다.\n\n"
        << "스크롤을 위로 끝까지 올리고 북마크를 꺼야 정상 작동할 가능성이 높습니다.\n\n"
        << "사용자의 이용환경을 선택해주세요.\n"
        << "A. 1920*1080 - 1개 계정\n"
        << "B. 1920*1080 - 2개 계정\n"
        << "C. 2560*1440 - 1개 계정\n"
        << "D. 2560*1440 - 2개 계정\n";

    char selection;
    std::cin >> selection;

    std::cout << "\n자동모드가 실행됩니다. F9를 누르면 시작, F10을 누르면 종료됩니다.\n";
    std::thread autoModeThread(AutoModeListener, selection);
    autoModeThread.join();

    return 0;
}
