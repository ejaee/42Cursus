# **Born2beRoot**

_요약: VirtualBox를 이용해 운영체제를 설치해보는 프로젝트 입니다._




# **Contents**

- [**Born2beRoot**](#born2beroot)
- [**Contents**](#contents)
- [**Key Word**](#key-word)
	- [Virtual box](#virtual-box)
	- [Debian](#debian)

# **Key Word**

## **Virtual box**

_가상머신(VM)_

운영체제를 여러개 돌릴 수 있게하는 것으로, 물리적 컴퓨터의 디지털 버전입니다.

```.vim
host : 물리적 컴퓨터
guest : VM으로 만든 컴퓨터
```

어떠한 운영체제라도 설치할 수 있게 하는 소프트웨어를 말합니다.

기존의 하드웨어 위에 OS가 위치하는 것이 아닌,

일반적으로 하드웨어 위에 vmm을 올리고 그위에 여러개의 OS가 올라간 형태를 가집니다.

호스트 하드웨어에 영향을 주지 않으며 게스트 환경의 것을 게스트 밖으로 내보낼 수 없습니다.

새로운 애플리케이션 테스트나, 악성 코드 분석 등의 목적으로 사용이 가능합니다.

_하이퍼바이저_

하이퍼바이저는 가상머신을 생성하고 구동하는 소프트웨어입니다.

가상머신 모니터(VMM)라고도 불리며 하이퍼바이저 운영체제와 가상머신의 리소스를 분리해 VM의 생성과 관리를 지원합니다.

-   하이퍼바이저의 유형

		하이퍼바이저는 타입 1과 타입 2로 나뉩니다.

		`타입 1`의 경우 네이티브(Native) 혹은 베어메탈(Bare Metal) 하이퍼바이저라고도 불리며,

		하드웨어와 직접 상호작용 합니다.

		KVM/QEMU, XEN 등이 타입 1 하이퍼바이저에 속합니다.

		반면 `타입 2`는 호스트 운영체제 위에서 하이퍼바이저가 동작합니다.

		따라서 타입 2를 호스티드(Hosted) 하이퍼바이저라고 부르기도 합니다.

		VMware Fusion, VMware Workstation, Parallels Workstation, VirtualBox 등이 있습니다.

		해당 과제에서는 `타입 2`의 `VirtualBox`를 활용합니다.

		[버추얼 박스 설치 공식 링크](https://www.virtualbox.org/wiki/Downloads)


<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

## **Debian**

_무료 오픈 소스 소프트웨어로 만든 운영체제입니다_

온라인 커뮤니티에서 제작된 컴퓨터 운영체제입니다.

사용법이 온라인 웹사이트나 커뮤니티에 자세히 기술되어 있다는 점이 진입장벽을 낮추어 초보 리눅스유저들이 접근하기 쉬운 OS입니다.

* Linux

	```.vim
리눅스(Linux)는 리누스 토르발스가 커뮤니티 주체로 개발한 컴퓨터 운영 체제입니다.

리눅스(Linux)는 UNIX운영체제를 기반으로 만들어진 운영체제 입니다.

두가지 계열의 리눅스가 있는데,바로 레드햇계열과 데비안계열입니다.

대표적인 버전으로 레드햇의 센토스OS 데비안의 우분투OS가 있습니다.
	```

* cf) centOS

_Community Enterprise Operating System_

센트OS(영어: CentOS)는 센트OS 프로젝트에서 레드햇 제휴로 개발한 컴퓨터 운영체제입니다

서버용으로 리눗그를 운영할 목적으로 대부분 쓰이고 있습니다.


## **APT and aptitude**

_패키지관리 프로그램의 한 유형입니다_

* 패키지?

	커널 및 라이브러리 버전의 배포판 환경에 맞추어 빌드한 실행파일을 압축한 것입니다.

	데비안 패키지 방식은 메인테이너들에 의해서 패키지가 관리되고 있어서 패키지를 네트워크를 통해 다운받을 때 의존성 패키지가 있는지를 검사하고 의존성 패키지가 자신의 환경에 설치되어 있지 않다면 자동으로 의존성 패키지까지 같이 설치할 수 있도록 지원하고 있습니다

* apt

	_Advanced Packaging Tool_

	데비안 GNU/리눅스 배포판 계열 배포판에서 소프트웨어를 설치하고 제거하는 일을 합니다.

	APT는 이진 파일로부터나 소스 코드 컴파일을 통하여 소프트웨어 패키지의 확인·구성·설치를 자동화함으로써 유닉스 계열 컴퓨터 시스템 상의 소프트웨어를 관리하는 작업을 단순하게 만든다.

* aptitude

	APT의 프론트엔드 프로그램입니다.

	앱티튜드는 소프트웨어 패키지의 목록을 보여주고, 사용자가 패키지를 능동적으로 설치 혹은 삭제하도록 허용한다.

	특히 유연한 검색 패턴을 지원하는 검색 기능을 가지고 있습니다.

	```.vim
	위 둘의 가장 큰 차이는 프론트엔드 지원 유/무 입니다.
	```

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
