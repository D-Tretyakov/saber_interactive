# saber_interactive
Репозиторий для выполнения тестового задания

##### Содержание
[1 задание](#1-printbinary)

[2 задание](#2-removedups)

[3 задание](#3-linkedlist)

[Как собирать](#как-запускать)

## #1 PrintBinary
_Нужно написать функцию, которая печатает двоичное представление знакового числа_

Для определенности написал функцию для инта.

Код лежит в папке `PrintBinary`

`PrintBinary.cpp` - непосредственно код функции

`PrintBinaryTests.cpp` - тесты

## #2 RemoveDups
_Нужно написать функцию, которая удаляет последовательно дублирующиеся символы в строке_

Тут проблем не было. Разве что не сразу добавил проверку на nullptr

Код лежит в папке `RemoveDups`

`RemoveDups.cpp` - непосредственно код функции

`RemoveDupsTests.cpp` - тесты

## #3 LinkedList
_Нужно написать сериализацию и десериализацию двусвязного списка_

К своему стыду, первый раз пишу сериализацию вручную, поэтому пришлось повозиться. Особенно затормозил, когда думал о способе сохранения указателя на случайный элемент

Код лежит в папке `LinkedList`

`LinkedList.cpp` - непосредственно код функции

`LinkedListTests.cpp` - тесты


## Как запускать
Для запуска нужен cmake. Для тестирования использовал фреймворк GTest. Тесты автоматически запустятся после окончания сборки. Лично я собирал под windows 11 с генератором ninja
```
mkdir build
cd build
cmake -GNinja ..
ninja
```
Еще проверил под WSL. Единственное, что пришлось дать права на запись для папки, в которой будет сборка, чтобы GTest смог нормально скачаться.
```
mkdir build
chmod u+w build
cmake ..
make
```