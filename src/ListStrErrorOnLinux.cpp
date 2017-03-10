/*
 * ListStrErrorOnLinux.cpp
 *
 *  Created on: 2017/03/09
 *      Author: yoshiiyuuichi
 */

#include <cstring>

#include "FileEntityOnLinux.h"

void TestMethod01() {
    vector<string> messages;
    for (int i = 0; i < 256; i++) {
        errno = i;
        string item = "Number : " + to_string(i);
        item.append(" ");
        item.append(string(strerror(errno)));
        messages.push_back(item);
    }
    FileEntityOnLinux f;
    f.SetFullPath("/home/yoshiiyuuichi/box/TestMethod01.txt");
    f.WritePrepare(false);
    if (f.IsWritePrepared()) {
        f.SetFileLines(messages);
        f.WriteFile();
    }
}

int main(int argc, char * argv[]) {
    TestMethod01();
    return 0;
}
