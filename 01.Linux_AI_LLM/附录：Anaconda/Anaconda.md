# Anaconda

教程演示在Ubuntu20.04安装Anaconda。

## Reference

Anaconda：https://www.anaconda.com/

## Anaconda

Anaconda是一个开源的包管理和环境管理系统，主要用于管理不同版本的软件包和创建各种环境。

### Anaconda download 

```
# 官方网址
https://www.anaconda.com/download
# 清华镜像站
https://mirrors.tuna.tsinghua.edu.cn/anaconda/archive/
```

### Anaconda install

```
bash ~/Downloads/Anaconda3-<INSTALLER_VERSION>-Linux-x86_64.sh
```

安装根据终端提示操作，阅读协议声明可以按q跳过，最后接受协议声明即可！

### Anaconda init

安装Anaconda会提示是否初始化，推荐输入`yes`：系统会在每次打开终端初始化Anaconda的`base`环境。

如果不想每次终端打开就是`base`环境，可以使用下面命令控制`base`环境的默认设置

```
# The base environment is activated by default
conda config --set auto_activate_base True
# The base environment is not activated by default
conda config --set auto_activate_base False
```

### Anaconda info

查看Ananconda详细信息

```
conda info
```

### Anaconda mirrors

添加清华镜像源。

#### 生成配置文件

```
conda config --set show_channel_urls yes
```

#### 修改配置文件

配置文件会自动生成在用户目录下。

```
sudo nano .condarc
```

把原有的内容删除，添加下面内容到.condarc文件内：

```
channels:
  - defaults
show_channel_urls: true
default_channels:
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/r
  - https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/msys2
custom_channels:
  conda-forge: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  msys2: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  bioconda: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  menpo: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  pytorch: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  pytorch-lts: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  simpleitk: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud
  deepmodeling: https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/
```

#### 清除索引

使用修改后的镜像站。

```
conda clean -i
```

#### 查看信息

```
conda info
```

#### 删除镜像源

直接删除用户目录下的.condarc文件：

```
sudo rm .condarc
```

### Anaconda use

#### Conda activate

激活指定Conda环境：不添加环境名称默认激活`base`环境。

```
格式：conda activate [env_name_or_prefix]
示例：conda activate base
```

#### Conda deactivate

退出当前Conda环境：

```
conda deactivate
```

#### Conda create

创建新的Conda环境：

```
格式：conda create [env_name]
示例：conda create -n LLM python=3.11
```

#### Conda env list

查看Conda已安装环境：

```
conda env list
```

#### Conda remove

移除Conda指定环境：

```
格式：conda remove -n [env_name] --all
示例：conda remove -n LLM --all
```

