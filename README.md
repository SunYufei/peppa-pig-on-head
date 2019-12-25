# Peppa Piggy

2019 OUC "数与你的小猪佩奇" 参赛作品 编程组 第一名

## 简介

使用摄像头拍摄视频，检测到人脸后在人脸周围出现小猪佩奇，佩奇跟随头部运动而运动。例如：

![](docs/example.jpg)

## 运行

如果你的电脑有摄像头，可以运行演示程序进行体验。演示效果与摄像头的成像效果、光照等因素有关，清晰的摄像头效果相对好一些。

### C++ 版本

详见`C++Version`文件夹中的内容，需要运行请安装配置OpenCV。

### Python 版本

本项目可运行的Python版本为3.6

安装依赖包

```bash
pip install opencv-python dlib==19.8.1
```

运行

```bash
python peggy.py
```

## 致谢

[OpenCV](https://github.com/opencv/opencv)


## 开源协议

[MIT License](LICENSE)
