Для компиляции файлов с командной строки с помощью g++ вам нужно будет прописать следующее:

g++ -c file1.cpp file2.cpp file3.cpp

Таким образом мы создадим file1.o, file2.o и file3.o. -c означает «только скомпилировать», т.е. просто создать .o (объектные) файлы. Есть и другие компиляторы для Linux, Windows и других операционных систем.

После того, как компоновщик закончит линкинг всех объектных файлов (при условии, что не будет ошибок), вы получите исполняемый файл. Опять же, в целях наглядности, чтобы связать .o файлы, которые мы создали выше в Linux или macOS, мы можем снова использовать g++:

g++ -o prog file1.o file2.o file3.o

Команда -o сообщает g++, что мы хотим получить исполняемый файл с именем prog из следующих файлов: file1.o, file2.o и file3.o. При желании, компиляцию и линкинг можно объединить в один шаг:

g++ -o prog file1.cpp file2.cpp file3.cpp

Результатом будет исполняемый файл с именем prog.

Вы можете отключить расширения компилятора, добавив флаг -pedantic-errors в командную строчку компиляции.

Изменение уровня предупреждений

   Добавьте следующие флаги в вашу командную строку:

   -Wall -Weffc++ -Wextra -Wsign-conversion

Обрабатывать предупреждения как ошибки

   Добавьте следующий флаг в вашу командную строку:

   -Werror

Установка стандарта языка С++ в GCC/G++ 

   В GCC/G++ вы можете прописать соответствующие флаги -std=c++11, -std=c++14, -std=c++17 или -std=c++2a, чтобы подключить функционал C++11/14/17/20, соответственно.

Популярные веб-компиляторы:

   OnlineGDB (https://www.onlinegdb.com/online_c++_compiler)

   TutorialsPoint (https://www.tutorialspoint.com/compile_cpp_online.php)

   C++ Shell (http://cpp.sh/)

   Repl.it (https://repl.it/languages/cpp)

#pragma once
   Большинство компиляторов поддерживают более простую, альтернативную форму header guards — директиву #pragma
   #pragma once используется в качестве header guards, но имеет дополнительные преимущества — она короче и менее подвержена ошибкам.
   Однако, #pragma once не является официальной частью языка C++, и не все компиляторы её поддерживают (хотя большинство современных компиляторов поддерживают).