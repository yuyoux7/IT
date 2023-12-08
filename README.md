# 關於倉庫
一個代碼存放區
每個代碼的使用方式皆在對應的資料夾中
### 關於default.h
一個C++的懶人開頭檔
### 如何使用default.h
將它下載放置與您的專項同一個資料夾中
在您的檔案中加入`#include "default.h"`
即可輕鬆使用
### defailt.h調用演示
```bash
#include "default.h"
often_use user;
int main(void)
{
   user.WORLD_BG_RGB_SET_CMD(RED);
   cout << user.GET_RAND();
}
```
### default.h功能說明
GET_RAND();
```bash
int GET_RAND(int __Bailiwick__ = 0);
//得到一個由0開始向上的隨機的數值
//Bailiwick可以限定上限值
```
WORLD_BG_RGB_SET_CMD();
```bash
void WORLD_BG_RGB_SET_CMD(int __Forg_Color__ = REST_FORG_COLOR, int __Back_Color__ = REST_BACK_COLOR);
//設定文字及文字背景的顏色
//不傳入參數視為重置顏色
//傳入值應為0~15之間的整數
//有預定義的顏色可直接使用
//#define WHITE 0x0F
//#define YELLOW 0x0E
//#define RED 0x0C
//#define GREED 0x0A
//#define BLUE 0x09
//#define BLACK 0x00
//僅限於在編譯終端時使用
```
MOVE_GOTO_SET_CMD();
```bash
void MOVE_GOTO_SET_CMD(int __x__, int __y__);
//將終端的光標移動至設定的位置
//僅限於在編譯終端時使用
```
```bash
WINDOWS_SET_SIZE();
void WINDOWS_SET_SIZE(const int WINDOWS_SIZE_X, const int WINDOWS_SIZE_Y, LPCWSTR WINDOWS_NAME, HINSTANCE hInstance = NULL, HINSTANCE hPrevInstance = NULL, PWSTR pCmdLine = NULL, int nCmdShow = NULL, int flog = 1);
//簡易的Window視窗建置
```
使用演示
```bash
#include "default.h"
often_use user;
int main(void)
{
   user.WINDOWS_SET_SIZE(1920, 1080, L"[TEXT]");
}
```