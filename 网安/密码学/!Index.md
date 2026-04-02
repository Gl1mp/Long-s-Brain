## 前后端传输
前后端传输需要：[[网站前后端加密传输原理]]，其中我们的密码：[[哈希密码校验：Ciphertext中的一部分]]就藏在密文中，等传到后端后进行校验。
## 本地校验
[[本地加密认证：Password+Salt+AES]]
## RSA+AES/CTR & Password+Salt+AES
- 不想让服务器看见 → 用`Password+Salt+AES`
- 想让服务器认出你 → 用`登录哈希/RSA+AES`