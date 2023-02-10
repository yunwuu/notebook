## Hello World


要在终端打印出 `Hello World`， 需要一个 `IO` 对象。 在这里，我们用 `new` 来创建它。

注意： `Cool`语言的赋值操作符是 `<-` 而非 `=`。

```
i: IO <- new IO;
```

然后调用 `i.out_string()`：
```
class Main {
    i: IO <- new IO;
    main() : IO { i.out_string("Hello world!\n") };
};
```