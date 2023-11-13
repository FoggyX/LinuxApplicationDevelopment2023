## 08_I18n

### Build
```console
$ autoreconf -fisv && ./configure --prefix /tmp/guesser && make && make install
```

### Usage
With RU language:
```console
$ LANGUAGE=ru_RU.UTF-8:ru /tmp/guesser/bin/guesser
```
With EN language:
```console
$ LANGUAGE=en_US.UTF-8:en /tmp/guesser/bin/guesser
```