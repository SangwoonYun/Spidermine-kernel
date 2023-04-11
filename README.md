![GitHub last commit](https://img.shields.io/github/last-commit/SangwoonYun/Spidermine-kernel)
![GitHub contributors](https://img.shields.io/github/contributors/SangwoonYun/Spidermine-kernel)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/SangwoonYun/Spidermine-kernel)

# Spidermine Kernel

### Project Reference
> [J. Won<sup>§</sup>, J. Ahn<sup>§</sup>, S. Yun, J. Kim, and K. Kang<sup>*</sup>, "Spidermine: Low Overhead User-Level Prefetching," in *Proc. 38th ACM/SIGAPP Symp. on Applied Computing (SAC)*, 2023.](https://ieeexplore.ieee.org/abstract/document/8123045 "Go IEEExplore")

### Kernel Build

#### Preparing to Build
> Update the system and the available packages to the latest versions
> ```bash
> sudo apt update
> sudo apt upgrade -y
> ```
> 
> Check the current Linux Kernel
> ```bash
> uname -r
> ```
> 
> Install the required packages and build tools
> ```bash
> sudo apt install build-essential dwarves python3 libncurses-dev flex bison libssl-dev bc libelf-dev zstd gnupg2 wget git -y
> ```

#### Download Linux Kernel
> The linux Kernel can be gotten from the [kernel.org](https://kernel.org/ "kernel.org")
> I use the `Linux kernel 6.2.10`
> 
> Download
> ```bash
> wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.2.10.tar.xz
> ```
> 
> Extract
> ```bash
> tar xvf linux-6.2.10.tar.xz
> cd linux-6.2.10/
> ```

#### Configuration
> Copy config file to our project
> ```bash
> cp -v /boot/config-$(uname -r) .config
> make menuconfig
> ```
> And then `Save` and `Exit`
> 
> Modify the created config by disabling SYSTEM_REVOCATION_KEYS
> ```bash
> scripts/config --disable SYSTEM_REVOCATION_KEYS
> make localmodconfig
> ```

#### Compile
> Compile the Linux Kernel
> ```bash
> make bzImage -j$(nproc)
> ```
> It's gonna take a long time
> 
> Compile the Linux Kernel modules
> ```bash
> make modules -j$(nproc)
> ```

#### Optional Step
> Enable Kernel Selection
> ```bash
> sudo vi /etc/default/grub
> ```
> Make the below line to comment
> ```
> GRUB_TIMEOUT_STYLE=hidden
> GRUB_TIMEOUT=0
> ```
> Update grub
> ```bash
> sudo update-grub
> ```

#### Install
> Install kernel modules
> ```bash
> sudo make modules_install -j$(nproc)
> ```
> 
> Install kernel
> ```bash
> sudo make install -j$(nproc)
> ```
>
> And then reboot
> ```bash
> sudo reboot -i
> ```

