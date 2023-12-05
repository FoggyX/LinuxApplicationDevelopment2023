## 11_Documenting

### Build
```console
$ autoreconf -fisv && ./configure --prefix /tmp/guesser && make && make install
```

### Usage
With RU language:
```console
$ LANGUAGE=ru_RU.UTF-8:ru /tmp/guesser/bin/guesser [-r] [--help]
```
With EN language:
```console
$ LANGUAGE=en_US.UTF-8:en /tmp/guesser/bin/guesser [-r] [--help]
```

### Man
```console
man guesser.1
```
### Docs
```console
make http
```