#!/bin/bash

# Кол-во запускаемых процессов
num_processes=5

# Цикл для создания дочерних процессов
for ((i=0; i<num_processes; i++)); do
	sleep 300 &
done

# Дожидаемся завершения всех процессов
wait

# Запись кол-ва отработанных процессов в файл
echo $num_processes > processes_counted.txt

# Ожидание в 1 час
sleep 3600
