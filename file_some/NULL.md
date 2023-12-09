# NULL
**
#### WINDOWS_SET_SIZE();
```bash
void WINDOWS_SET_SIZE(const int WINDOWS_SIZE_X, const int WINDOWS_SIZE_Y, LPCWSTR WINDOWS_NAME, HINSTANCE hInstance = NULL, HINSTANCE hPrevInstance = NULL, PWSTR pCmdLine = NULL, int nCmdShow = NULL, int flog = 1);
//簡易的Window視窗建置
```
#### 使用演示
```bash
#include "default.h"
often_use user;
int main(void)
{
   user.WINDOWS_SET_SIZE(1920, 1080, L"[TEXT]");
}
```
**
