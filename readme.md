## What for ?
这个仓库是用来线上存放 qwelz 的，数据结构课程的实验作业的代码

## 说明
* 一共 8 个实验，所以分别有 8 个工程文件夹，Exp1~Exp8，每一个文件都是一个完整的 C 工程
* 纯 C 语言 实现，C99 标准
* 实验要求参见根目录下的 experiments.md 文件
* 每个 cmake-build-debug 文件夹下，有已经编译好的 .exe 文件(Windows 64位系统)。

## compile.bat 文件
* 根目录下有一个 compile.bat 文件，显然这是用于 windows 环境的脚本。
* 仅适用于 cmake + MinGW 进行编译
* 如果要使用上述环境编译，只需要将这个脚本复制到 Exp[1-8] 文件夹下，点击运行即可完成编译(前提是 cmake 和 MinGW 都已经被添加到环境变量下)