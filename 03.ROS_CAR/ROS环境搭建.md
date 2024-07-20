# ROS环境搭建

教程演示Ubuntu20.04搭建ROS1和ROS2环境。

## 设置语言环境

使用的环境需要支持UTF-8。

### 验证环境

```
locale
```

若不是UTF-8环境：

```
sudo apt update && sudo apt install locales
locale-gen en_US en_US.UTF-8
update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
echo "export LANG=en_US.UTF-8" >> ~/.bashrc
source ~/.bashrc
```

## ROS1

### 设置软件源

安装ROS软件包之前确保系统软件和环境是最新的。

```
sudo apt update
sudo apt upgrade
```

```
sudo apt install lsb-core
```

### 设置sources.list

```
sh -c '. /etc/lsb-release && echo "deb http://mirrors.tuna.tsinghua.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
```

### 设置密钥

```
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

### 安装ROS1

安装ROS软件包之前确保系统软件和环境是最新的。

更新apt软件包索引信息：

```
sudo apt update
```

更新软件包：

```
sudo apt upgrade
```

#### 安装Desktop版本

安装不同的版本选择不同的命令。

##### Melodic

```
sudo apt install ros-melodic-desktop-full
```

##### Noetic

```
sudo apt install ros-noetic-desktop-full
```

#### 安装依赖

安装不同的版本选择不同的命令。

##### Melodic

```
sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
```

##### Noetic

```
sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
```

#### 初始化rosdep

```
sudo rosdep init
```

```
sudo rosdep update
```

若`rosdep init`出现`ERROR: cannot download default sources list from: https://raw.githubusercontent.com/ros/rosdistro/master/rosdep/sources.list.d/20-default.list Website may be down.`错误提示，访问`https://www.ipaddress.com/`搜索`raw.githubusercontent.com`域名，并将搜索得到的IP地址填写进`/etc/hosts`文件：

```
sudo apt install nano
```

```
sudo nano /etc/hosts
```

添加内容：示例

```
185.199.110.133 raw.githubusercontent.com
```

#### 设置环境变量

安装不同的版本选择不同的命令。

##### Melodic

```
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
```

```
source ~/.bashrc
```

##### Noetic

```
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
```

```
source ~/.bashrc
```

使用上面这种方法不需要每次在终端运行`source`命令！

### 验证ROS1

#### 小海龟案例

打开三个终端，分别运行下面命令：

```
roscore
```

```
rosrun turtlesim turtlesim_node
```

```
rosrun turtlesim turtle_teleop_key
```

```
注意：鼠标必须停留在第三条命令窗口才能控制小乌龟
```

## ROS2

### 设置软件源

确保 Ubuntu Universe 存储库已启用

```
sudo apt-cache policy | grep universe
```

将 ROS 2 apt 存储库添加到系统：

```
sudo apt install software-properties-common
```

```
sudo add-apt-repository universe
```

### 设置密钥

使用 apt 添加 ROS 2 GPG 密钥：

```
sudo apt update && sudo apt install curl
```

```
curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

将存储库添加到系统的软件源列表中：

```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

若`sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg`解析失败，访问`https://www.ipaddress.com/`搜索`raw.githubusercontent.com`域名，并将搜索得到的IP地址填写进`/etc/hosts`文件：

```
sudo apt install nano
```

```
sudo nano /etc/hosts
```

添加内容：示例

```
185.199.110.133 raw.githubusercontent.com
```

### 安装ROS2

安装ROS软件包之前确保系统软件和环境是最新的。

更新apt软件包索引信息：

```
sudo apt update
```

更新软件包：

```
sudo apt upgrade
```

#### 安装Desktop版本

```
sudo apt install ros-<rosdistro>-desktop
# sudo apt install ros-foxy-desktop
```

#### 安装开发工具

```
sudo apt install ros-dev-tools
```

#### 设置环境变量

```
echo "source /opt/ros/<rosdistro>/setup.bash" >> ~/.bashrc
# echo "source /opt/ros/foxy/setup.bash" >> ~/.bashrc
```

```
source ~/.bashrc
```

使用上面这种方法不需要每次在终端运行`source /opt/ros/<rosdistro>/setup.bash`命令！

### 验证ROS2

#### 小海龟案例

打开两个终端，分别运行下面命令：

```
ros2 run demo_nodes_cpp talker
```

```
ros2 run demo_nodes_py listener
```

## ROS1/2 混合配置

按照教程安装ROS1和ROS2环境，将之前设置的ROS环境注释或者删除，在`~/.bashrc`文件底部添加下面内容：

```
# Set terminal environment
echo "Set up the terminal environment:"
echo "1. ROS Noetic"
echo "2. ROS2 Foxy"
echo "3. None"
read -p "Enter your choice (1, 2, or 3): " edition

if [ "$edition" -eq "1" ]; then
    if [ -f "/opt/ros/noetic/setup.bash" ]; then
        source /opt/ros/noetic/setup.bash
        echo "ROS Version: Noetic"
    else
        echo "Error: ROS Noetic is not installed."
        exit 1
    fi
elif [ "$edition" -eq "2" ]; then
    if [ -f "/opt/ros/foxy/setup.bash" ]; then
        source /opt/ros/foxy/setup.bash
        echo "ROS2 Version: Foxy"
    else
        echo "Error: ROS2 Foxy is not installed."
        exit 1
    fi
elif [ "$edition" -eq "3" ]; then
    echo "Exiting setup."
else
    echo "Invalid choice. Please enter 1, 2, or 3."
    exit 1
fi
```