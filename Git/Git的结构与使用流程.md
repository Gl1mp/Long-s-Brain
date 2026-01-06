## 工作区、暂存区和版本库
- **工作区**（Working Directory）：电脑里能看到的目录
- **暂存区**（Staging Area）：index或stage，目录为.git/index
- **版本库**（Repository）：工作区内有一个隐藏库.git，不属于工作区
### 1. 工作区
工作区是你在本地计算机上的项目目录，你在这里进行文件的创建、修改和删除操作。工作区包含了当前项目的所有文件和子目录。
#### 特点
- 显示项目的当前状态。
- 文件的修改在工作区中进行，但这些修改还没有被记录到版本控制中。
### 2. 暂存区
暂存区是一个临时存储区域，它包含了即将被提交到版本库中的文件快照。在提交之前，你可以选择性地将工作区中的修改添加到暂存区。
#### 特点：
- 暂存区保存了将被包括在下一个提交中的更改。
- 你可以多次使用 `git add` 命令来将文件添加到暂存区，直到你准备好提交所有更改。
#### 常用命令：
```bash
git add filename       # 将单个文件添加到暂存区
git add .              # 将工作区中的所有修改添加到暂存区
git status             # 查看哪些文件在暂存区中
```
### 3. 版本库
版本库包含项目的所有版本历史记录。每次提交都会在版本库中创建一个新的快照，这些快照是不可变的，确保了项目的完整历史记录。
#### 特点：
- 版本库分为本地版本库和远程版本库。这里主要指本地版本库。
- 本地版本库存储在 `.git` 目录中，它包含了所有提交的对象和引用。
#### 常用命令：
```bash
git commit -m "Commit message"   # 将暂存区的更改提交到本地版本库
git log                          # 查看提交历史
git diff                         # 查看工作区和暂存区之间的差异
git diff --cached                # 查看暂存区和最后一次提交之间的差异
```

### 4. 一次提交&拉取
1. 修改工作区中内容
2. 将修改添加到暂存区中`git add filename`
3. 将暂存区中的修改提交到版本库`git commit -m branch-name`
4. 将本地版本库的提交推送到远程仓库`git push origin branch-name`
5. 将远程仓库的内容更新到本地`git pull origin branch-name`
**注**：步骤5还可以通过fetch和merge结合的方式来实现
## 从0开始创建一个仓库
### 1. 初始化仓库
#### 通过现有的文件目录创建仓库
1. `cd <my-project>`进入目录。（[如果无法切换驱动器点这里](CMD中无法切换驱动器)）
2. `git init`会在当前目录生成一个隐藏的.git文件夹，也就是版本库
#### 新建目录来创建仓库
1. `mkdir <my-project>`来创建目录
2. `git init [<directory>]`可以指定目录来创建版本库
### 2. 添加要追踪的文件
1. `git add <filename>`把指定文件添加到暂存库
2. `git add *.c`将当前目录下所有c语言文件添加到暂存库
3. `git commit -m "<Commit Message>"`提交到本地版本库
### 3. GitHub上建立仓库
**可以去手动建立**
### 4. 推送更改
`git push origin branch-name`将本地修改推送到远程仓库的指定分支上
## 从远程克隆项目

`git clone <repo> <directory>
- repo：Github仓库
- directory：本地目录
e.g. `git clone https://github.com/nowasiki/Network-Monitor-Quant.git [<new-project-name>]`
- 不要使用git协议，已经被废弃
- 最好使用https或SSH
- 最后的参数为本地项目的名字
## 配置GIT
Git的参数配置用`git config`来完成。
### 修改git配置
#### 针对本地所有仓库
`git config -e --gloabal`
#### 针对本仓库
`git config -e`

### 设置提交代码时的用户信息
```bash
git config --global user.name "<yourname>"
git config --global user.email <your-email>
```
## 提交与修改
Git 的工作就是创建和保存你的项目的快照及与之后的快照进行对比。

| 命令                           | 说明                   |
| ---------------------------- | -------------------- |
| `git add`                    | 添加文件到暂存区             |
| `git status`                 | 查看仓库当前的状态，显示有变更的文件。  |
| `git diff`                   | 比较文件的不同，即暂存区和工作区的差异。 |
| `git difftool`               | 使用外部差异工具查看和比较文件的更改。  |
| `git range-diff`             | 比较两个提交范围之间的差异。       |
| `git commit`                 | 提交暂存区到本地仓库。          |
| `git reset`                  | 回退版本。                |
| `git rm`                     | 将文件从暂存区和工作区中删除。      |
| `git mv`                     | 移动或重命名工作区文件。         |
| `git notes`                  | 添加注释。                |
| `git checkout`               | 分支切换。                |
| `git switch（Git 2.23 版本引入）`  | 更清晰地切换分支。            |
| `git restore（Git 2.23 版本引入）` | 恢复或撤销文件的更改。          |
| `git show`                   | 显示 Git 对象的详细信息。      |
[更多参阅这里](https://www.runoob.com/git/git-basic-operations.html)
## 提交日志

| 命令                 | 说明                                  |
| ------------------ | ----------------------------------- |
| `git log`          | 查看历史提交记录                            |
| `git blame <file>` | 以列表形式查看指定文件的历史修改记录                  |
| `git shortlog`     | 生成简洁的提交日志摘要                         |
| `git describe`     | 生成一个可读的字符串，该字符串基于 Git 的标签系统来描述当前的提交 |
## 远程操作

| 命令              | 说明               |
| --------------- | ---------------- |
| `git remote`    | 远程仓库操作           |
| `git fetch`     | 从远程获取代码库         |
| `git pull`      | 下载远程代码并合并        |
| `git push`      | 上传远程代码并合并        |
| `git submodule` | 管理包含其他 Git 仓库的项目 |
## 文件状态的转换流程
- **未跟踪（Untracked）**： 新创建的文件最初是未跟踪的。它们存在于工作目录中，但没有被 Git 跟踪。
- **跟踪（Tracked）**： 通过 `git add` 命令将未跟踪的文件添加到暂存区后，文件变为已跟踪状态。
- **已修改（Modified）**： 对已跟踪的文件进行更改后，这些更改会显示为已修改状态，但这些更改还未添加到暂存区。
- **已暂存（Staged）**： 使用 `git add` 命令将修改过的文件添加到暂存区后，文件进入已暂存状态，等待提交。
- **已提交（Committed）**： 使用 `git commit` 命令将暂存区的更改提交到本地仓库后，这些更改被记录下来，文件状态返回为已跟踪状态。