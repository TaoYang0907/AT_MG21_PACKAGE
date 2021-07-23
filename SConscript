from building import *

cwd = GetCurrentDir()
path = [cwd + '/inc']
src  = Glob('src/*.c')

# MG21
if GetDepend(['PKG_USING_AT_MG21']):
    path += [cwd + '/class/mg21']
    src += Glob('class/mg21/at_device_mg21.c')
    if GetDepend(['AT_DEVICE_ESP8266_SAMPLE']):
        src += Glob('samples/at_sample_mg21.c')
		src += Glob('samples/AT_client_sample.c')
		

group = DefineGroup('at_mg21', src, depend = ['PKG_USING_AT_MG21'], CPPPATH = path)

Return('group')
