## Cool

> Cool, an acronym for Classroom Object Oriented Language, is a computer programming language designed by Alexander Aiken for use in an undergraduate compiler course project.


### 环境搭建
参考 [Compilers](http://openclassroom.stanford.edu/MainFolder/DocumentPage.php?course=Compilers&doc=docs/pa.html)

```
sudo apt-get install g++ csh flex bison
```

如果使用Java:
```
sudo apt-get install openjdk-6-jdk
```

下载并解压（Linux）：
```
mkdir cool
cd cool
wget http://openclassroom.stanford.edu/MainFolder/courses/Compilers/docs/src/pa.linux.i686.tar.gz
tar zvxf pa.linux.i686.tar.gz
```


解压后， `bin`目录下包含了一些可执行文件，其中最常用的是 `coolc` 编译出MIPS指令集， 并由 `spim` 执行。