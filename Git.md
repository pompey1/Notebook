# Git和GitHub
从2021年8月13日开始github不再支持密码的方式认证
1. 修改.git/config 文件提交通过ssh的方式而不是http
```
将remote标题下url的前缀改为ssh://git@github.com/
```
2. 官方推荐方法：执行以下命令生成密钥
```
$ ssh-keygen -t rsa -C "这里换上你的邮箱"
```
> 教程：[https://zhuanlan.zhihu.com/p/589003121](https://zhuanlan.zhihu.com/p/589003121)