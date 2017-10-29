[![Build Status](https://travis-ci.org/ToshUxanoff/lab06.svg?branch=master)](https://travis-ci.org/ToshUxanoff/lab06)
## Laboratory work VIII

Данная лабораторная работа посвещена изучению средств пакетирования на примере **CPack**

```ShellSession
$ open https://cmake.org/Wiki/CMake:CPackPackageGenerators
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial
Установка переменных окружения
```ShellSession
$ export GITHUB_USERNAME=ToshUxanoff
$ export GITHUB_EMAIL=toshuxanoff@gmail.com
$ alias edit=nano
$ alias gsed=sed # for *-nix system
```
Клонирование репозитория предыдущей лабы в новую директорию
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 projects/lab08
$ cd projects/lab08
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08
```
Редактирование файла CMakeLists.txt, установка значений Tweak, Patch, Minor, Major - версии (0.1.0.0)
```ShellSession
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION \
\${PRINT_VERSION_MAJOR}.\${PRINT_VERSION_MINOR}.\${PRINT_VERSION_PATCH}.\${PRINT_VERSION_TWEAK})
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_TWEAK 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_PATCH 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_MINOR 1)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_MAJOR 0)
' CMakeLists.txt
```
Создание файла описания и истории изменений и редактирование последнего. Вставка своих контактов в этот файл.
```ShellSession
$ touch DESCRIPTION && edit DESCRIPTION
$ touch ChangeLog.md
$ export DATE="`LANG=en_US date +'%a %b %d %Y'`"
$ cat > ChangeLog.md <<EOF
* ${DATE} ${GITHUB_USERNAME} <${GITHUB_EMAIL}> 0.1.0.0
- Initial RPM release
EOF
```
Редактирование CPackConfig.cmake (подключение требуемых библиотек)
```ShellSession
$ cat > CPackConfig.cmake <<EOF
include(InstallRequiredSystemLibraries) 
EOF
```
Вставка контактных данных, версии, пути к Description и комментария к файлу
```ShellSession
$ cat >> CPackConfig.cmake <<EOF
set(CPACK_PACKAGE_CONTACT ${GITHUB_EMAIL})
set(CPACK_PACKAGE_VERSION_MAJOR \${PRINT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR \${PRINT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH \${PRINT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION_TWEAK \${PRINT_VERSION_TWEAK})
set(CPACK_PACKAGE_VERSION \${PRINT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE \${CMAKE_CURRENT_SOURCE_DIR}/DESCRIPTION)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "static c++ library for printing")
EOF
```
Указание пути к License и Readme
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RESOURCE_FILE_LICENSE \${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README \${CMAKE_CURRENT_SOURCE_DIR}/README.md)
EOF
```

```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RPM_PACKAGE_NAME "print-devel") #имя пакета
set(CPACK_RPM_PACKAGE_LICENSE "MIT")      #имя лизензии
set(CPACK_RPM_PACKAGE_GROUP "print")      #группа пакета print 
set(CPACK_RPM_PACKAGE_URL "https://github.com/${GITHUB_USERNAME}/lab07")    #ссылка на github-репозиторий
set(CPACK_RPM_CHANGELOG_FILE \${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog.md)      #путь к файлу истории изменений
set(CPACK_RPM_PACKAGE_RELEASE 1)      #релиз = 1
EOF
```
Аналогично для debian
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_DEBIAN_PACKAGE_NAME "libprint-dev")   #имя пакета - libprint-dev
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://${GITHUB_USERNAME}.github.io/lab07") #домашняя страница - ссылка на репозиторий 
set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "cmake >= 3.0")   #требуемая версия cmake >= 3.0
set(CPACK_DEBIAN_PACKAGE_RELEASE 1) 
EOF
```
Включение CPack и CPackConfig.make
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

include(CPack)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF

include(CPackConfig.cmake)
EOF
```
Замена lab07 на lab08
```ShellSession
$ gsed -i 's/lab07/lab08/g' README.md
```
Пуш изменений
```ShellSession
$ git add .
$ git commit -m"added cpack config"
$ git push origin master
```
Подключение трэвиса
```ShellSession
$ travis login --auto
$ travis enable
```

```ShellSession
$ cmake -H. -B_build    #сканирование CMakeLists.txt
$ cmake --build _build    #создание build
$ cd _build   #переход в неё
$ cpack -G "TGZ" #тип архивирования - TGZ
$ cd ..
```

```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ"  #задаем архивирование - TGZ
$ cmake --build _build --target package   #архивирование
```
Создание директории Artifacts и перемещение в неё архивированного файла
```ShellSession
$ mkdir artifacts
$ mv _build/*.tar.gz artifacts
$ tree artifacts
artifacts
 └── print-0.1.0.0-Darwin.tar.gz
```
Редактирование отчета
## Report

```ShellSession
$ popd
$ export LAB_NUMBER=08
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [DMG](https://cmake.org/cmake/help/latest/module/CPackDMG.html)
- [DEB](https://cmake.org/cmake/help/latest/module/CPackDeb.html)
- [RPM](https://cmake.org/cmake/help/latest/module/CPackRPM.html)
- [NSIS](https://cmake.org/cmake/help/latest/module/CPackNSIS.html)

```
Copyright (c) 2017 Братья Вершинины
