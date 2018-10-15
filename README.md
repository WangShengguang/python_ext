# python_ext
Python C语言扩展

运行setup.py编译并链接代码
使用 `python setup.py build` 命令构建扩展， 
扩展模块会创建在build/lib.*目录下，可以切换到此目录下或者用以下方式安装

`python setup.py install`
```python
>>> import Extest
>>> Extest.test()
```
