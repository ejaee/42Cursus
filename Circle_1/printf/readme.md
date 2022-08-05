# **printf**

_요약: stdio.h의 printf 함수를 구현하는 프로젝트 입니다._

# **Contents**

- [**printf**](#printf)
- [**Contents**](#contents)
- [**Introduction**](#introduction)
- [**Logic**](#logic)
- [**Key Word**](#key-word)
	- [read()](#read)
	- [FD](#fd)
	- [Static 변수](#static-변수)
	- [Dangling Pointer](#dangling-pointer)
	- [gcc -D flag](#gcc--d-flag)
	- [Redirection](#redirection)

# **Introduction**

# **Key Word**

##  variadic arguments
_가변 인자_

**PROTOTYPE**

```c
void	func(int num_args, ...);
```
최소 1개 이상의 고정 인수가 있어야 합니다.

`...`은 파라미터 순서 상 가장 마지막에 위치해 있어야 합니다.

```.c
#include <stdio.h>
#include <stdarg.h>

int	sum(int num_args, ...);

int	main()
{
	int	a = 1, b = 2, c = 3, d = 4, e = 5;
	printf("%d\n", sum(5, a, b, c, d, e));
}

int sum(int num_args, ...)
{
	va_list	ap;

	va_start(ap, num_args);
	int arg = 0, result = 0;
	for (int i = 0; i < num_args; i++)
	{
		arg = va_arg(ap, int);
		result += arg;
	}
	va_end(ap);
	return (result);
}
```

-	**va_list ap**

	길이가 변할 수 있는 인수들을 저장하려면 가변의 저장공간이 필요합니다.

	va_list 타입이 이 가변 공간이 됩니다.

	vs_list는 가변 인수들에 대한 정보를 홀드 하기 위한 타입으로,

	가변인수들을 저장하는 스택 주소 포인터 입니다.

-	**va_start(ap, num_args)**

	va_list 인스턴스(ap)가 맨 첫 번째 가변인수를 가리킬 수 있도록 va_list를 초기화 합니다.

	첫 번째 가변인자 주소를 알려면 두 번째 인자인 고정인수가 필요합니다.

	```.vim
	#define va_start(ap, v) ( (ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
	```
	_va _list 주소값에다가 고정 인수 크기를 더한 위치로 ap로 초기화 합니다._

	![Alt text](./pictures/monitoring.png)

	ap는 가변인수 함수에 들어오는 고정인수 다음에 위치해야하기 때문입니다.



-	**va_arg(ap, int)**

	반복문을 돌리면서 인자 값 한 개 한 개씩 뽑습니다.



**DESCRIPTION**

메모리 s1과 s2를 n byte까지 비교합니다.

**RETURN VALUE**

strcmp와 동일합니다.

**ISSUES**

<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

