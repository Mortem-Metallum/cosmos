#!/bin/bash
while [[ $# -gt 0 ]]; do
    case "$1" in
        clean)
            read -p "autogen.sh: clean: Are you sure? [y/N]: " i
            if [[ "$i" == "Y" || "$i" == "y" ]]; then
                cd build 2>/dev/null
                rm -rf *
            elif [[ "$i" == "N" || "$i" == "n" || "$i" == "" ]]; then
                exit 0
            else
                echo "autogen.sh: Please enter Y or N"
                exit 1
            fi
        ;;
        build)
            cd build
            cmake -G Ninja ..
            ninja -C .
        ;;
        install)
            if [[ "$USER" != "root" ]]; then
                echo "Must be root"
                exit 1
            fi
            cp ./build/comet /usr/bin || cp ./comet /usr/bin
            cp ./build/cosmos /usr/bin || cp ./cosmos /usr/bin
        ;;
        *)
            echo "autogen.sh: Please specify one arg: clean, install, or build"
            exit 1
        ;;
    esac
    shift
done
