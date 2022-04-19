#include "help.h"
#include "iostream"

void help() {
    std::cout << "Программа для применения фильтров" << std::endl;
    std::cout << "Программа принимает изображение, применяет к нему фильтры и выгружает результат" << std::endl;
    std::cout << "Обязательные аргументы программы:" << std::endl;
    std::cout << "1. Путь к файлу с преобразуемым изображением" << std::endl;
    std::cout << "2. Путь к файлу для выгрузки результата" << std::endl;
    std::cout << "Необязательные аргументы(применяемые фильтры):" << std::endl;
    std::cout << "1. -crap a b" << std::endl;
    std::cout << "а и б целые, обрезает картинку до размеров а и б, аргументы а и б обязательны" << std::endl;
    std::cout << "2. -gs" << std::endl;
    std::cout << "Преобразует изображение в оттенки серого" << std::endl;
    std::cout << "3. -neg" << std::endl;
    std::cout << "Возвращает негатив" << std::endl;
    std::cout << "4. -sharp" << std::endl;
    std::cout << "Повышает резкость" << std::endl;
    std::cout << "5. -edge threshold" << std::endl;
    std::cout << "Выделяет границы, threshold число от 0 до 1 влияющее на то что считать границей" << std::endl;
    std::cout << "6. -blur sigma" << std::endl;
    std::cout << "Гауссово размытие, sigma - сигма из формулы" << std::endl;
}