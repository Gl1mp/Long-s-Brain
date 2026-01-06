我明明已经开了Clash但是依旧连接错误，产生以下问题：
```shell
fatal: unable to access 'https://github.com/cold-bin/cold-bin.github.io.git/': OpenSSL SSL_read: Connection was reset, errno 10054
fatal: unable to access 'https://github.com/cold-bin/cold-bin.github.io.git/': Failed to connect to github.com port 443 after 21109 ms: Timed out

```
这是因为没有走VPN的系统代理，只要给Git设置VPN代理的端口就行了。
```shell
git config --global http.proxy http://127.0.0.1:7890 
git config --global https.proxy http://127.0.0.1:7890
# 我的clash在7890上系统代理
```
![[Pasted image 20260106104223.png]]
这里能看到我的Clash端口。