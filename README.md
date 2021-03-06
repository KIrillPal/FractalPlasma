# FractalPlasma
Это учебный проект по визуализации фрактальной плазмы. Он использует SFML 2.5.1. и написан на C++ в Visual Studio.
Сложно не заметить его сходство с проектом [MandelbrotViewer](https://github.com/KIrillPal/MandelbrotViewer), ведь они имеют общую основу.
# Подключение и использование
Чтобы запустить приложение, скачайте архив [Release.zip](https://github.com/KIrillPal/MandelbrotViewer/blob/main/Release.zip) из корня проекта и запустить в нём файл FractalPlasma.exe.
После ввода откроется консоль и предложит выбрать два параметра.

1. Время отображения кадра - необходимая пауза между генерацией нового изображения
1. Диапазон случайности - главная переменная в генерации, отображающая то, насколько новый пиксель может отличаться от двух или четырёх его образующих.
При вводе диапазона 0 будет выведен градиент. 

!!ВАЖНО: Программа не защищена от данных не по формату. Она упадёт, если подставлять в неё что-то, кроме целых положительных числел.

Наконец, откроется окно:
![pl1](https://github.com/KIrillPal/FractalPlasma/blob/main/README_Images/pl1.jpg)

# Структура проекта
Здесь описано, какие файлы содержатся в проекте и их предназначение в общих чертах.

## 1. SnowKOH.cpp
Это главный файл, содержащий функцию main. Он отвечает за любые действия с окном и его отрисовку. Также именно в нём просчитывается сама плазма. Фактически, этот файл содержит в себе всю программу.

- Новые пиксели имеют цвет, определяемый в функциях `mid` и `rmid`.
- Генерация нового изображения происходит в функции `drawfield`.
- Также имеются вспомогательные структуры `color`(rgb одной структурой) и `vertex`(точка, имеющая цвет).

# Замечания
Для запуска проекта в Visual Studio необходим доступ среды к SFML 2.5.1. Эта библиотека должна находиться по пути `D:\Program Files\SFML-2.5.1`. Чтобы выбрть другую папку для SFML, зайдите в `Проект -> C/C++ -> Общие -> Дополнитеьные каталоги включаемых файлов`, а затем измените каталог и версию на нужное. Аналогично нужно поменять данные по пути `Проект -> Компоновщик -> Общие -> Дополнитеьные каталоги библиотек`.

# Особенности проекта
Этот проект был дан в школе для отработки навыков работы с фракталами/графикой. Проект мега простой, полностью соответсвует ТЗ.