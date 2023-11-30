

#include <iostream>

// Абстрактный класс меча
class Sword {
public:
    //Виртуальная функция forge() объявлена равной нулю, что делает класс абстрактным
    virtual void forge() const = 0;

    //Виртуальный деструктор для правильного освобождения ресурсов в производных классах
    virtual ~Sword() = default;
};

// Конкретные классы мечей
class Broadsword : public Sword {
public:
    //Реализация виртуальной функции forge() для меча Broadsword
    void forge() const override {
        std::cout << "Forging Broadsword" << std::endl;
    }
};

class Katana : public Sword {
public:
    //Реализация виртуальной функции forge() для меча Katana
    void forge() const override {
        std::cout << "Forging Katana" << std::endl;
    }
};

// Интерфейс фабрики мечей
class SwordFactory {
public:
    //Виртуальная функция createSword() объявлена равной нулю, делая класс абстрактным 
    virtual Sword* createSword() const = 0;

    //Виртуальный деструктор для правильного освобождения ресурсов в производных классах
    virtual ~SwordFactory() = default;
};

// Конкретные классы фабрик мечей
class BroadswordFactory : public SwordFactory {
public:
    //Реализация виртуальной функции createSword() для создания меча Broadsword 
    Sword* createSword() const override {
        return new Broadsword();
    }
};

class KatanaFactory : public SwordFactory {
public:
    //Реализация виртуальной функции createSword() для создания меча Katana.
    Sword* createSword() const override {
        return new Katana();
    }
};

int main() {
    //Использование фабричного метода для создания мечей

    //Создание фабрики для меча Broadsword
    SwordFactory* broadswordFactory = new BroadswordFactory();
    //Создание меча Broadsword с использованием фабрики и вызов его метода forge()
    Sword* broadsword = broadswordFactory->createSword();
    broadsword->forge();

    //Создание фабрики для меча Katana
    SwordFactory* katanaFactory = new KatanaFactory();
    //Создание меча Katana с использованием фабрики и вызов его метода forge()
    Sword* katana = katanaFactory->createSword();
    katana->forge();

    // Освобождение ресурсов (очистка памяти)
    delete broadsword;
    delete broadswordFactory;
    delete katana;
    delete katanaFactory;

    return 0;
}
