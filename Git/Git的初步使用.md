## 📋 基础步骤
### 1. 克隆仓库
- 代码：`git clone https://github.com/nowasiki/Tic_Tac_Toe_C`
- 作用：将远程仓库克隆到本地
### 2. 创建新的分支
- 代码：`git checkout -b new-1`
- 作用：为了避免直接在 main 或 master 分支上进行开发，通常会创建一个新的分支
### 3. 进入工作目录
- 作用：在工作目录中进行代码编辑、添加新文件或删除不需要的文件。
### 4. 暂存文件
- 代码：`git add filename`（添加特定的）
- 代码：`git add .`（添加所有修改过的）
- 作用：将修改过的文件添加到暂存区，以便进行下一步的提交操作
### 5. 提交更改
- 代码：`git commit -m "Add a new file"`
- 作用：将暂存区的更改提交到本地仓库，并添加提交信息
### 6. 拉取最新更改
- 代码：`git pull origin main / git pull orgin new-1`（这是拉取到新的分支上）
- 作用：在推送本地更改之前，最好从远程仓库拉取最新的更改，以避免冲突
### 7. 推送更改
- 代码：`git push origin new-1`
- 作用：将本地的提交推送到远程仓库
### 8. 创建 Pull Request（PR）
- 作用：在 GitHub 或其他托管平台上创建 Pull Request，邀请团队成员进行代码审查。PR 合并后，你的更改就会合并到主分支。
### 9. 合并更改
- 代码：
```bash
git checkout main
git pull origin main
git merge new-1（基本不需要了）
```
- 作用：在 PR 审核通过并合并后，可以将远程仓库的主分支合并到本地分支
### 10. 删除分支
- 代码：`git branch -d new-feature`
- 作用：需要新功能分支，可以将其删除
- 代码：`git push origin --delete new-1`
- 作用：从远程仓库删除分支
## 🚀 完整开发周期
```bash
# 1. 克隆仓库（仅首次）
git clone <仓库URL>

# 2. 创建并切换到新分支
git checkout -b <分支名>

# 3. 开发工作（编辑文件...）

# 4. 暂存更改
git add .

# 5. 提交更改
git commit -m "描述性提交信息"

# 6. 推送分支到远程
git push origin <分支名>

# 7. 创建 Pull Request（在 GitHub/GitLab 上操作）

# 8. PR合并后，同步本地主分支
git checkout main
git pull origin main

# 9. 清理分支
git branch -d <分支名>              # 删除本地分支
git push origin --delete <分支名>   # 删除远程分支（可选）
```
## 🎯 核心精简流程（最常用）
```bash
# 开始新功能
git checkout -b feature-name
# ...开发...
git add .
git commit -m "feat: add new feature"
git push origin feature-name

# PR合并后
git checkout main
git pull origin main
git branch -d feature-name
```
## 🔄 日常更新流程
```bash
# 保持本地最新
git checkout master
git pull origin master

# 如果要基于最新代码开发
git checkout -b new-feature
```
## 💡 重要原则

1. **分支策略**：每个功能/修复都创建独立分支
2. **提交规范**：提交信息要清晰描述改动
3. **先拉后推**：推送前先拉取最新代码，减少冲突
4. **及时清理**：合并后删除已完成的分支，保持整洁
## 📊 流程图示意
```text
克隆仓库 → 创建分支 → 开发 → 提交 → 推送 → 创建PR → 审查合并
    ↓
同步主分支 ← 删除分支 ← PR通过
```
这个流程覆盖了从开始到结束的完整 Git 协作过程，适用于大多数开发场景。