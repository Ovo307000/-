#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义全局RGB变量
int red, green, blue;

//定义设置颜色函数
void set_color()
{
    //使用ANSI码改变背景色，若是想要改变字体颜色可以使用\033[38;2;%d;%d;%dm
    printf("\033[48;2;%d;%d;%dm", red, green, blue);
}

//定义恢复默认值函数
void reset_color()
{
    printf("\033[0m");
}

int main()
{
    //设置随机数种子
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

    //设置是否进入随机模式
    int rand_color;

    printf("欢迎使用渐变条生成器，当前版本为V0.2\n\n");
    printf("有bug一定要及时反馈啊QAQ，GitHub地址：https://github.com/Ovo307000/-\n");
    printf("更新日志：");
    printf("V0.2：加入了自定义颜色系统\n");
    //更换了两个自定义函数的命名，现在所有变量遵循下划线命名法~~
    //删除了无用的windows.h头文件
    //使用while循环判断输入错误
    printf("使用随机生成请回复“1”\n");
    printf("使用自定义生成请回复“2”\n");

    scanf_s("%d", &rand_color);

    while (rand_color != 1 || rand_color != 2)
    {
        printf("输入错误！\n");

        printf("使用随机生成请回复“1”\n");
        printf("使用自定义生成请回复“2”\n");
        scanf_s("%d", &rand_color);
    }

    if (rand_color == 1)
    {

        printf("请输入想要生成的渐变条数量：");
        scanf_s("%d", &num);
        printf("请输入渐变条宽度：");
        scanf_s("%d", &width);
        printf("若饱和度大于250+可能会卡顿一会，因为比较难Roll > <\n");

        printf("请输入开始最低饱和度(输入0为默认，255为纯白)：");
        scanf_s("%d", &start_min_color);
        printf("请输入结束最低饱和度(输入0为默认，255为纯白)：");
        scanf_s("%d", &end_min_color);

        while (start_min_color > 255 || end_min_color > 255)
        {
            printf("最大饱和度为255，请重新输入！\n");

            printf("请输入开始最低饱和度(输入0为默认，255为纯白)：");
            scanf_s("%d", &start_min_color);
            printf("请输入结束最低饱和度(输入0为默认，255为纯白)：");
            scanf_s("%d", &end_min_color);
        }

        //循环生成渐变条
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
                set_color();
                putchar(' ');
                reset_color();
            }
            //换行，避免两个渐变条连在一起
            putchar('\n');
        }
        //结束换行，避免和结束语句粘一起
        putchar('\n');
        return 0;
    }
    else if (rand_color == 2)
    {
        {
            printf("请输入起始红色的值（0-255）：");
            scanf_s("%d", &start_red);
            printf("请输入起始绿色的值（0-255）：");
            scanf_s("%d", &start_green);
            printf("请输入起始蓝色的值（0-255）：");
            scanf_s("%d", &start_blue);

            putchar('\n');

            printf("请输入终点红色的值（0-255）：");
            scanf_s("%d", &end_red);
            printf("请输入终点绿色的值（0-255）：");
            scanf_s("%d", &end_green);
            printf("请输入终点蓝色的值（0-255）：");
            scanf_s("%d", &end_blue);
        }

        putchar('\n');

        printf("请输入想要生成的渐变条数量：");
        scanf_s("%d", &num);
        printf("请输入渐变条宽度：");
        scanf_s("%d", &width);

        printf("若饱和度大于250+可能会卡顿一会，因为比较难Roll > <\n");

        printf("请输入开始最低饱和度(输入0为默认，255为纯白)：");
        scanf_s("%d", &start_min_color);
        printf("请输入结束最低饱和度(输入0为默认，255为纯白)：");
        scanf_s("%d", &end_min_color);

        while (start_min_color > 255 || end_min_color > 255)
        {
            printf("最大饱和度为255，请重新输入！\n");

            printf("请输入开始最低饱和度(输入0为默认，255为纯白)：");
            scanf_s("%d", &start_min_color);
            printf("请输入结束最低饱和度(输入0为默认，255为纯白)：");
            scanf_s("%d", &end_min_color);
        }

            //循环生成渐变条
            for (int i = 0; i < num; i++)
            {
                for (int w = 0; w < width; w++)
                {
                    //*计算各颜色在字符中的占比
                    red = start_red + (end_red - start_red) * w / width;
                    green = start_green + (end_green - start_green) * w / width;
                    blue = start_blue + (end_blue - start_blue) * w / width;
                    set_color();
                    putchar(' ');
                    reset_color();
                }
            }
        
    }  
    putchar('\n');
    return 0;
 }

 //有bug一定要及时反馈啊QAQ，GitHub地址：https://github.com/Ovo307000/-
