# 【MySQL数据库】最全安装过程及配置详解

## 一.官网安装

### 1.官网地址

首先我们点击链接：MySQL官网
点进去只有会出现以下图片  

![](https://img-blog.csdnimg.cn/7ee7776c4ebe4daaa8434d1d0bacb4b7.png#pic_center "null")



我们往下滑，找到 中文  

![](https://img-blog.csdnimg.cn/06f715324443419ebf0925a1da01142c.png "null")



看在小日本后面有一个中文，我们点击他

---

### 2.下载

接下来我们点击GPL  

![](https://img-blog.csdnimg.cn/9c90aa31444445feb0288a08993779fb.png "null")



进入页面，点击for window  

![M](https://img-blog.csdnimg.cn/03c209bb7b6840d68e622f8bbd1908ec.jpeg "null")



点击Mdownload  

![iecne](https://img-blog.csdnimg.cn/6e0e80cdbf294a2ea12617fa31d9a6da.png "null")

439.6M，三分钟内就能下载完

---

## 二.安装教程

双击运行mysql-installer-community-8.30.0msi，安装好了之后，我们进入安装，刚开始的页面长这样

![](https://img-blog.csdnimg.cn/b12eeefa5d2e450b81349322f1aa360b.png "null")



- “Developer Default”是开发者默认  

- “Server only”仅作为服务器安装  

- “Client only”仅作为客户端安装  

- “Full”是完整安装  

- “Custom”是自定义安装

所以我们直接点击Custom，并且next 
出现了这个页面 
首先点击MySLQ Servers，再MySQL Server，最后再点击MySQL Server 8.0.30 - x64  

![](https://img-blog.csdnimg.cn/a30d0074b92a41cf818b30b1de1e24c2.png#pic_center "null")



再点击亮起来的绿色小箭头，就把这玩意放到了右边  

![](https://img-blog.csdnimg.cn/03cbe9c4381c4d7c8ef2e6dbe5f7f403.png#pic_center "null")



之后会跳出Advanced Options，点击他我们选择安装的路径 
若跳出Warning就直接Yes。**注：这里因为选择了我自己创建的路径，故程序提示路径已存在，是否要继续** 
接下来让他自己安装  

![](https://img-blog.csdnimg.cn/973920fc4a5b4fb8a2f99cec98fb0afa.png#pic_center "null")



等安装完了我们点击Execute  

![](https://img-blog.csdnimg.cn/a22d3c3861884ac6aae293ffea378bf0.png#pic_center "null")



- Development Computer 适合个人开发学习使用的  

- Server Computer 是像主要用于像FTP，email，web服务器等等  

- Dedicated Computer 只用作MySQL服务器

我们直接点击Development Computer 
选择完后不用动，Next  

![](https://img-blog.csdnimg.cn/baf888cf80f1448f8f775b13fcd96a08.png#pic_center "null")



这里我们输入密码，一定要记住，之后有用。 
上面输入，下面重复，懂得都懂。  

![](https://img-blog.csdnimg.cn/e08fc3fbb8034adb98c266d9a3235cc3.png#pic_center "null")



再次点击next  

![](https://img-blog.csdnimg.cn/f77033b83b824c30b01565a5c535a0fc.png "null")



点击finish，结束

---

## 三.测试

首先我们把整个文件夹整理下  

![](https://img-blog.csdnimg.cn/5684009c9d844203873887ec275adfcb.png "null")



找到bin文件夹，在他的上面查找cmd  

![](https://img-blog.csdnimg.cn/a49c8ddb2d474842a696ab0683d2ecfb.png "null")



在路径那里，搜索cmd  

![](https://img-blog.csdnimg.cn/0f3c6e2e5fa248a485bb7977fbc66db0.png "null")



这里输入 **mysql -u root -p**

![](https://img-blog.csdnimg.cn/b80e529c6b204542972c59f410ea0a8c.png "null")



输入自己的密码  

![](https://img-blog.csdnimg.cn/d195027203d64d889d600542bc01a30f.png "null")



若显示了这玩意就安装成功了

---

## 四.配置

首先我们获取MySQL的路径。打开设置，找到系统的环境变量，

![](https://img-blog.csdnimg.cn/809ad0742a104f2c91b0faa85ba9b334.png "null")



然后点击环境变量，选择path，新建，把bin的路径放入，确定。设置好后 
按win+r。搜索cmd 
打开系统的cmd之后，再次输入 mysql -u root -p 
输入密码，接着如果再次弹出这里就好了  

![](https://img-blog.csdnimg.cn/f86c5b23eac4495ebf8ea72095b6db01.png "null")



---

## 总结

本节课主要是讲解了MySQL的知识点，至此该课示例的思想博主已经真真切切彻彻底底分享完了，相信大家对这个逻辑有了一定的理解，大家可以自己动手敲敲代码，感受一下，包教包会。若有任何侵权和不妥之处，请私信于我，定积极配合处理，看到必回！！！
