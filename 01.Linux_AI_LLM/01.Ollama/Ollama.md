# Ollama

教程演示在Ubuntu20.04安装Ollama。

## Reference

Ollama：https://ollama.com/

## Ollama

Ollama是一个开源的工具，旨在简化大型语言模型的部署和运行过程，使得用户可以在本地环境中使用高质量的语言模型。

### Ollama install

#### Linux install

```
curl -fsSL https://ollama.com/install.sh | sh
```

### Ollama use

LLaVA: Large Language and Vision Assistant

#### Pull Mode

```
ollama pull llava
```

#### Model list

```
ollama list
```

#### Run Model

```
ollama run llava
```

```
what's in this image? /home/w_ml/Pictures/panda.jpeg
```

#### Runing Model list

```
ollama ps
```

#### Remove Model

```
ollama rm llava
```
