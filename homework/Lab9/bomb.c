/***************************************************************************
 * 邪恶博士的阴险炸弹，第 1.1 版
 * 版权所有 © 2011，Dr. Evil Incorporated（邪恶博士公司）。保留所有权利。
 *
 * 许可条款
 *
 * 邪恶博士公司（以下简称“设局者”）在此明确许可你（以下简称“受害者”）
 * 使用这枚炸弹（以下简称“炸弹”）。本许可有时限，受害者离世时即告到期。
 * 若受害者遭受损失、挫败、精神失常、双眼暴突、腕管综合征、失眠或其他伤害，
 * 设局者概不负责。当然，设局者想把这些算作自己功劳的时候除外。
 * 受害者不得将炸弹源码分发给设局者的任何敌人。受害者不得调试、逆向分析、
 * 对炸弹运行 strings、反编译、解密，或以任何其他手段探明并拆解炸弹。
 * 操作本程序时不得穿防爆服。设局者不会为自己糟糕的幽默感道歉。
 * 凡法律禁止使用本炸弹之处，本许可无效。
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

/*
 * 给自己提个醒：记得删掉这份文件，免得受害者看懂我的把戏。
 * 这样他们就会在一场壮观又邪恶的爆炸里全军覆没。——邪恶博士
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* 给自己提个醒：记得把炸弹移植到 Windows，再给它配个气派的图形界面。 */

    /* 启动时没有附加参数，就从标准输入逐行读取。 */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* 启动时若给出一个文件名，就先从该文件逐行读取，读到文件末尾后改从标准输入读取。
     * 这样，每通过一个阶段，就可以把该阶段的答案追加到文件里，下次运行时省得重输。 */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* 程序名后面最多只能给一个命令行参数。 */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* 做些秘密的初始化工作，让这枚炸弹更难拆。 */
    initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");

    /* 嗯……六个阶段总该比一个阶段更保险吧！ */
    input = read_line();             /* 读入一行。 */
    phase_1(input);                  /* 用这一行输入运行第一阶段。 */
    phase_defused();                 /* 可恶！他们解开了！快告诉我他们是怎么做到的。 */
    printf("Phase 1 defused. How about the next one?\n");

    /* 第二阶段更难。这回谁也猜不出该怎么拆了吧…… */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("That's number 2.  Keep going!\n");

    /* 看来前面还是太容易了。来点更复杂的代码，把他们绕晕。 */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Halfway there!\n");

    /* 哦？那你的数学怎么样？来试试这道够呛的题！ */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("So you got that one.  Try this one.\n");
    
    /* 在内存里转呀转，转到哪儿停，炸弹就在哪儿响！ */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Good work!  On to the next...\n");

    /* 反正谁也过不了前面几关，这一关用不上。不过以防万一，还是再出难点。 */
    input = read_line();
    phase_6(input);
    phase_defused();

    /* 哇，他们竟然解开了！可是不是还少了点什么……他们漏掉了什么呢？哇哈哈哈！ */
    
    return 0;
}
