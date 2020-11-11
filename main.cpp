#include <iostream>
#include <sstream>
#include <fstream>
#include <zconf.h>
#include <cstring>


using namespace std;


void parsing(char *file_src,char *fmc) {
    ifstream csv_file(file_src, std::fstream::binary);

    int line_n = 0;
    char line[256];

    while (true) {
        csv_file.getline(line, 256);
        string line_string = line;
        if (line_string.size() == 0) {
            printf("The end\n");
            break;
        }

        int sub = 0;
        size_t i = 0;
        std::size_t char_position = 0;
        string sub_string;
        while (true) {
            int flag = 0;
            char_position = line_string.find(fmc, i);

            if (char_position == -1) {
                char_position = line_string.find("\n", i);
                flag = 1;
            }

            int size = char_position - i;

//            printf("i:%d\n",i);
//            printf("char_position:%d\n",char_position);
            printf("size:%d\n",size);

            sub_string = line_string.substr(i, size);

            printf("%d.%d:%s\n", line_n, sub, sub_string.c_str());

            i = i + size + 1;
            sub++;

            if (flag) {
                break;
            }
        }
        line_n++;
    }
}

int main() {
    char *csv_src = "/home/zyx/workspace/csv_parsing_library/test.csv";
    parsing(csv_src,",");
    return 0;
}

