2. Реализация двух вариаций циклического буффера//
Обе реализации циклического буффера имеют одинаковый внешний интерфейс:
в конструкторе задается размер буффера, который остается неизменным все
время жизни объекта (причем вызов конструктора без параметров запрещен),
функции write, read и print. Первая функция позволяет записать новый элемент в буффер,
вторая функция возвращает элемент, который был записан раньше остальных, а 
последняя функция выводит в консоль на одной строке все доступные элементы буффера.//
//
Внутри реализации отличаются типом контейнера, в котором хранятся элементы буффера.
std::vector и std::list для RingBuffVec и RingBuffList соответственно. В буффере,
основанном на векторе при создании объекта выделяется память под массив объектов,
которые должны будут храниться в буффере. Таким образом, все время жизни объекта буффера
он будет распологать элементы в фиксированном участке памяти постоянного размера.
Вторая же реализация основана на двусвязном списке, что позволяет добавлять и удалять
элементы с обоих концов списка. Так изначально буффер будет пустым, и память под
элементы не будет выделена, но при добавлении нового элемента в буффер будет
производиться выделение памяти под новый элемент. Таким образом, реализация буффера
с помощью вектора будет постоянно занимать в памяти под максимальное количество
элементов буффера, но не будет тратить время на выделение памяти и удаление 
ненужных элементов. Буффер, основанный на двусвязном списке будет вести себя обратным
способом, то есть занимает место в памяти только под нужное количество элементов,
но тратит время на работу с памятью. 
