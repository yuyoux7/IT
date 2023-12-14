#include "Windows.h"
#include <iostream>
Windows::Windows(int x, int y, int flog)
{
   Window_size = ::initgraph(x, y, flog);
}

int Windows::Window_exit()
{
    return getchar();
}

void Windows::Title(const std::string& title)
{
    ::SetWindowText(Window_size, title.c_str());
}