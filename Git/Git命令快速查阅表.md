#git #cheatsheet #工具
## 1. 基础设置与初始化

| 操作     | 命令                                                                                | 说明                             |
| ------ | --------------------------------------------------------------------------------- | ------------------------------ |
| 初始化仓库  | `git init`                                                                        | 在当前目录创建新 Git 仓库                |
| 克隆远程仓库 | `git clone <url>`                                                                 | 克隆远程仓库到本地（推荐加 `--depth 1` 浅克隆） |
| 查看状态   | `git status`                                                                      | 显示工作区、暂存区状态（最常用！）              |
| 配置用户信息 | `git config --global user.name "你的名字"`<br>`git config --global user.email "你的邮箱"` | 全局配置提交者信息                      |
## 2. 文件操作与提交

| 操作 | 命令 | 说明 |
|------|------|------|
| 添加文件到暂存区 | `git add <file>`<br>`git add .` | 添加指定文件 / 所有修改 |
| 提交更改 | `git commit -m "提交信息"`<br>`git commit --amend` | 普通提交 / 修改上一次提交 |
| 查看已跟踪文件 | `git ls-files` | 列出 Git 跟踪的所有文件 |
| 查看差异 | `git diff`<br>`git diff --staged` | 查看工作区差异 / 暂存区差异 |
## 3. 查看历史

| 操作 | 命令 | 说明 |
|------|------|------|
| 查看提交历史 | `git log --oneline`<br>`git log --oneline --graph --all` | 简洁模式 / 带图形的所有分支 |
| 查看具体文件历史 | `git log --oneline -- <file>` | 只看某个文件的历史 |
## 4. 恢复与撤销（重点！）

| 操作 | 命令 | 说明 |
|------|------|------|
| 丢弃工作区修改（现代推荐） | `git restore <file>`<br>`git restore .` | 恢复文件到暂存区/HEAD 状态 |
| 取消暂存 | `git restore --staged <file>` | 把文件从暂存区移回工作区 |
| 撤销最后一次提交（保留修改） | `git revert HEAD` | 创建新提交来撤销（安全） |
| 软重置（保留修改） | `git reset --soft HEAD~1` | 撤销提交，但修改留在暂存区 |
| 硬重置（危险！） | `git reset --hard HEAD~n`<br>`git reset --hard <commit>` | 强制回退，**会丢失未提交修改** |
| 恢复已删除的提交 | `git reflog` | 查看所有操作记录，找到 commit 后用 `git reset` 或 `git cherry-pick` |
> **小贴士**：优先使用 `git restore`，少用老的 `git checkout` 做文件恢复。
## 5. 分支操作（现代写法推荐）

| 操作 | 命令 | 说明 |
|------|------|------|
| 查看分支 | `git branch -v`<br>`git branch -a` | 本地分支（带最后提交） / 所有分支（含远程） |
| 创建分支 | `git branch <name>` | 只创建不切换 |
| 创建并切换分支 | `git switch -c <name>`<br>`git checkout -b <name>` | **推荐使用 `git switch`** |
| 切换分支 | `git switch <branch>`<br>`git checkout <branch>` | 切换到已有分支 |
| 删除分支 | `git branch -d <name>`<br>`git branch -D <name>` | 安全删除 / 强制删除 |
## 6. 远程仓库操作（协作必备）

| 操作 | 命令 | 说明 |
|------|------|------|
| 添加远程仓库 | `git remote add origin <url>` | 添加远程地址 |
| 查看远程 | `git remote -v` | 显示所有远程仓库 |
| 拉取最新代码 | `git fetch origin`<br>`git pull origin <branch>` | 只下载 / 下载并合并 |
| 推送到远程 | `git push origin <branch>`<br>`git push -u origin <branch>` | 普通推送 / 首次推送并设置上游 |
| 推送所有分支 | `git push --all` | 推送所有本地分支 |
| 删除远程分支 | `git push origin --delete <branch>` | 删除远程分支 |
| 拉取并变基（推荐干净历史） | `git pull --rebase origin main` | 拉取后变基，避免多余合并提交 |
## 7. 合并与变基

| 操作 | 命令 | 说明 |
|------|------|------|
| 合并分支 | `git merge <branch>` | 把指定分支合并到当前分支 |
| 变基（推荐用于特性分支） | `git rebase <base-branch>` | 把当前分支“嫁接”到目标分支上，历史更线性 |
| 交互式变基（修改历史） | `git rebase -i HEAD~n` | 交互式编辑最近 n 次提交（squash、edit 等） |
## 8. 暂存（Stash） - 临时保存工作

| 操作 | 命令 | 说明 |
|------|------|------|
| 暂存当前修改 | `git stash`<br>`git stash -u` | 暂存（包含未跟踪文件） |
| 查看暂存列表 | `git stash list` | 显示所有 stash |
| 恢复最近一次暂存 | `git stash pop`<br>`git stash apply` | 恢复并删除 / 只恢复不删除 |
| 恢复指定 stash | `git stash pop stash@{1}` | 恢复第 2 个 stash |
## 9. 其他实用命令

| 操作 | 命令 | 说明 |
|------|------|------|
| 挑选特定提交 | `git cherry-pick <commit>` | 把某个 commit 应用到当前分支 |
| 打标签 | `git tag v1.0.0`<br>`git push origin --tags` | 创建标签 / 推送所有标签 |
| 删除未跟踪文件 | `git clean -fd` | 删除未跟踪的文件和目录（小心使用） |
| 查看 Git 配置 | `git config --list` | 显示所有配置 |
### 常用工作流快捷组合

- **新建功能分支**：`git switch -c feature/xxx`
- **常规提交流程**：`git add .` → `git commit -m "feat: xxx"` → `git push`
- **拉取最新主干并变基**：`git switch main` → `git pull --rebase` → `git switch feature/xxx` → `git rebase main`
- **临时切换分支**：`git stash` → `git switch other-branch` → 干活 → `git switch feature/xxx` → `git stash pop`
- **修复上一次提交**：`git commit --amend`
### 安全提醒
- 使用 `--hard`、`git reset`、`git clean` 前一定要 `git status` + `git stash` 或确认无重要未提交修改。
- 团队协作推荐使用 `rebase` 保持历史整洁，或严格的 merge 策略。
- 经常执行 `git fetch` 而不是只用 `git pull`。