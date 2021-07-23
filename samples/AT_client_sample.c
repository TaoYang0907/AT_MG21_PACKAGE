/*
 * 程序清单：AT Client 发送命令并接收响应例程
 */

#include <rtthread.h>
#include <finsh.h>
#include <at_device_mg21.h>     /* AT 组件头文件 */

int at_client_test(int argc, char**argv)
{
    zclOnoffCmd_t *pjCmd = rt_malloc(sizeof(zclOnoffCmd_t));
    pjCmd -> nwkAddr = 0xBB0C;
    pjCmd -> endpoint = 0x01;
    pjCmd -> mode = 0;
    struct at_device *device = RT_NULL;

    device = at_device_get_by_name(AT_DEVICE_NAMETYPE_DEVICE, "mg0");
    if(device == RT_NULL)
    {
        rt_kprintf("can't find device\r\n");
        return -RT_ERROR;
    }

    at_device_control(device, AT_DEVICE_CTRL_ONOFF, (void *)pjCmd);

    return RT_EOK;
}

/* 输出 at_Client_send 函数到 msh 中 */
MSH_CMD_EXPORT(at_client_test, AT Client send commands to AT Server and get response data);

