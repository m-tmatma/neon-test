# arm neon experiment

## link

* https://qiita.com/ar90n@github/items/347790d26a90f6de637b

## initial setup

```
sudo apt install -y gcc-12-arm-linux-gnueabi
sudo apt install -y qemu-user
```


## build

```
arm-linux-gnueabi-gcc-12 -mfpu=neon -mfloat-abi=softfp -std=c99 neon_test1.c -o neon_test1
```

## run


```
qemu-arm  -L /usr/arm-linux-gnueabi neon_test1
```
