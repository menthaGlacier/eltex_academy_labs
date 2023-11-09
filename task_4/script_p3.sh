#!/bin/bash

# Получаем PID основного процесса
parent=$(pgrep -f "script_p1.sh")

# Получаем PID дочерних процессов
children=($(pgrep -P $parent))

# Убиваем все дочерние процессы перед основным
for pid in $children; do
	kill $pid;
done

# Убиваем основной процесс
kill $parent;
