# arm neon experiment

## link

* [qemuでneonをつかってみる](https://qiita.com/ar90n@github/items/347790d26a90f6de637b)
* [いまさら聞けない ARM を使ったNEONの基礎と活用事例（2021/08/05）](https://www.docswell.com/s/fixstars/KENEQJ-20210805)
* arm
  * [Arm Neon Intrinsics Reference](https://arm-software.github.io/acle/neon_intrinsics/)
  * [Arm Neon Intrinsics Reference(Table of Contents)](https://arm-software.github.io/acle/neon_intrinsics/advsimd.html)
  * [Arm Neon Intrinsics Reference for ACLE Q2 2021](https://developer.arm.com/documentation/ihi0073/latest/)
  * [GitHub Arm C Language Extensions (ACLE)](https://github.com/ARM-software/acle)
  * [GitHub Release Arm C Language Extensions (ACLE)](https://github.com/ARM-software/acle/releases)
* gcc
  * [6.62 Built-in Functions Specific to Particular Target Machines](https://gcc.gnu.org/onlinedocs/gcc/Target-Builtins.html)
  * [6.59.7 ARM C Language Extensions (ACLE)](https://gcc.gnu.org/onlinedocs/gcc-8.5.0/gcc/ARM-C-Language-Extensions-_0028ACLE_0029.html)
  * [6.54.3 ARM NEON Intrinsics](https://gcc.gnu.org/onlinedocs/gcc-4.6.4/gcc/ARM-NEON-Intrinsics.html)
  * [Re: ARM NEON Intrinsics guide?](https://gcc.gnu.org/legacy-ml/gcc-help/2016-05/msg00057.html)

## initial setup

```
sudo apt install -y gcc-12-arm-linux-gnueabi
sudo apt install -y qemu-user
```


## build

```
make
```

## run


```
make run_neon_test1
```


```
make neon_test_select
```
