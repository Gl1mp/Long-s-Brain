## 背景
我在C盘中使用Git管理项目，现在想去D盘创建一个新的Git仓库。当我输入`cd D:\`的时候一直停留在C盘，无法切换。
## 解决方案
实际上是Cmd在切换驱动器的时候要先“激活”。
## 方法1
```shell
D:
cd D:\Project1
```
## 方法2
```shell
cd /d D;\Project1
```