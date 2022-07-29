# **Born2beRoot**

_요약: VirtualBox를 이용해 운영체제를 설치해보는 프로젝트 입니다._




# **Contents**

- [**Born2beRoot**](#born2beroot)
- [**Contents**](#contents)
- [**Key Word**](#key-word)
  - [Virtual box](#virtual-box)
  - [Debian](#debian)

# **Key Word**

## Virtual box

_가상머신(VM)_

운영체제를 여러개 돌릴 수 있게하는 것으로 물리적 컴퓨터의 디지털 버전입니다. 

```.vim
host : 물리적 컴퓨터
guest : VM으로 만든 컴퓨터
```

어떠한 운영체제라도 설치할 수 있게 하는 소프트웨어를 말합니다.

기존의 하드웨어 위에 OS가 위치하는 것이 아닌,

하드웨어 위에 vmm을 올리고 그위에 여러개의 OS가 올라간 형태를 가집니다.

호스트 하드웨어에 영향을 주지 않으며 게스트 환경의 것을 게스트 밖으로 내보낼 수 없습니다.

새로운 애플리케이션 테스트나, 악성 코드 분석 등의 목적으로 사용이 가능합니다.

_하이퍼바이저_

하이퍼바이저는 가상머신을 생성하고 구동하는 소프트웨어입니다.

가상머신 모니터(VMM)라고도 불리며 하이퍼바이저 운영체제와 가상머신의 리소스를 분리해 VM의 생성과 관리를 지원합니다.

-   하이퍼바이저의 유형

    하이퍼바이저는 타입 1과 타입 2로 나뉩니다.

    타입 1의 경우 네이티브(Native) 혹은 베어메탈(Bare Metal) 하이퍼바이저라고도 불리며,

    하드웨어와 직접 상호작용 합니다.

    KVM/QEMU, XEN 등이 타입 1 하이퍼바이저에 속합니다.

    반면 타입 2는 호스트 운영체제 위에서 하이퍼바이저가 동작합니다.
    
    따라서 타입 2를 호스티드(Hosted) 하이퍼바이저라고 부르기도 합니다.
    
    VMware Fusion, VMware Workstation, Parallels Workstation, VirtualBox 등이 있습니다. 
    
    해당 과제에서는 버추얼박스를 요구하고 있습니다.

    [버추얼 박스 설치 공식 링크](https://www.virtualbox.org/wiki/Downloads)




<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

## Debian

_무료 오픈 소스 소프트웨어로 만든 운영체제 입니다_

## Debian-installer

## partition


## encrypted

## volume 세분화

## mount point

## ? apt vs aptitude

## install sudo
## install vim

## appArmor
## setting UFW

## setting SSH

## port forwarding

## Hostname

## passwd

## USER GROUP

## Shell Script

## Lighttpd

## PHP

## MariaDB

## WorldPress ... DB

## WorldPress

## WorㅣdPress ... MariaDB

## Signature