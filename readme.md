# arm neon experiment

## link

* [qemuでneonをつかってみる](https://qiita.com/ar90n@github/items/347790d26a90f6de637b)
* [いまさら聞けない ARM を使ったNEONの基礎と活用事例（2021/08/05）](https://www.docswell.com/s/fixstars/KENEQJ-20210805)
* [Arm Neon Intrinsics Reference](https://arm-software.github.io/acle/neon_intrinsics/)
  * [Arm Neon Intrinsics Reference(Table of Contents)](https://arm-software.github.io/acle/neon_intrinsics/advsimd.html)
  * [GitHub Arm C Language Extensions (ACLE)](https://github.com/ARM-software/acle)

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
