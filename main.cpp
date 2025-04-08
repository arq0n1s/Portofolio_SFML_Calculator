#include <SFML/Graphics.hpp>
#include <iostream>
#include "Calculator.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 600), L"SFML �����������"); // ������� ����
    auto font = std::make_unique<sf::Font>(); // ��������� �����
    if (!font->loadFromFile("ArialMT.ttf")) {
        std::cerr << "�� ������� ��������� �����!\n";
        return -1;
    }

    Calculator calculator(*font); // ������� �����������

    while (window.isOpen()) { // ������� ����
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close(); // �������� ����
            calculator.handleEvent(event, window); // ��������� �������
        }

        window.clear(); // ������� ������
        window.draw(calculator); // ��������� ������������
        window.display(); // ���������� ���������
    }
    return 0;
}