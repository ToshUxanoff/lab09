[![Build Status](https://travis-ci.org/ToshUxanoff/lab05.svg?branch=master)](https://travis-ci.org/ToshUxanoff/lab05)
## Laboratory work V

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса **Travis CI**

```ShellSession
$ open https://travis-ci.org
```

## Tasks

- [x] 1. Авторизоваться на сервисе **Travis CI** с использованием **GitHub** аккаунта
- [x] 2. Создать публичный репозиторий с названием **lab05** на сервисе **GitHub**
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Включить интеграцию сервиса **Travis CI** с созданным репозиторием
- [x] 5. Получить токен для **Travis CLI** с правами **repo** и **user**
- [x] 6. Получить фрагмент вставки значка сервиса **Travis CI** в формате **Markdown**
- [x] 7. Установить [**Travis CLI**](https://github.com/travis-ci/travis.rb#installation)
- [x] 8. Выполнить инструкцию учебного материала
- [x] 9. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

Создание переменных окружения
```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_TOKEN=<полученный_токен>
```
Клонирование репозитория lab04 в новый lab05
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab04 lab05
$ cd lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```
Редактирование travis.yml (Записываем язык)
```ShellSession
$ cat > .travis.yml <<EOF
language: cpp
EOF
```
Редактирование travis.yml (Записываем скрипт)
```ShellSession
$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF
```
Редактирование travis.yml (Записываем аддоны)
```ShellSession
$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```
Записываем полученный токен
```ShellSession
$ travis login --github-token ${GITHUB_TOKEN}
```
Проверка работоспособности .travis.yml
```ShellSession
$ travis lint
```
Вставка значка в файл отчета
```ShellSession
$ ex -sc '1i|<фрагмент_вставки_значка>' -cx README.md
```
Коммит изменений
```ShellSession
$ git add .travis.yml
$ git add README.md
$ git commit -m"added CI"
$ git push origin master
```
Используем комманды тревиса 
```ShellSession
$ travis lint
Warnings for .travis.yml:
[x] value for addons section is empty, dropping
[x] in addons section: unexpected key apt, dropping
$ travis accounts  #показывает соединенные с ним GitHub аккаунты
ToshUxanoff (Уханов Антон): subscribed, 24 repositories
$ travis sync       #синхронизация
synchronizing: . done
$ travis repos        #отображение репозиториев и их статуса(связаны ли они с Travis)
ToshUxanoff/3_semester_labs (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Course-Prorject (active: no, admin: yes, push: yes, pull: yes)
Description: Hybrid-p2p chat

ToshUxanoff/GatesToHell-HW2- (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/HW1-Set (active: no, admin: yes, push: yes, pull: yes)
Description: Caution!

ToshUxanoff/Lab-1-2-mod- (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab-2.1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab-3.1 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab-5 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab03 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab2-2mod (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab3.-2Mod (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab4 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab4_mod2 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab5_2mod (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab6 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Lab7 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/TaMoP (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/Test-for-Go-2017-park.mail.ru- (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/TestRep (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/beginner-cpp-course-bmstu (active: no, admin: yes, push: yes, pull: yes)
Description: Second semester of course: Programming Languages

ToshUxanoff/lab04 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/lab05 (active: yes, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/lab1.1 (active: no, admin: yes, push: yes, pull: yes)
Description: TString

ToshUxanoff/labs4 (active: no, admin: yes, push: yes, pull: yes)
Description: ???

ToshUxanoff/labs6 (active: no, admin: yes, push: yes, pull: yes)
Description: ???
$ travis enable         # "включить" travis в текущей директории
Detected repository as ToshUxanoff/lab05, is this correct? |yes| 
ToshUxanoff/lab05: enabled :)
$ travis whatsup          #показывает пройденные шаги
ToshUxanoff/lab05 passed: #3
$ travis branches           #показывает сделанные шаги на ветке master 
master:  #3    passed     added CI
$ travis history           #показывает всю историю изменений и их состояние   
#3 passed:       master added CI
$ travis show           #показывает всю информацию
State:         passed
Type:          push
Branch:        master
Compare URL:   https://github.com/ToshUxanoff/lab05/compare/20b563325bbd...4f0dc1c1
Duration:      29 sec
Started:       2017-10-06 13:32:24
Finished:      2017-10-06 13:32:53
Allow Failure: false
Config:        os: linux
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=05
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Travis Client](https://github.com/travis-ci/travis.rb)
- [AppVeyour](https://www.appveyor.com/)
- [GitLab CI](https://about.gitlab.com/gitlab-ci/)

```
Copyright (c) 2017 Братья Вершинины
```
