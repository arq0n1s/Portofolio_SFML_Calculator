#include <SFML/Graphics.hpp>
#include <iostream>
#include "Calculator.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 600), L"SFML Калькулятор"); // Создаем окно
    auto font = std::make_unique<sf::Font>(); // Загружаем шрифт
    if (!font->loadFromFile("ArialMT.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!\n";
        return -1;
    }

    Calculator calculator(*font); // Создаем калькулятор

    while (window.isOpen()) { // Главный цикл
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close(); // Закрытие окна
            calculator.handleEvent(event, window); // Обработка событий
        }

        window.clear(); // Очистка экрана
        window.draw(calculator); // Отрисовка калькулятора
        window.display(); // Показываем результат
    }
    return 0;
}