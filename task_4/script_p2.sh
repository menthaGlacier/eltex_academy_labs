#!/bin/bash

# Кол-во процессов, которые нужно убить
kill_count=3

# Получаем PID основного процесса из скрипта п.1.
parent=$(pgrep -f "script_p1.sh")

# Получаем список дочерних процессов
pids=($(pgrep -P $parent))

# Получаем кол-во дочерних процессов
total_pids=${#pids[@]}
echo $total_pids

# Проверяем, что в списке есть хотя бы необходимое (3) процесса
if [ $total_pids -ge $kill_count ]; then
	# Итерируемся по последним элементам списка и беспощадно убиваем процессы
	for ((i = $total_pids - 1; i >= $total_pids - $kill_count; i--)); do
		pid_to_kill=${pids[i]}
		echo "Беспощадно убил процесс с PID $pid_to_kill"
		kill "$pid_to_kill"
	done
else
	echo "Не хватает детей для убийства"
fi
