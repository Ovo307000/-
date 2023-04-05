#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//定义全局RGB变量
int red, green, blue;

//定义设置颜色函数
void setColor() 
{
    //使用ANSI码改变背景色，若是想要改变字体颜色可以使用\033[38;2;%d;%d;%dm
    printf("\033[48;2;%d;%d;%dm", red, green, blue);
}

//定义恢复默认值函数
void resetColor() 
{
    printf("\033[0m");
}

int main() 
{
    srand(time(NULL)); 
    //定义宽度变量
    int width;
    //定义最小饱和度变量
    int start_min_color, end_min_color;
    //定义开始和结束点的颜色
    int start_red, start_green, start_blue;
    int end_red, end_green, end_blue;
    //设置渐变条数量
    int num;

    //获取用户输入的宽，最低饱和度
    printf("欢迎使用渐变条生成器，当前版本为V0.1\n");
    printf("请输入想要生成的渐变条数量：");
    scanf_s("%d", &num);
    printf("请输入渐变条宽度：");
    scanf_s("%d", &width);
    printf("若饱和度大于250+可能会卡顿一会，因为比较难Roll > <\n");
    set_color:
    printf("请输入开始最低饱和度(输入0为默认，255为纯白)：");
    scanf_s("%d", &start_min_color);
    printf("请输入结束最低饱和度(输入0为默认，255为纯白)：");
    scanf_s("%d", &end_min_color);
    if (start_min_color > 255 || end_min_color > 255)
    {
        printf("最大饱和度为255，请重新输入！\n");
        goto set_color;
    }

    //循环遍历每一个字符
    for (int i = 0; i < num; i++)
    {
        // 随机生成开始和结束颜色，并且确保生成的最小值大于输入的最小值
        {
            do
            {
                start_red = rand() % 256;
                start_green = rand() % 256;
                start_blue = rand() % 256;
            } while (start_red <= start_min_color || start_green <= start_min_color || start_blue <= start_min_color);

            do
            {
                end_red = rand() % 256;
                end_green = rand() % 256;
                end_blue = rand() % 256;
            } while (end_red <= end_min_color || end_green <= end_min_color || end_blue <= end_min_color);
        }
        putchar('\n');
        for (int w = 0; w < width; w++)
        {
            //*计算各颜色在字符中的占比
            red = start_red + (end_red - start_red) * w / width;
            green = start_green + (end_green - start_green) * w / width;
            blue = start_blue + (end_blue - start_blue) * w / width;
            setColor();
            putchar(' ');
            resetColor();

        }
        //换行，避免两个渐变条连在一起
        putchar('\n');
    }
    //结束换行，避免和结束语句粘一起
    putchar('\n');
    return 0;
}
