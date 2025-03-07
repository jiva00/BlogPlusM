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
        ClickAtPosition(720, 220);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(900, 690);
        ClickAtPosition(900, 690);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1370, 720);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1370, 835);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(900, 620);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker3() {
    while (autoRunning) {
        ClickAtPosition(720, 220);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(900, 690);
        ClickAtPosition(900, 690);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1370, 775);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1370, 835);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(900, 620);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker4() {
    while (autoRunning) {
        ClickAtPosition(961, 294);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(1201, 921);
        ClickAtPosition(1201, 921);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1828, 961);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1828, 1041);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1201, 828);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker5() {
    while (autoRunning) {
        ClickAtPosition(961, 294);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(1201, 921);
        ClickAtPosition(1201, 921);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1828, 961);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1828, 1114);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1201, 828);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker6() {
    while (autoRunning) {
        ClickAtPosition(961, 294);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(1201, 921);
        ClickAtPosition(1201, 921);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1828, 1034);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1828, 1114);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1201, 828);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker7() {
    while (autoRunning) {
        ClickAtPosition(580, 180);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(730, 535);
        ClickAtPosition(730, 535);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1075, 560);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1075, 645);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(730, 490);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void AutoClicker8() {
    while (autoRunning) {
        ClickAtPosition(580, 180);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        ClickAtPosition(730, 535);
        ClickAtPosition(730, 535);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1075, 600);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(1075, 645);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        ClickAtPosition(730, 490);
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
                else if (mode == 'E' || mode == 'e') autoClickerThread = std::thread(AutoClicker5);
                else if (mode == 'F' || mode == 'f') autoClickerThread = std::thread(AutoClicker6);
                else if (mode == 'G' || mode == 'g') autoClickerThread = std::thread(AutoClicker7);
                else if (mode == 'H' || mode == 'h') autoClickerThread = std::thread(AutoClicker8);

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
    std::cout << "블로그 플러스 매크로 2.2.1ver 입니다.\n"
        << "제작자 : 준벗\n\n"
        << "해상도 1920*1080, 2560*1440만 지원합니다.\n"
        << "블로그플러스 등록 계정 1개와 2개만 지원합니다.\n\n"
        << "스크롤을 위로 끝까지 올리고 북마크를 꺼야 정상 작동합니다.\n\n"
        << "사용자의 이용환경을 선택해주세요.\n"
        << "A. 1920*1080 - 1개 계정\n"
        << "B. 1920*1080 - 2개 계정 - 1번 계정\n"
        << "C. 1920*1080 - 2개 계정 - 2번 계정\n"
        << "D. 2560*1440 - 1개 계정\n"
        << "E. 2560*1440 - 2개 계정 - 1번 계정\n"
        << "F. 2560*1440 - 2개 계정 - 2번 계정\n\n\n"
        << "아래는 이*욱의 노트북 세팅 디스플레이 125%, 화면 75% 1080전용 세팅입니다. 제발~ 그만 고치게 해줘~\n"
        << "G. 1920*1080 - 2개 계정 - 1번 계정\n"
        << "H. 1920*1080 - 2개 계정 - 2번 계정\n"
        << "대소문자 구분없이 A ~ H 중 골라주세요. : " ;

    char selection;
    std::cin >> selection;

    std::cout << "\n자동모드가 실행됩니다. F9를 누르면 시작, F10을 누르면 종료됩니다.\n";
    std::thread autoModeThread(AutoModeListener, selection);
    autoModeThread.join();

    return 0;
}
