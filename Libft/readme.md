# Libft

> 42에서 필요한 라이브러리를 직접 구현하는 프로젝트입니다.

[라이브러리 만들기]()

man에 기반하여 각 함수들이 어떤 역할을 하는지 정리하였습니다.

## Contents

- [Libft](#libft)
  - [Contents](#contents)
  - [Part 1 - Libc functions](#part-1---libc-functions)
    - [ft_isalpha](#ft_isalpha)
    - [ft_isdigit](#ft_isdigit)
    - [ft_isalnum](#ft_isalnum)
    - [ft_isascii](#ft_isascii)
    - [ft_isprint](#ft_isprint)
    - [ft_toupper](#ft_toupper)
    - [ft_tolower](#ft_tolower)
    - [ft_strchr](#ft_strchr)
    - [ft_strrchr](#ft_strrchr)
    - [ft_strlen](#ft_strlen)
    - [ft_strncmp](#ft_strncmp)
    - [ft_strlcpy](#ft_strlcpy)
    - [ft_strlcat](#ft_strlcat)
    - [ft_strnstr](#ft_strnstr)
    - [ft_atoi](#ft_atoi)
    - [ft_memset](#ft_memset)
    - [ft_bzero](#ft_bzero)
    - [ft_memchr](#ft_memchr)
    - [ft_memcpy](#ft_memcpy)
    - [ft_memcmp](#ft_memcmp)
    - [ft_memmove](#ft_memmove)
    - [ft_calloc](#ft_calloc)
    - [ft_strdup](#ft_strdup)
  - [Part 2 - Additional functions](#part-2---additional-functions)
    - [ft_](#ft_)
  - [Question](#question)

## Part 1 - Libc functions

### ft_isalpha
> is alphabetic character 

**PROTOTYPE**
```c
int ft_isalpha(int c)
```

**DESCRIPTION**  
매개변수 `c`가 문자인지 확인합니다. (`A` == 65, `Z` == 90, `a` == 97, `z` == 122)

**RETURN VALUE**  
문자가 아닐 경우, 0을 반환합니다.  
문자가 맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
문자열을 다루는 함수인데 왜 int형 매개변수로 받나?

- [문자를 다루는 함수의 매개변수가 int형인 이유](#문자를-다루는-함수의-매개변수가-int형인-이유)

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isdigit
> is digit character 

**PROTOTYPE**
```c
int ft_isdigit(int c)
```

**DESCRIPTION**  
매개변수 `c`가 숫자인지 확인합니다. (`0` == 48, `9` == 57)

**RETURN VALUE**  
숫자가 아닐 경우, 0을 반환합니다.  
숫자가 맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
.
<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isalnum
> is alphanumeric character 

**PROTOTYPE**
```c
int ft_isalnum(int c)
```

**DESCRIPTION**  
매개변수 `c`가 알파벳 또는 숫자인지 확인합니다.

**RETURN VALUE**  
아닐 경우, 0을 반환합니다.  
맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isascii
> is ASCII character 

**PROTOTYPE**
```c
int ft_isascii(int c)
```

**DESCRIPTION**  
매개변수 `c`가 ASCII 문자인지 확인합니다. 
확장 아스키가 아닌, 0부터 127까지 문자를 확인한다.

**RETURN VALUE**  
아닐 경우, 0을 반환합니다.  
맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_isprint
> is printable character 

**PROTOTYPE**
```c
int ft_isprint(int c)
```

**DESCRIPTION**  
매개변수 `c`가 출력 가능한 문자인지 확인합니다. 
출력 가능한 문자는 `SP`(32)부터 `~`(126)까지 입니다.

**RETURN VALUE**  
아닐 경우, 0을 반환합니다.  
맞다면, 0이 아닌 int형을 반환합니다.

**ISSUES**  
`DEL`(127)은 delete control character로, 명령어에 해당합니다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_toupper
> to upper case character 

**PROTOTYPE**
```c
int ft_toupper(int c)
```

**DESCRIPTION**  
매개변수 `c`가 소문자라면 대문자로 바꿔줍니다.  
대문자와 소문자간의 차이는 `32`입니다

**RETURN VALUE**  
소문자는 대문자로 바꿔 반환합니다.
소문자가 아니라면 그대로 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------

### ft_tolower
> to lower case character 

**PROTOTYPE**
```c
int ft_tolower(int c)
```

**DESCRIPTION**  
매개변수 `c`가 대문자라면 소문자로 바꿔줍니다.

**RETURN VALUE**  
대문자는 소문자로 바꿔 반환합니다.
대문자가 아니라면 그대로 반환합니다.

**ISSUES**  
.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---------------------------------------------------
### ft_strchr
> string  character

**PROTOTYPE**
```c
char    *ft_strchr(const char *s, int c);
```

**DESCRIPTION**  
문자열 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다. c가 '\0'일 경우 종료 Null 문자를 찾습니다.

**RETURN VALUE**  
문자 `c`가 처음 발견된 곳의 포인터. 문자열 `s`에 문자 `c`가 없으면 Null 포인터를 반환합니다.

**ISSUES**  

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

### ft_strlen
> string length

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
-   [size_t형에 대하여](#size_t형)

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strncmp
> string n compare

**PROTOTYPE**
```c
int ft_strncmp(const char *s1, const char *s2, size_t n)
```

**DESCRIPTION**  
문자열 s1과 s2를 n만큼 비교합니다.

```.vim
"The comparison is done using unsigned characters, so that ‘\200’ is greater than ‘\0’."
```
8진수 '\200', 즉 10진수 128의 수가 '\0'보다 커야 한다는 말은 char가 아닌 unsigned char형으로 비교해야 한다는 말로 해석하였습니다. (char형 비교 시 128은 오버플로우 발생)

**RETURN VALUE**  
s1가 크면 양수를, s2가 크면 음수를, 같다면 0을 반환합니다.

**ISSUES**  
`const char`형으로 매개변수를 받는 이유
>   ft_strncmp 함수는 비교의 목적으로 쓰이므로 매개변수로 받는 문자열 s1, s2 값이 조작되면 안된다. 따라서 해당 매개변수들의 자료형을 const char형으로 받는다. 

그렇다면 비교를 위해 `unsigned char`형으로 casting 할 때, const unsigned char형이 되어야 할 것 같아 상수화를 유지시켰다.

<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strlcpy
> string length(?) copy

**PROTOTYPE**
```c
size_t  strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
```
> 해당 `restrict qualifier`는 `c99 standard` 키워드로, 해당 과제에서는 다루지 않습니다.

**DESCRIPTION**  
문자열 src에서 dst로 dstsize bytes 만큼 복사합니다. strncpy 함수에서는 n의 size가 src length보다 작을 경우 NULL이 보장되지 못한다는 단점이 있었습니다. 이를 보완한 함수로, 복사가 끝나면 문자열 끝에 NULL문자(\0)가 보장됩니다.

**RETURN VALUE**  
복사를 시도하려고 하는 길이인, src의 길이를 반환합니다.

**ISSUES**  


<div align = "right">
    <b><a href = "#Contents">↥ top</a></b>
</div>

---

### ft_strlcat
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

### ft_strnstr
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

### ft_atoi
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

### ft_memset
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

### ft_bzero
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

### ft_memchr
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

### ft_memcpy
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

### ft_memcmp
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

### ft_memmove
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

### ft_calloc
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

### ft_strdup
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

## Part 2 - Additional functions

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
