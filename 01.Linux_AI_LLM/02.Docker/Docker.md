# Docker

教程演示在Ubuntu20.04安装Docker。

## Docker

Docker是一种容器化平台，可以帮助开发者打包应用程序及其依赖项，使其能够在任何环境中快速部署和运行。

### Docker install

#### Bash install

国内用户可能通过官方脚本无法安装Docker，可以使用手动安装Docker。

```
sudo apt update
sudo apt upgrade
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
```

#### Manual install

使用清华软件源安装Docker

```
sudo apt update
sudo apt install ca-certificates curl gnupg lsb-release
```

```
curl -fsSL https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
```

```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

```
sudo apt update
sudo apt install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```

### Docker check

检查Docker版本。

```
docker --version
```

### Docker permissions

添加系统当前用户对Docker守护程序的访问权限：不需要使用sudo命令就可以使用Docker命令。

```
sudo usermod -aG docker $USER
newgrp docker
```

### Docker mirrors

添加国内镜像源，拉取Docker镜像更快！

```
sudo nano /etc/docker/daemon.json
```

文件内添加下面内容：

```
{
    "registry-mirrors": [
        "https://dockerproxy.com",
        "https://docker.m.daocloud.io",
        "https://cr.console.aliyun.com",
        "https://ccr.ccs.tencentyun.com",
        "https://hub-mirror.c.163.com",
        "https://mirror.baidubce.com",
        "https://docker.nju.edu.cn",
        "https://docker.mirrors.sjtug.sjtu.edu.cn",
        "https://github.com/ustclug/mirrorrequest",
        "https://registry.docker-cn.com"
    ]
}
```

```
sudo systemctl daemon-reload
sudo systemctl restart docker
sudo docker info
```

### Docker use

#### Docker pull

拉取容器到本地：

```
格式：docker pull NAME[:TAG]
示例：docker pull hello-world
```

#### Docker images

列出所有本地容器:

```
docker images
```

#### Docker run

启动容器（本地没有该容器则自动拉取容器）：

```
格式：docker run NAME[:TAG]
示例：docker run hello-world
```

#### Docker ps

列出正在运行的容器：

```
docker ps
```

列出正在运行和停止的容器：

```
docker ps -a
```

#### Docker stop

停止运行的容器：

```
格式：docker stop NAME[:TAG]
示例：docker stop hello-world
```

#### Docker container prune

清理所有停止运行的容器：

```
docker container prune
```

#### Docker rmi

删除镜像：若无法删除，先清理所有停止运行的容器再删除或者增加-f参数强制删除

```
格式：docker rmi NAME[:TAG]
示例：docker rmi hello-world
强制删除：docker rmi -f hello-world
```
