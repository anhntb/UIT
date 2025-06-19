## Getting Started

Welcome to the VS Code Java world. Here is a guideline to help you get started to write Java code in Visual Studio Code.

## Folder Structure

The workspace contains two folders by default, where:

- `src`: the folder to maintain sources
- `lib`: the folder to maintain dependencies

Meanwhile, the compiled output files will be generated in the `bin` folder by default.

> If you want to customize the folder structure, open `.vscode/settings.json` and update the related settings there.

## Dependency Management

The `JAVA PROJECTS` view allows you to manage your dependencies. More details can be found [here](https://github.com/microsoft/vscode-java-dependency#manage-dependencies).


## How to run
### 1. Biên dịch code:
    javac -d ../bin *.java
(Chạy lệnh này trong thư mục `src`, nó sẽ tạo file `.class` trong `bin`.)


### 2. Chạy chương trình:
Di chuyển ra thư mục Fitness (nơi chứa cả `bin` và `lib`): 
    
    cd ..

<br>Chạy lệnh: 

    java -cp "lib/*;bin" App

