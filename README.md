## Laboratory work III

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

```bash
$ open https://git-scm.com
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab03** и с лиценцией **MIT**
- [x] 2. Ознакомиться со ссылками учебного материала
- [x] 3. Выполнить инструкцию учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Toshuxanoff
$ export GITHUB_EMAIL=tosha.uhanoff@yandex.ru
$ alias edit=nano
```

```ShellSession
$ mkdir lab03 && cd lab03  #создание директории и переход в неё
$ git init	#создание локального репозитория
$ git config --global user.name ${GITHUB_USERNAME}	#первоначальная настройка данных пользователя
$ git config --global user.email ${GITHUB_EMAIL}
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03 #добавление удаленного репозитория
$ git pull origin master	 #получение данных
$ touch README.md	 #создание файла
$ git status 	#определение состояния файлов (отслеживаемые или нет)
$ git add README.md	#добавление файла в версионный контроль (отслеживание)
$ git commit -m"added README.md"	#коммит с комментарием
$ git push origin master 	#пуш данных в репозиторий
```

Добавить на сервисе **GitHub** в репозитории **lab03** файл **.gitignore**
со следующем содержимом:

```ShellSession
*build*/
*install*/
*.swp
```

```ShellSession
$ git pull origin master	 #получение данных из репозитория
$ git log			#получение истории коммитов
```

```ShellSession
$ mkdir sources       #создание директории для файлов исходного кода
$ mkdir include				#создание директории для заголовочных файлов
$ mkdir examples      #создание кода для примеров
$ cat > sources/print.cpp <<EOF		
#include <print.hpp>

void print(const std::string& text, std::ostream& out) {
  out << text;
}

void print(const std::string& text, std::ofstream& out) {
  out << text;
}
EOF                  #заполнение файла исходного кода
```

```ShellSession
$ cat > include/print.hpp <<EOF
#include <string>
#include <fstream>
#include <iostream>

void print(const std::string& text, std::ostream& out = std::cout);
void print(const std::string& text, std::ofstream& out);
EOF              #заполнение заголовочного файла
```

```ShellSession
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv) {
  print("hello");
}
EOF               #заполнение файла с примером 1
```

```ShellSession
$ cat > examples/example2.cpp <<EOF
#include <fstream>
#include <print.hpp>

int main(int argc, char** argv) {
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF              #заполнение файла с примером 2
```

```ShellSession
$ edit README.md		
```

```ShellSession
$ git status			#состояние новых файлов
$ git add .	
$ git commit -m"added sources"		#коммит новых файлов
$ git push origin master
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [GitHub](https://github.com)
- [Bitbucket](https://bitbucket.org)
- [Gitlab](https://about.gitlab.com)
- [LearnGitBranching](http://learngitbranching.js.org/)

```
Copyright (c) 2017 Братья Вершинины
```
