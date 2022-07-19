# Get Next Line

> 파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 구현하는 프로젝트 입니다.

`open()` 함수를 통해 `fd`을 얻어 `read()` 함수를 통해 파일을 읽을 수 있습니다. 해당 프로젝트의 `GNL()` 함수는 파일을 개행까지 한줄 읽어오는 함수 입니다. 개행없이 파일이 끝나는 경우엔 파일 끝까지 읽어옵니다. `GNL()` 함수의 일반적 사용은 다음과 같습니다.

```.c
char *line = 0;

if (!(fd = open("file_name", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);
```

-----

## Contents

- [Get Next Line](#Get-Next-Line)
  - [Contents](#contents)
	- [Key Word](#Key-Word)
	- [Logic](#Logic)
	- [ft_strlen](#ft_strlen)

-----

## Key Word

### 📌 read()
> #include <unistd.h>


<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

### 📌 FD
> file descriptor


<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

### 📌 Buffer
>


<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

### 📌 Static 변수
> 정적 변수

<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

### 📌 Dangling Pointer
> 댕글링 포인터

<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

### 📌 gcc -D
>

------
### 📌 Redirection
>

<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

### ft_strlen
> string length

<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

------

[sample]

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
-   [size_t형에 대하여](#size_t형에-대하여)

<div align = "right">
	<b><a href = "#Contents">↥ top</a></b>
</div>

--------------------------------------------------
