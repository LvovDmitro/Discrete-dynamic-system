// ДДС - постройка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

int main()
{
    int size = 10000000;
    double** T = new double* [size];

    for (int count = 0; count < size; count++)
    {
        T[count] = new double[2];
    }
    ifstream file("C:\\Users\\user\\source\\repos\\Дискретная динамическая система\\Дискретная динамическая система\\p.txt");
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file >> T[i][0];
            file >> T[i][1];
            i++;
        }
    }
    file.close();
    
    Color treecolor = Color::White;
    VertexArray list;
    Vector2f point;
    for (int n = 0; n < size; n++)
    {
        point.x = -2000 + 700 * T[n][0];
        point.y = 700 - 700 * T[n][1];
        list.append(Vertex(point, treecolor));
    }
    RenderWindow window(VideoMode(1000, 600, 32), "SFML Graphics");
    while (window.isOpen())
    {
        for (Event event; window.pollEvent(event);)
        {
            if (event.type == Event::Closed)
                window.close();
                    }
        window.clear();
        window.draw(list);
        window.display();
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
