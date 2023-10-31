#!/bin/bash

# Создаем директорию для исполнения скрипта
if [ ! -d "test" ]; then
    mkdir "test"
fi

# Переходим в директорию test
cd "test"

# Создаем файлы [1..20].txt и записываем в них
# их имя одной операцией
for i in {1..20}; do
    echo $i.txt > $i.txt
done

# Удаление файлов
shopt -s extglob
rm !(*\4*).txt

# Записываем что-нибудь в 14.txt
echo "lab_2" > 14.txt

# Удаляем результат
rm -f *.txt
rm -rf 1
rm -rf 2
rm -rf 3
rm -rf 4

# Создаем директории для файлов
mkdir -p 1 2/2 3/3/3 4/4/4/4

# Заполняем директории файлами
touch 1/1.txt 2/2/2.txt 3/3/3/3.txt 4/4/4/4/4.txt

# Создаем симлинки
for j in $(find . | grep -E '^\./[0-9]+$');
do
  j=${j#"./"}
  
  d=$(pwd)

  for i in $(seq "$j");
  do
    cd $j
  done;

  ln -sf "$(pwd)/$j.txt" "$d/$j.txt"
  cd $d
done;
