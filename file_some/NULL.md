# NULL
#### WINDOWS_SET_SIZE();
```C++
void WINDOWS_SET_SIZE(const int WINDOWS_SIZE_X, const int WINDOWS_SIZE_Y, LPCWSTR WINDOWS_NAME, HINSTANCE hInstance = NULL, HINSTANCE hPrevInstance = NULL, PWSTR pCmdLine = NULL, int nCmdShow = 1);
//簡易的Window視窗建置
```
#### 使用演示
```C++
#include "default.h"
often_use user;
int main(void)
{
   user.WINDOWS_SET_SIZE(1920, 1080, L"[TEXT]");
}
```
#### WINDOWS_TEXT();
```C++
void WINDOWS_TEXT(LPCWSTR lpString, int WINDOWS_SIZE_X, int WINDOWS_SIZE_Y);
//簡易的Window視窗文字顯示
```
#### 使用演示
```C++
#include "default.h"
often_use user;
int main(void)
{
   user.WINDOWS_SET_SIZE(1920, 1080, L"[TEXT]");
   user.WINDOWS_SET_SIZE(10, 10, L"Hello World!");
}
```
