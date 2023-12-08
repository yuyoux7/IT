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
