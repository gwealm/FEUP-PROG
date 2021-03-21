#!/usr/bin/bash

current="$(pwd)"
PATH1=$1


cd "$(pwd)/$PATH1"

for file in *; do
    # sed -s "/(.*).cpp/$1/" $file
    new_name=$($file | cut -d '.' -f2)
    echo $new_name
    # mkdir $new_name
    # mv $file 'main.cpp'
    # mv 'main.cpp' $new_name

    #  cut -d '.' -f2
    # mv "$file" "main.cpp"
    # mkdir "$file"
    # mv "main.cpp" "./$file"
done