# Serializing_n_Deserializing_tree_of_pointers

Cохранение и восстановление дерева указателей.<br>

Реализована простая иерархия классов для хранения нескольких простых типов данных: int (32 бита); char[10]; double. Абстрактный базовый класс – BaseHolder, и его наследники – IntHolder, CharArrayHolder и DoubleHolder. Далее используется структура данных — дерево указателей на базовый класс — и наполнение его в теле программы "serialize" несколькими произвольными элементами, используя разные типы (int , char[], double).<br>
Данные сохраняются в текстовый файл.<br>

Сериализация и десериализация в одном тесте (данные в файле serialized_data.txt):<br>
$ make<br>
$ ./test<br>

Сериализация и десериализация как отдельные программы (имя файла для сериализации/десериализации передаётся как параметр):<br>
$ make serialize<br>
$ ./serialize file_name<br>

$ make deserialize<br>
$ ./deserialize file_name<br>

<p><img src="https://lh3.googleusercontent.com/pw/AM-JKLUSUYYzqxk9PCfJFPkQdAAqGSD3rZ8Mk3iOXFpbfnceHd6LeiN9L2TDq-EsRRZnoma1PPzMPOLDwvV_CArIH5UTtKrX4_SGUfO_wYJXVyQakj3qsLydOFTrYwJQoAHvmGVG6czCouTVYxg_6zCrrMUJ=w470-h318-no?authuser=0" alt="Ссылка"></p>
