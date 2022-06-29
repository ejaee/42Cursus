# Libft

> 42에서 필요한 라이브러리를 직접 구현하는 프로젝트입니다.

[라이브러리 만들기]()

man에 기반하여 각 함수들이 어떤 역할을 하는지 정리하였습니다.

## Contents

- [Libft](#libft)
  - [Contents](#contents)
  - [Part 1 - Libc functions](#part-1---libc-functions)
    - [ft_strlen](#ft_strlen)
    - [ft_strchr](#ft_strchr)
    - [ft_strrchr](#ft_strrchr)
    - [ft_](#ft_)
  - [Question](#question)

## Part 1 - Libc functions

### ft_strlen
> 

**PROTOTYPE**
```c
size_t  ft_strlen(const char *s)
```

**DESCRIPTION**  
문자열 `s`의 길이를 구한다.

**RETURN VALUE**  
문자열 `s`의 길이

**ISSUES**  
`size_t`형을 반환하므로 count value도 동일한 자료형으로 선언한다.
-   [size_t형에 대하여]()

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strchr
> string  character

**PROTOTYPE**
```c
char    *ft_strchr(const char *s, int c);
```

**DESCRIPTION**  
문자열 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다. c가 '\0'일 경우 종료 Null 문자를 찾는다.

**RETURN VALUE**  
문자 `c`가 처음 발견된 곳의 포인터. 문자열 `s`에 문자 `c`가 없으면 Null 포인터

**ISSUES**  
문자열을 다루는 함수인데 왜 int형 매개변수로 받나?

- [문자를 다루는 함수의 매개변수가 int형인 이유](#문자를-다루는-함수의-매개변수가-int형인-이유)

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strrchr
> string rear character

**PROTOTYPE**
```c
char    *ft_strrchr(const char *s, int c);
```

**DESCRIPTION**  
문자열 `s`에 문자 `c`가 마지막으로 발견된 곳의 포인터를 반환한다. c가 '\0'일 경우 종료 Null 문자를 찾는다.

**RETURN VALUE**  
문자 `c`가 마지막으로 발견된 곳의 포인터. 문자열 `s`에 문자 `c`가 없으면 Null 포인터

**ISSUES**  

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_
> 

**PROTOTYPE**
```c

```

**DESCRIPTION**  


**RETURN VALUE**  


**ISSUES**  

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

## Question


-   size_t형

size_t형은 부호 없는 정수형(`unsigned integer`)으로, `sizeof`, `offsetof`의 반환값이다. 일반적으로, 문자열이나 메모리의 사이즈를 나타낼 때 사용합니다.

```.c
typedef unsigned int size_t;
```

size_t는 `32비트` 운영체제에서는 `부호없는 32비트 정수`, `64비트`에서는 `부호없는 64비트 정수`입니다. 그러나 unsigned int 또는 intsms 64비트 운영체제라고 꼭 64비트 정수가 아닌, 여전히 32비트일 수 있습니다. 이것이 `size_t형과 unsigned int형의 차이`입니다.

size_t가 아닌, unsigned int형에 캐스팅 없이, 문자열 길이를 대입하면 다음과 같은 경고가 발생합니다.

```.c
warning C4267: 'initializing' : conversion from 'size_t' to 'unsigned int', possible loss of data
```

---

- 라이브러리 코드의 읽히는 부분이 const인 이유

메모리 관리의 최소 단위는 1byte입니다. 

포인터는 다소 많은 자원이 필요하므로, 단순 읽기 상황에서는 상수화해서 사용할 때 연산 속도와 자원 효율성에 도움을 줍니다.

---

- 문자를 다루는 함수의 매개변수가 int형인 이유

상당 수의 코드에서 int로 인자를 받아 1byte씩 읽는 경우가 많은데, 내가 찾은 이유들을 열거하자면, 먼저 char형이 없었던 적에 사용됐던 코드라는 이유가 있습니다.(실제로 char형으로 라이브러리를 지원할 경우 올드 코드들은 동작이 멈추거나 의도와는 다른 행동을 합니다) char형이 만들어진 후에도 올드 코드를 모두 수정하는데에 많은 비용을 발생하기 때문에 기존의 함수들을 굳이 수정하지 않는다고 합니다.

메모리 엑세스 단위가 int형으로, 실제로 사용자가 char형을 사용한다 해도 int로 메모리를 받습니다.(char형이 int형 안에 속해 있습니다.)

---
