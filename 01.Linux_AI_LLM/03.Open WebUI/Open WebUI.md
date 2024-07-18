# Open WebUI

教程演示在Ubuntu20.04安装Open WebUI。

## Reference

Open WebUI：https://github.com/open-webui/open-webui

## Open WebUI

Open WebUI是一个开源项目，旨在提供一个简单易用的用户界面（UI），用于管理和监控开源软件和服务。

### Docker install

#### Pull Open WebUI

拉取Open WebUI：

```
docker pull ghcr.io/open-webui/open-webui:main
```

#### Run Open WebUI

运行Open WebUI：

```
docker run --network=host -v open-webui:/app/backend/data -e OLLAMA_BASE_URL=http://127.0.0.1:11434 --name open-webui --restart always ghcr.io/open-webui/open-webui:main
```

#### Use Open WebUI

浏览器访问：

```
http://localhost:8080
```

首次使用需要先注册账号。

```
用户可以使用Ollama拉取大模型，拉取成功刷新网页，Open WebUI会自动更新模型列表
```

##### LLaVA

LLaVA: Large Language and Vision Assistant

```
what's in this image?
```

### Conda install

```
Anaconda安装可以看【附录：Anaconda】教程
```

Open WebUI环境要求：

- Node.js >= 20.10

- Python >= 3.11

#### Node.js

- Node.js官网下载

```
https://nodejs.org/zh-cn/download/prebuilt-binaries
```

- 解压/复制

自行解压并重命名下载的文件为nodejs，然后将文件复制到新建的文件夹下：

```
sudo mv nodejs /usr/local/lib
```

- 设置环境变量

编辑.bashrc文件

```
nano ~/.bashrc
```

并将下面内容添加进去.bashrc文件底部

```
export NODEJS_HOME=/usr/local/lib/nodejs
export PATH=$NODEJS_HOME/bin:$PATH
```

- 刷新环境变量

```
source ~/.bashrc
```

- 查看版本号

```
node -v
npm -v
```

若终端出现版本号，说明安装成功！

#### Build/Install Open WebUI

建议使用Conda安装Open WebUI，可以避免环境问题。

```
git clone https://github.com/open-webui/open-webui.git
cd open-webui/

# Copying required .env file
cp -RPp .env.example .env

# Building Frontend Using Node
npm i
npm run build

# Serving Frontend with the Backend
cd ./backend
pip install -r requirements.txt -U
bash start.sh
```

#### 常见报错

- Couldn't find ffmpeg or avconv - defaulting to ffmpeg, but may not work ···

```
sudo apt update
sudo apt install ffmpeg
```

- OSError: We couldn't connect to 'https://huggingface.co' to load this file ···

```
pip install -U huggingface_hub
```

```
sudo nano ~/.bashrc
```

将下面内容添加到文件底部：

```
HF_ENDPOINT=https://hf-mirror.com
```

#### Use Open WebUI

> **Conda环境使用**

```
conda activate LLM
bash open-webui/backend/start.sh
```

浏览器访问：

```
http://localhost:8080
```

首次使用需要先注册账号。

```
用户可以使用Ollama拉取大模型，拉取成功刷新网页，Open WebUI会自动更新模型列表
```

