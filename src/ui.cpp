#define YELLOW "\033[33m"
#define RESET "\033[0m"

// NOTE: unused TXLib? //used
// #include <TXLib.h>
#include <stdio.h>
#include <windows.h>

#include "ui.h"
#include "string_funcs.h"
#include "constants.h"

void greeting()
{
    slow_print(YELLOW "����� ���������� �� �������� ���� \"������\"\n");
    Sleep(SHORT_SLEEP);
    slow_print("����: ������� ����(1), ������ ����(2)\n");
}

void tell_rools()
{
    slow_print("������ ����� �������� ����� ������������ � ������ ������ ������� �����\n");
    Sleep(SHORT_SLEEP);

    slow_print("����� ������ �������� ����� �� ��������� ����� ������ ������� ������\n");
    Sleep(SHORT_SLEEP);

    slow_print("���� ����� ������� ������ ������������� �� ������� ��� ������ ����, � ����� � � �\n");
    Sleep(SHORT_SLEEP);

    slow_print("������ �������� ����� �� ������������� �����\n");
    Sleep(SHORT_SLEEP);

    slow_print("���� ������������ �� ��� ���, ���� ���� �� ��� �� ������ ������� ���������� �����\n\n");
    Sleep(SHORT_SLEEP);

    slow_print("���� �� �� ������ ������ �������, ������� end\n");
    Sleep(LONG_SLEEP);

    printf("��� ���� ����� ������ ���� ������� Enter\n\n");
    getchar();
    getchar();
    printf("\033[1A");
}

void begin_game()
{
    slow_print("�������, ������� ������ ����\n");
    Sleep(SHORT_SLEEP);

    slow_print("������� ���� ������ �����\n");
    Sleep(SHORT_SLEEP);

    //slow_print("��� ������, � ��������� ������� ������ ����, ��� �� ��� ������ ����\n");
    //Sleep(LONG_SLEEP);
}

void goto_next_phrase() {
    getchar();
    printf("\x1b[A");
}
