import os
import shutil
import re

srcDir = os.path.join(os.path.dirname(__file__), '..', 'src')
testDir = os.path.join(os.path.dirname(__file__), '..', 'tests')

if os.path.exists(testDir):
    shutil.rmtree(testDir)
os.mkdir(testDir)


def extract_structs_from_comments(c_code):
    # 正则表达式以匹配注释中的结构体定义
    pattern = r'/\*\*(.*?)\*/'
    struct_pattern = r'struct\s+\w+\s*\{[^}]*\};'
    structs = []

    # 在源码中查找所有匹配项
    matches = re.findall(pattern, c_code, re.DOTALL)

    # 提取结构体定义
    for match in matches:
        struct_matches = re.findall(struct_pattern, match, re.DOTALL)
        for struct in struct_matches:
            # 清除前导的星号和空格
            cleaned_struct = re.sub(r'^\s*\*', '', struct, flags=re.MULTILINE).strip()
            structs.append(cleaned_struct)

    return "\n".join(structs)


for filename in os.listdir(path=srcDir):
    if not filename.endswith(".c"):
        continue
    
    srcPath = os.path.join(srcDir, filename)

    name, ext = os.path.splitext(filename)
    destPath = os.path.join(testDir, f"{name}_test{ext}")

    with open(srcPath, 'r') as sf:
        content = sf.read()
        with open(destPath, 'w') as df:
            content = f"""
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/minunit.h"

#define bool int
#define true 1
#define false 0

{extract_structs_from_comments(content)}

{content}

int main(void) {{
   MU_RUN_SUITE(test_suite);
   MU_REPORT();
   return MU_EXIT_CODE; 
}}
            """
            df.write(content)

