#include <iostream>
#include <string>
#include <Windows.h>

// Базовый класс People
class People
{
public:
    // Основные свойства
    std::string name; // Имя человека
    int age;          // Возраст человека

    // Конструктор
    People(std::string n, int a) : name(n), age(a) {}

    // Метод для отображения информации о человеке
    void displayInfo()
    {
        std::cout << "Имя: " << name << ", Возраст: " << age;
    }
};

// Наследуемый класс HomeHyb (Житель дома)
class HomeHyb : public People
{
public:
    // Дополнительное свойство для Resident
    std::string address; // Адрес жителя

    // Конструктор
    HomeHyb(std::string n, int a, std::string addr) : People(n, a), address(addr) {}

    // Метод для отображения информации о жителе
    void displayResidentInfo()
    {
        displayInfo(); // Вызов метода базового класса для отображения имени и возраста
        std::cout << ", Адрес: " << address << "\n"; // Отображение адреса
    }
};

// Наследуемый класс Manager (Управляющий домом)
class Manager : public People
{
public:
    // Дополнительное свойство для Manager
    std::string jobTitle; // Должность управляющего

    // Конструктор
    Manager(std::string n, int a, std::string tit) : People(n, a), jobTitle(tit) {}

    // Метод для отображения информации о менеджере
    void displayManagerInfo()
    {
        displayInfo(); // Вызов метода базового класса для отображения имени и возраста
        std::cout << ", Должность: " << jobTitle << "\n"; // Отображение должности
    }

    // Метод для назначения новой должности
    void assignJobTitle(std::string newTit)
    {
        jobTitle = newTit; // Изменение должности управляющего
        std::cout << name << " теперь имеет должность: " << jobTitle << "\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка локали для корректного отображения русских символов

    // Создание объекта HomeHyb (Житель дома)
    HomeHyb resident("Алиса", 30, "Крупской 34");
    resident.displayResidentInfo(); // Отображение информации о жителе

   

    // Создание объекта Manager (Управляющий домом)
    Manager manager("Степа", 40, "Директор");
    manager.displayManagerInfo(); // Отображение информации о менеджере

  

    // Изменение должности менеджера
    manager.assignJobTitle("Генеральный директор"); // Назначение новой должности

    return 0;
}
