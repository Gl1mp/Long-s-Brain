#工具 #git 
## 1. 生成 SSH 密钥（一次性）

| 操作              | 命令                                                            | 说明            |
| --------------- | ------------------------------------------------------------- | ------------- |
| 生成推荐密钥（Ed25519） | `ssh-keygen -t ed25519 -C "你的邮箱@example.com"`                 | 现代默认推荐，安全且高效  |
| 生成传统密钥（RSA）     | `ssh-keygen -t rsa -b 4096 -C "你的邮箱@example.com"`             | 旧系统或特殊需求时使用   |
| 指定文件名生成         | `ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519_github -C "你的邮箱"` | 不同平台用不同密钥（推荐） |

**操作提示**：
- 按回车接受默认路径（`~/.ssh/id_ed25519`）
- **强烈建议设置强 passphrase**（密码短语），保护私钥
- 生成后会显示随机艺术图案（randomart），可用于视觉区分

## 2. 启动 SSH Agent 并添加密钥

| 操作 | 命令 | 说明 |
|------|------|------|
| 启动 SSH Agent | `eval "$(ssh-agent -s)"` | macOS / Linux 常用<br>Windows 可直接用 `ssh-agent` |
| 添加私钥到 Agent | `ssh-add ~/.ssh/id_ed25519`<br>`ssh-add ~/.ssh/id_ed25519_github` | 添加后无需每次输入 passphrase |
| 查看已添加的密钥 | `ssh-add -l` | 确认密钥是否加载 |

## 3. 查看并复制公钥

| 操作 | 命令 | 说明 |
|------|------|------|
| 查看公钥内容 | `cat ~/.ssh/id_ed25519.pub` | 复制全部内容 |
| 复制到剪贴板（macOS） | `cat ~/.ssh/id_ed25519.pub \| pbcopy` | 快速复制 |
| 复制到剪贴板（Linux） | `cat ~/.ssh/id_ed25519.pub \| xclip -selection clipboard` | 需要安装 xclip |

**下一步**：把公钥粘贴到 Git 平台（GitHub / GitLab / Gitee / 自建服务器）的 **SSH Keys** 设置中。

## 4. 测试 SSH 连接

| 操作 | 命令 | 预期结果 |
|------|------|----------|
| 测试 GitHub | `ssh -T git@github.com` | Hi username! You've successfully authenticated... |
| 测试 GitLab | `ssh -T git@gitlab.com` | Welcome to GitLab, @username! |
| 测试自建服务器 | `ssh -T git@your-server.com` | 类似欢迎信息 |

如果看到 "Permission denied"，检查密钥是否正确添加或平台设置。

## 5. 使用 SSH 的 Git 命令

| 操作          | 命令                                                                                           | 说明                    |
| ----------- | -------------------------------------------------------------------------------------------- | --------------------- |
| SSH 方式克隆    | `git clone git@github.com:username/repo.git`<br>`git clone git@gitlab.com:username/repo.git` | 直接使用 SSH URL          |
| 添加远程仓库（SSH） | `git remote add origin git@github.com:username/repo.git`                                     | 添加 SSH 远程             |
| 修改现有远程为 SSH | `git remote set-url origin git@github.com:username/repo.git`                                 | 把 HTTPS 改为 SSH        |
| 查看远程地址      | `git remote -v`                                                                              | 确认当前使用的是 SSH 还是 HTTPS |
| 推送 / 拉取     | `git push origin main`<br>`git pull origin main`                                             | SSH 下通常无需输入用户名和密码     |

**常见 SSH URL 格式**：
- GitHub：`git@github.com:用户名/仓库名.git`
- GitLab：`git@gitlab.com:用户名/仓库名.git`
- 自建 Git 服务器：`git@你的服务器IP或域名:仓库路径.git`

## 6. SSH 配置文件（~/.ssh/config）—— 管理多个平台推荐

当你有多个 Git 账号或多个服务器时，创建或编辑 `~/.ssh/config` 文件：

```bash
# 示例配置
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_github
    IdentitiesOnly yes

Host gitlab.com
    HostName gitlab.com
    User git
    IdentityFile ~/.ssh/id_ed25519_gitlab
    IdentitiesOnly yes

Host myserver
    HostName your-server.com
    User git
    Port 22
    IdentityFile ~/.ssh/id_ed25519_work
    IdentitiesOnly yes