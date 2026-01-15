## V1 双层原始实现
```C
void rotate_k_1(char* arr, int k) {
	int i, j;
	char tmp;
	int len = strlen(arr);
	for (i = 0; i < k; i++) {
		tmp = arr[0];
		for (j = 0; j < len - 1; j++) {
			arr[j] = arr[j+1];
		}
		arr[len-1] = tmp;
	}
}
```
这是最基本的实现，每次都左旋一个字符，重复k次。
## V2 memmove的使用
```C
void rotate_k_1(char* arr, int k) {
	int i, j;
	char tmp;
	int len = strlen(arr);
	k%=len;
	for (i = 0; i < k; i++) {
		tmp = arr[0];
		memmove(arr, arr+1, len-1);
		arr[len-1] = tmp;
	}
}
```
- 利用`k%=len`减少了很多不必要的移动
- 利用库函数`memmove`（有内存重叠部分移动需求），加快了运行速度
## V3 三次逆序法
三次逆序法的实现需要我们额外写一个`reverse()`函数。
### 样例
 1.`abcdef` 左旋2个字符
 - 左区：ab
 - 右区：cdef
2.将他们分别逆序
- 左区：ba
- 右区：fedc
3.将他们合并后整体再逆序
- 合并：bafedc
- 逆序：cdefab
就得到了我们想要的结果了！
### 代码
#### Reverse()函数
```C
void reverse(char* left, char* right) {
	assert(left && right);
	char tmp;
	while (left < right) {
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
```
#### Rotate_k_2()函数
```C
void rotate_k_2(char* arr, int k) {
    if (!arr) return;
	int len = strlen(arr);
	if (len == 0) return;
	k%=len;
	reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
}
```
