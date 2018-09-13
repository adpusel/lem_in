#!/usr/bin/env bash

function print_separateur()
{

    echo -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    echo "     -- $1 -- "
    echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    echo -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    echo =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    echo -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
}

# permet de print un nombre de ligne donnee en green
function print_argv()
{
    nb_line="$1"
    file="$2"

    text=` cat "$file" | head -n 1`
    echo "\033[1;31m----> $text \033[0m"
}

function run_test()
{
    name_test="$1"
    print_separateur "test $name_test"

    cat "$name_test/tuto.txt"

    for file in `cd "$name_test" ; ls`
        do

            path_file="$name_test/$file"

            if [ "$file" != "tuto.txt" ]
            then
                    echo "\033[1;32m----> $path_file\033[0m"
                    print_argv 1 "$path_file"
                    ./lem-in < "$path_file" | head -n 1
                    echo
            fi
    done
    echo
}


run_test "1__bad_ants"
#run_test "2__err_room"
#run_test "3__link_no_work"
#run_test "4__link_work"
#run_test "5__comment"
#run_test "other_test"
#run_test "other_good"
#run_test "dur_test"
